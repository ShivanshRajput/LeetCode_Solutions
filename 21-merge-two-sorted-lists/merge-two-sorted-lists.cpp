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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        while(list1 && list2){
            if(list1->val <= list2->val){
                if(prev == nullptr){
                    head = prev = list1;
                }
                else{
                    prev->next = list1;
                    prev = list1;
                }
                list1 = list1->next;
            }
            else{
                if(prev == nullptr){
                    head = prev = list2;
                }
                else{
                    prev->next = list2;
                    prev = list2;
                }
                list2 = list2->next;
            }
        }
        if(list1){
            if(prev==nullptr){
                head = list1;
            }
            else{
                prev->next = list1;
            }
        }
        if(list2){
            if(prev==nullptr){
                head = list2;
            }
            else{
                prev->next = list2;
            }
        }
        return head;
    }
};