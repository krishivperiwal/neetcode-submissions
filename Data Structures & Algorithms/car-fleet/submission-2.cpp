class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        stack<double> st;
        vector<pair<int,int>> pos;
        for(int i = 0; i < position.size(); i++){
            pos.push_back({position[i],speed[i]});
        }
        sort(pos.begin(),pos.end(),greater<pair<int,int>>());
        for(auto it:pos){
            auto [pos,sp] = it;
            double time = (double)(target - pos)/sp;
            if(st.empty()||time > st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};
