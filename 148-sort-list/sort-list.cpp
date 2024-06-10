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
    ListNode *merge2list(ListNode *l1 , ListNode *l2){
        ListNode * dummyHead = new ListNode(-1);
        ListNode * move = dummyHead;
        while(l1 && l2){
            if(l1->val <= l2->val){
                move->next = l1;
                l1 = l1->next;
                move = move->next;
            }   
            else{
                move->next = l2;
                l2 = l2->next;
                move = move->next;
            }
        }
        if(l1){
            move->next = l1;
        }
        else{
            move->next = l2;
        }
        return dummyHead -> next;
    }


    ListNode * findMid(ListNode * head){
        ListNode * mid = head;
        ListNode * fast = head;
        while(fast->next && fast->next->next){
            mid = mid->next;
            fast = fast->next->next;
        }
        return mid;
    }
    ListNode* mergeSort(ListNode* head){
        if(head->next){
            ListNode * mid = findMid(head);
            ListNode * l2 = mid->next;
            mid->next = nullptr;
            head = mergeSort(head);
            l2 = mergeSort(l2);
            head = merge2list(head , l2);
        }
        return head;
    }

    ListNode* sortList(ListNode* head) {
        if(head==nullptr or head->next==nullptr) return head;
        return mergeSort(head);
    }
};