class Solution {
public:
    string longestPalindrome(string s) {
        int len = 0;
        string ans = s.substr(0,1);
        int n = s.size();
        if(n <= 1)return s;

        for(int i = 0; i < n; i++){
            int l = i - 1;
            int r = i + 1;
            while( l >= 0 && r < n && s[l] == s[r]){
                if(r-l + 1 > len){
                    len = r - l + 1;
                    ans = s.substr(l,r-l+1);
                }
                    r++;
                    l--;
            }
        }
        for(int i = 0; i < n; i++){
            int l = i;
            int r = i + 1;
            while( l >= 0 && r < n && s[l] == s[r]){
                if(r-l + 1 > len){
                    len = r - l + 1;
                    ans = s.substr(l,r-l+1);
                }
                    r++;
                    l--;
            }
        }
        return ans;
    }
};
