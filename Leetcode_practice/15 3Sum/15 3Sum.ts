function threeSum(nums: number[]): number[][] {
    // 步驟 1: 排序陣列
    // 首先對輸入的數字陣列 nums 進行升序排序。
    // 排序是使用雙指針方法的關鍵，它能幫助我們有效率地移動指針並處理重複的數字。
    nums.sort((a, b) => a - b);

    // 取得陣列的長度
    let length: number = nums.length;

    // 初始化結果陣列，用於儲存所有符合條件的三元組
    let resArr: number[][] = [];

    // 步驟 2: 遍歷陣列
    // 我們要找到 nums[i] + nums[left] + nums[right] = 0 的組合。
    // 這個迴圈會固定 nums[i]，然後利用雙指針 left 和 right 在其餘部分尋找。
    for (let i = 0; i < length; i++) {
        // 優化 1: 如果 nums[i] 大於 0，則可以提前終止
        // 因為陣列已經排序，如果 nums[i] 已經是正數，
        // 那麼後面的 nums[left] 和 nums[right]（即使是負數）與 nums[i] 相加，總和也一定會大於 0。
        // 因此，不可能找到和為 0 的三元組，可以直接返回目前結果。
        if (nums[i] > 0) {
            return resArr;
        }

        // 優化 2: 跳過重複的 nums[i]
        // 為了避免結果中出現重複的三元組，如果當前的 nums[i] 與前一個 nums[i-1] 相同，
        // 就跳過本次循環，因為我們已經處理過以 nums[i-1] 開頭的所有可能組合了。
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }

        // 初始化雙指針
        // `left` 指針從 `i + 1` 開始 (確保不與 nums[i] 重複，並向右移動)
        // `right` 指針從陣列的末尾開始 (向左移動)
        let left: number = i + 1;
        let right: number = length - 1;

        // 步驟 3: 雙指針搜尋
        // 當 `left` 指針小於 `right` 指針時，繼續搜尋。
        while (left < right) {
            // 計算當前三數之和
            let total: number = nums[i] + nums[left] + nums[right];

            // 根據總和的值調整指針
            if (total === 0) {
                // 如果總和為 0，表示找到了一個有效的三元組
                resArr.push([nums[i], nums[left], nums[right]]);

                // 移動指針
                // 將 `left` 指針向右移動一位
                left++;
                // 將 `right` 指針向左移動一位
                right--;

                // 優化 3: 跳過重複的 nums[right] 和 nums[left]
                // 在找到一個有效的三元組後，為避免結果中出現重複的三元組，
                // 如果 `nums[right]` 與新的 `nums[right+1]` 相同，則繼續將 `right` 向左移動，直到遇到不同的數字。
                while (left < right && nums[right] === nums[right + 1]) {
                    right--;
                }
                // 同理，如果 `nums[left]` 與新的 `nums[left-1]` 相同，則繼續將 `left` 向右移動，直到遇到不同的數字。
                while (left < right && nums[left] === nums[left - 1]) {
                    left++;
                }
            } else if (total < 0) {
                // 如果總和小於 0，表示當前三數之和太小，需要增大。
                // 由於陣列已排序，我們將 `left` 指針向右移動，以取得更大的數字。
                left++;
            } else { // total > 0
                // 如果總和大於 0，表示當前三數之和太大，需要減小。
                // 由於陣列已排序，我們將 `right` 指針向左移動，以取得更小的數字。
                right--;
            }
        }
    }
    // 返回所有找到的，不重複的，和為 0 的三元組
    return resArr;
}