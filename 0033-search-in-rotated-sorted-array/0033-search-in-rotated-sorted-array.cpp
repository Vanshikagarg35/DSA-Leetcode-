class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid]>nums[r]) l = mid+1;
            else if(nums[mid]<=nums[r]) r= mid;
        }
        if(nums[r]== target ) return r;
        int pivot = r-1;
        l = 0;
        while(l<=pivot){
            int mid = l + (pivot-l)/2;
            if(target == nums[mid]) return mid;
            else if(target < nums[mid]) pivot = mid-1;
            else if(target > nums[mid]) l = mid+1;
        }
        pivot = r+1;
        r = nums.size()-1;
        while(pivot <= r){
            int mid = pivot + (r - pivot)/2;
            if(target == nums[mid]) return mid;
            else if(target < nums[mid]) r = mid-1;
            else if(target > nums[mid]) pivot = mid+1;
        }
        return -1;
    }
};