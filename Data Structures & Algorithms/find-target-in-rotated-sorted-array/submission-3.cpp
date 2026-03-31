class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)>>1;
            cout << mid;
            if(nums[mid]==target)return mid;
            if(target==nums[l])return l;
            if(target==nums[r])return r;
            if((nums[mid]>target&&target>nums[l])||
            (nums[mid]<=nums[l]&&nums[l]<target)||
            (target<nums[mid]&&nums[mid]<nums[l]))r=mid-1;
            if((nums[mid]>=nums[l]&&nums[l]>target)||
            (nums[mid]<target&&nums[l]>target)||
            (nums[l]<nums[mid]&&nums[mid]<target))l=mid+1;
        }return -1;
    }
};
