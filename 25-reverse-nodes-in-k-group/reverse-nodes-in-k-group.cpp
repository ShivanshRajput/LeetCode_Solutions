/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr or head->next==  nullptr) return head;
        ListNode * slow = nullptr;
        ListNode * fast = head;
        while(fast != nullptr){
            ListNode * temp = slow;
            slow = fast;
            fast = fast->next;
            slow->next = temp;
        }
        return slow;
    }
    ListNode* KthNode(ListNode* temp , int k){
        int cnt = 0;
        while(temp!=nullptr){
            cnt++;
            if(cnt==k) break;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;
        while(temp != nullptr){
            ListNode* kthNode = KthNode(temp , k);
            if(kthNode == nullptr){
                if(prevLast){
                    prevLast->next = temp;
                }
                break;
            } 
            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverseList(temp);
            if(temp == head){
                head = kthNode;
            }
            else{
                prevLast->next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};