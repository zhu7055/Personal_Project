# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self,head):
        slow=head
        fast=head
        
        while fast and fast.next:
            slow = slow.next #slow向後1步
            fast=fast.next.next #fast向後2步
            
            #如果有一個cycle，slow和fast pointer會相遇
            if slow==fast:
                #移動其中一個pointers回到list的開頭
                slow=head
                while slow!=fast:
                    slow = slow.next
                    fast=fast.next
                return slow
                
        #當沒有cycle，return None
        return None