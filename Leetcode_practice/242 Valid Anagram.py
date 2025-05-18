class Solution:
    def isAnagram(self,s:str,t:str):
        record=[0]*26
        for i in s:
        #不需記字符a的ASCII，只要求出一個相對數值就可以
            record[ord(i)-ord("a")]+=1
        for i in t:
            record[ord(i)-ord("a")]-=1
        for i in range(26):
            if record[i]!=0:
                #record若有些element!=0，說明string s和t，一定有多字符or少字符。
                return False
        return True