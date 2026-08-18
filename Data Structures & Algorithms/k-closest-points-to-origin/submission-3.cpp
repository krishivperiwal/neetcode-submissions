class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-heap to store pairs of {squared_distance, index}
        priority_queue<pair<int, int>> maxHeap;

        for (int i = 0; i < points.size(); ++i) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y; // Avoid sqrt for performance and precision

            maxHeap.push({dist, i});

            // If heap size exceeds k, remove the farthest point
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            int idx = maxHeap.top().second;
            ans.push_back(points[idx]);
            maxHeap.pop();
        }

        return ans;
    }
};