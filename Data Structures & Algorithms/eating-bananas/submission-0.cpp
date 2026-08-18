class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = 0;
        for(int i = 0; i < piles.size();i++){
            e = max(e,piles[i]);
        }
        int ans = 0;
        while(s <= e){
            int mid = s + (e-s)/2;
            long long time = can_finish(mid,piles);
            if(time > h)s = mid + 1;
            else{
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }

    long long can_finish(int rate,vector<int>& piles){
        long long time = 0;
        for(int i = 0; i < piles.size();i++){
            time += (piles[i] + rate - 1)/rate;
        }
        return time;
    }
};
