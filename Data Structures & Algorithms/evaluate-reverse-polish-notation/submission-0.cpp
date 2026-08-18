class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == "+"||s[i] == "-"||s[i] == "*"||s[i] == "/"){
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                if(s[i] == "+"){
                    st.push(left+right);
                }
                else if(s[i] == "-"){
                    st.push(left-right);
                }
                else if(s[i] == "*"){
                    st.push(left*right);
                }
                else{
                    st.push(left/right);
                }
            }else{
                st.push(stoi(s[i]));
            }
        }
        return st.top();
    }
};
