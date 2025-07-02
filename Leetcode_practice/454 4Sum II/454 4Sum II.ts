function fourSumCount(nums1: number[], nums2: number[], nums3: number[], nums4: number[]): number {
    // 創建一個 Map 來儲存 nums1 和 nums2 中所有可能的和，以及它們出現的次數。
    let helperMap: Map<number, number> = new Map();
    // 初始化結果變數，用於計數滿足條件的四元組數量。
    let resNum: number = 0;
    // 宣告一個臨時變數，用於儲存從 Map 中取出的值。
    let tempVal: number | undefined;

    // 遍歷 nums1 和 nums2，計算所有可能的和。
    for (let i of nums1) {
        for (let j of nums2) {
            // 取得當前和 (i + j) 在 helperMap 中已存在的計數。
            tempVal = helperMap.get(i + j);
            // 將當前和 (i + j) 存入 helperMap，如果已存在則計數加一，否則初始化為一。
            helperMap.set(i + j, tempVal ? tempVal + 1 : 1);
        }
    }

    // 遍歷 nums3 和 nums4，尋找與之前計算的和互補的值。
    for (let k of nums3) {
        for (let l of nums4) {
            // 計算目標值：0 減去 (k + l)。如果 helperMap 中存在這個目標值，就表示找到了四元組的和為 0。
            tempVal = helperMap.get(0 - (k + l));
            // 如果找到了互補的值 (即 tempVal 存在且不為 undefined)。
            if (tempVal) {
                // 將該互補值出現的次數加到結果變數 resNum 中。
                resNum += tempVal;
            }
        }
    }

    // 返回滿足條件的四元組數量。
    return resNum;
};