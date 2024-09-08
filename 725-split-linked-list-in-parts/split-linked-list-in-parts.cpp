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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<ListNode*> ans(k, nullptr);
        int totalLength = 0;
        ListNode* temp = head;
        
        // Calculate the total length of the linked list
        while (temp) {
            totalLength++;
            temp = temp->next;
        }
        
        // Calculate the size of each part
        int partSize = totalLength / k;
        int extraNodes = totalLength % k; // These will be distributed in the first 'extraNodes' parts
        
        temp = head;
        for (int i = 0; i < k && temp; i++) {
            ans[i] = temp;
            int currentPartSize = partSize + (extraNodes > 0); // Add an extra node to the first 'extraNodes' parts
            extraNodes--;
            
            // Advance to the end of the current part
            for (int j = 1; j < currentPartSize; j++) {
                temp = temp->next;
            }
            
            // Break the list and move to the next part
            ListNode* nextPart = temp->next;
            temp->next = nullptr;
            temp = nextPart;
        }
        
        return ans;
    }
};
