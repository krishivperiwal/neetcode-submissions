class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int index = n-1;
        int carry = 0; 
        do{
            int sum = digits[index] + 1;
            carry = sum/10;
            digits[index--] = sum%10;
        }while(carry != 0 && index>=0);
        if(carry){
            reverse(digits.begin(),digits.end());
            digits.push_back(1);
            reverse(digits.begin(),digits.end());
        }
        return digits;
    }
};
