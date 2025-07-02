/*此問題的解決方法：
初始化兩個變量，oddCount 用於儲存出現次數為奇數的字元數，無序映射 ump 用於儲存字串中每個字元的計數。
迭代字串，對於每個字元 ch，增加無序映射中該字元的計數。
如果目前字元 ch 的計數為奇數，則增加 oddCount。 如果計數為偶數，則減少 oddCount。
如果 oddCount 大於 1，則傳回 s.length() - oddCount + 1，這是使用除一個出現次數為奇數的字元以外的所有字元形成的回文的最大長度。
如果 oddCount 不大於 1，則傳回 s.length()，也就是原始字串的長度，因為所有字元都可以用來形成回文。*/

#include <string>

class Solution {
public:
    int longestPalindrome(string s) {
        int oddCount=0;//用於儲存出現次數為奇數，目前ch的計數為奇數，則增加oddCount
        unordered_map<char, int> ump;
        for(char ch : s){
            ump[ch]++;
            if(ump[ch]%2==1){
                oddCount++;
            }
            else{
                oddCount--;
            }
        }
        if(oddCount > 1){
            return s.length()-oddCount+1;
        }
        return s.length();
    }
};