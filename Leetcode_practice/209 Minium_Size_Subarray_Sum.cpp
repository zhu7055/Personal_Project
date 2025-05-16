#include <vector>
#include <cstdint>
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; // 滑動窗口數字之和
        int i = 0; // 滑動窗口起始位置
        int subLength = 0; // 滑動窗口的長度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意這裡使用while，每次更新 i（起始位置），並不斷比較序列是否符合條件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列的長度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 這裡出現滑動窗口的精隨之處，不斷變更i（子序列的起始位置）
            }
        }
        // 如果result沒有被賦值的話，就返回0，說明沒有符合條件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};