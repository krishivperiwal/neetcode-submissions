class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0)return false;
        map<int,int> mp;
        int mini = 1e8;
        for(int i = 0; i < n; i++){
            mp[hand[i]]++;
            mini = min(mini,hand[i]);
        }

        for(int g = 0; g < n/groupSize; g++){
            for(int i = 0; i < groupSize; i++){
                int num = mini + i;
                if(mp.contains(num)){
                    mp[num]--;
                    if(!mp[num])mp.erase(num);
                }else{
                    return false;
                }
            }
            mini = mp.begin()->first;
        }
        return true;
    }
};
