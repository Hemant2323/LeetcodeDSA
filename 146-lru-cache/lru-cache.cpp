class LRUCache {
public:

    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void removeNode(Node* node) {
        Node* before = node->prev;
        Node* after = node->next;

        before->next = after;
        after->prev = before;
    }

    void addFront(Node* node) {
        Node* after = head->next;

        head->next = node;
        node->prev = head;

        node->next = after;
        after->prev = node;
    }

    int get(int key) {

        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        removeNode(node);
        addFront(node);

        return node->val;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];
            node->val = value;

            removeNode(node);
            addFront(node);

            return;
        }

        // Cache is full
        if (mp.size() == cap) {

            Node* lru = tail->prev;

            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* node = new Node(key, value);

        addFront(node);
        mp[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */