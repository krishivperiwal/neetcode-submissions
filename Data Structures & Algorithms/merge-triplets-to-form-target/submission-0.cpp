class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> temp = {-1,-1,-1};
        for(int i = 0; i < triplets.size(); i++){
            bool take = true;
            for(int j = 0; j < 3; j++){
                if(triplets[i][j] > target[j]){
                    take= false;
                    break;
                }
            }
            if(take){
                for(int j = 0; j < 3; j++){
                    temp[j] = max(temp[j],triplets[i][j]);
                }
            }
        }
        return temp == target;
    }
};
