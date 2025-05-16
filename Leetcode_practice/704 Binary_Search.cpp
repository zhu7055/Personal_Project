class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                
                if (nums[mid] == target) {//相等
                    return mid;
                } else if (nums[mid] < target) {//在右側
                    left = mid + 1;
                } else {//在左側
                    right = mid - 1;
                }
            }
            
            return -1;//沒找到
        }
    };