class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定義一個二維數組
        int startx = 0, starty = 0; // 定義每循環一個圈的起始位置
        int loop = n / 2; // 每個圈循環幾次，例如n為奇數3，那麼loop = 1 只是循環一圈，矩陣中間的值需要單獨處理
        int mid = n / 2; // 矩陣中間的位置，例如：n為3， 中間的位置就是(1，1)，n為5，中間位置為(2, 2)
        int count = 1; // 用來給矩陣中每一個空格賦值
        int offset = 1; // 需要控制每一條邊遍歷的長度，每次循環右邊收縮一個長度
        int i,j;
        while (loop --) {
            i = startx;
            j = starty;

            // 下面開始的四個for就是模擬轉了一圈
            // 模擬填充上行從左到右(左閉右開)
            for (j; j < n - offset; j++) {
                res[i][j] = count++;
            }
            // 模擬填充右列從上到下(左閉右開)
            for (i; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // 模擬填充下行從右到左(左閉右開)
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // 模擬填充左列從下到上(左閉右開)
            for (; i > startx; i--) {
                res[i][j] = count++;
            }

            // 第二圈開始的時候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;

            // offset 控制每一圈裡每一條邊遍歷的長度
            offset += 1;
        }

        // 如果n為奇數的話，需要單獨給矩陣最中間的位置賦值
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};