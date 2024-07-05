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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>criticalPoints;
        ListNode * prev = head;
        ListNode * curr = head->next;
        int position = 0;
        while(curr->next!=nullptr){
            if((curr->val>prev->val && curr->val>curr->next->val) ||
                (curr->val<prev->val && curr->val<curr->next->val)){
                criticalPoints.push_back(position);
                }
            prev = curr;
            curr = curr->next;
            position++;
        }
        if(criticalPoints.size()<=1){
            return {-1,-1};
        }
        int maxDist = criticalPoints.back() - criticalPoints.front();
        int minDist = maxDist;
        for(int i=1;i<criticalPoints.size();i++){
            minDist = min(minDist , criticalPoints[i] - criticalPoints[i-1]);
        }
        return {minDist , maxDist};
    }
};