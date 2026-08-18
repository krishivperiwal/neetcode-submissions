class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int i = 0;
    int kf = 0;
    KthLargest(int k, vector<int>& nums) {
        for(; i < nums.size() && i < k; i++){
            pq.push(nums[i]);
        }
        while(i < nums.size()){
            if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }
        kf = k;
    }
    
    int add(int val) {
        if(pq.size() < kf){
            pq.push(val);
        }else if(pq.top() < val){
            pq.pop();
            pq.push(val);
        }
        i++;
        return pq.top();
    }
};
