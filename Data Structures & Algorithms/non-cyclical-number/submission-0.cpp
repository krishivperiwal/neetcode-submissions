class Solution {
public:
    bool isHappy(int n) {
        int fast = n;
        int slow = n;

        do{
            slow = cycle(slow);
            fast = cycle(cycle(fast));
            if(slow == 1 || fast == 1)return true;

        }while(slow != fast);
        return false;
    }

    int cycle(int n){
        int ans = 0;
        while(n > 0){
            int dig = n%10;
            ans += dig*dig;
            n /= 10;
        }
        return ans;
    }
};
