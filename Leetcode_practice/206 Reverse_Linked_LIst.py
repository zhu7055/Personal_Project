# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev=None
        while head:
            next=head.next #head指向自己->指向下一個head
            head.next=prev#head.next指向前一個(prev)
            prev=head#prev:指向前一個->指向自己(head)
            head=next
        return prev

#「指向下一個 head.next」改成指向「前一個節點 prev」：
#head.next=prev