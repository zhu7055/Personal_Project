function fourSumCount(nums1:number[],nums2:number[],nums3:number[],nums4:number[]):number{
// 創建一個Map來存儲nums1和nums2中所有可能和的頻率
// key是和，值是該和出現的次數
    let helperMap:Map<number,number>=new Map();
    // 初始化結果計數器
    let resNum:number=0;
    // 用於暫存從helperMap中取出的值
    let tempVal: number | undefined;
     // 遍歷nums1和nums2，計算所有可能的兩數之和
    for(let i of nums1){
        for(let j of nums2){
            tempVal =helperMap.get(i+j);  // 計算當前兩數之和
            helperMap.set(i + j,tempVal ? 1 : 1); // 如果tempVal存在（表示之前已經遇到過這個和），則在原有基礎上加1；
            // 如果tempVal不存在，則設置為1
        }
    }
    // 遍歷nums3和nums4，尋找與之前計算的和互補的組合
    for(let k of nums3){
        for(let l of nums4){
        // 計算當前兩數之和的負數，因為我們需要 (i+j) + (k+l) = 0
            // 所以 (k+l) 必須等於 -(i+j)
            tempVal=helperMap.get(0-(k+1));
            if(tempVal){ //如果找到了
                resNum+=tempVal;// 因為每一個 'tempVal' 都代表了之前 nums1 和 nums2 中一組可以與當前 (k+l) 配對的和
            }
        }
    }
    return resNum; //返回統計的值
};