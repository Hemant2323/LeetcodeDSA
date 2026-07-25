class Solution {
public:
    int f(vector<int> arr) {
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                left[i] = -1;
            } else {
                left[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                right[i] = n;
            } else {
                right[i] = st.top();
            }
            st.push(i);
        }

        int maxx = -1e9;
        int area;
        for (int i = 0; i < n; i++) {
            area = arr[i] * (right[i] - left[i] - 1);
            maxx = max(maxx, area);
        }

        return maxx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea=0;
        vector<int> heights(n,0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                   heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
             maxArea = max(maxArea, f(heights));
        }

        return maxArea;
    }
};