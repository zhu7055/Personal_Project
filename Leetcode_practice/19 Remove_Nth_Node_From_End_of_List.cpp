class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(0);//宣告虛擬頭節點
        dummy->next=head;//設定虛擬頭節點位置
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        while(n-- && fast!=NULL){ //快指針向後移動
            fast=fast->next;
        }
        
        fast=fast->next;//快指針在提前走一步，要讓慢指針指向刪除節點的前一個節點
        while(fast!=NULL){ //fast和slow指針，同時向右移動
            fast=fast->next; //fast指向NULL時，slow指向要刪除節點的前一個node
            slow=slow->next;
        }
        slow->next=slow->next->next;//完成刪除倒數第n個節點

        return dummy->next; //回傳頭節點
    }
};