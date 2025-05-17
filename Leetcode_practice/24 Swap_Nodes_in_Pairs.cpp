class Solution{
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* dummy=new ListNode(0);//虛擬頭節點
        dummy->next=head;
        ListNode* cur=dummy;
        while(cur->next!=nullptr && cur->next->next!=nullptr)
        {
            ListNode* tmp1 = cur->next; //節點1
            ListNode* tmp2 = cur->next->next->next; //節點3
            
            cur->next=cur->next->next; //step1，dummy->2
            cur ->next-> next=tmp1; //step2，2->1
            cur->next->next->next=tmp2;//step3，3->1
            
            cur=cur->next->next; //cur向後移兩位，跳到while開頭，下一輪交換
        }
        ListNode* result=dummy->next;
        delete dummy;
        return result; //回傳頭節點
    }
};