class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int n = nums.size();
        int e = n - 1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target)return mid;
            else if(nums[mid] >= nums[0]){
                if(nums[mid] > target && nums[0] <= target){
                    e = mid - 1;
                }else{
                    s = mid + 1;
                }
            }else{
                if(nums[mid] < target && nums[n-1] >= target){
                    s = mid + 1;
                }else{
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};
