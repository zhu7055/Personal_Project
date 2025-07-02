import java.util.Map;

class Solution {
public int[] twoSum(int[] nums,int target){
    Map<Integer,Integer> indexMap=new HashMap<>();
    
    for(int i=0;i<nums.length;i++){
        int s=target-nums[i];//紀錄要查詢的值，尋找s
        if(indexMap.containsKey(s)){//如果在Map中出現過
            return new int[]{i,indexMap.get(s)};//如果有找到，return目標值
        }
        else{
            indexMap.put(nums[i],i);//如果沒有，把遍歷過的元素和下標(index)加入map中
        }
    }
    return null;
}
}
