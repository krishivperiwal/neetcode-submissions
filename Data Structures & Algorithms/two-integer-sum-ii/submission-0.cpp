class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int st = 0;
        int e = numbers.size() - 1;

        while(st < e){
            if(numbers[st] + numbers[e] == target)return{st+1,e+1};
            else if(numbers[st] + numbers[e] > target)e--;
            else{st++;}
        }

        return{};
    }
};
