class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(int i = 0; i < tasks.size(); i++){
            freq[tasks[i]-'A']++;
        }
        priority_queue<int> pq;
        for(auto it:freq){
            if(it){pq.push(it);}
        }
        int time = 0;
        while(!pq.empty()){
            int cycle = 0;
            vector<int> rem;
            while(cycle < n + 1 && !pq.empty()){
                int left = pq.top() - 1;
                pq.pop();
                cycle++;
                time++;
                if(left > 0)rem.push_back(left);
            }
            for(auto it:rem){
                pq.push(it);
            }
            if(!pq.empty()){time += n+1 - cycle;}
        }
        return time;
    }
};
