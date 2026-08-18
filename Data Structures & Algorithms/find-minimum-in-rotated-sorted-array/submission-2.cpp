class Solution {
public:
    int findMin(vector<int> &nums) {
        int s = 0;
        int n = nums.size();
        int e = n - 1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(mid > 0 && nums[mid] < nums[mid - 1])return nums[mid];
            else if(nums[0] <= nums[mid] && nums[n-1] < nums[mid]){s = mid + 1;}
            else{e = mid - 1;}
        }
        return nums[0];
    }
};
