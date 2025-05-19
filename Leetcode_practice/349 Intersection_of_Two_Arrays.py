# Two array的Intersection
#Use Dictionary and Set

class Solution(object):
    def intersection(nums1,nums2):
    #Use Hash Table save一個array中的所有element
        table={}
        for num in nums1:
            table[num]=table.get(num,0)+1
            #Use set to save result
            result=set()
        for num in nums2:
            if num in table:
                result.add(num) #新增有intersection的element到result list
                del table[num]
        return list(result) #return intersection的結果
        

#Use Dictionary
class Solution:
    def intersection(self,nums1,nums2):
        count1=[0]*1001
        count2=[0]*1001 #題目要求length不超過1000
        result=[] #存intersection result
        for i in range(len(nums1)):
            count1[nums1[i]]+=1
        for j in range(len(nums2)):
            count2[nums2[j]]+=1
        for k in range(1001):
            if count1[k]*count2[k]>0:
                result.append(k) #若發現有intersection，新增element到result的dictionary
        return result #return intersection的結果
