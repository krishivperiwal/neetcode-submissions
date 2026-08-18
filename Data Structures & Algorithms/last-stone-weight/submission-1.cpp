class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){
            int st1 = pq.top();
            pq.pop();
            int st2 = pq.top();
            pq.pop();
            if(st1 == st2)continue;
            pq.push(abs(st2-st1));
        }

        return pq.size() ? pq.top():0;
    }
};
