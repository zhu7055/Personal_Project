class Solution(object):
    def fourSumCount(self, nums1, nums2, nums3, nums4):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type nums3: List[int]
        :type nums4: List[int]
        :rtype: int
        """
        #用dictionary存nums1,nums2的元素，和
        hashmap=dict()
        for n1 in nums1:
            for n2 in nums2:
                if n1+n2 in hashmap:
                    hashmap[n1+n2]+=1#統計n1+n2的出現次數
                else:
                    hashmap[n1+n2]=1
        #if nums3和nums4，存在-(n1+n2)，存到count
        count=0
        for n3 in nums3:
            for n4 in nums4:
                key = -n3-n4
                if key in hashmap:#找到hashmap中key對應的數值
                    count+=hashmap[key]
        return count #count統計四元組