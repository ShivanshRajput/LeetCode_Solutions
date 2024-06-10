/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node* , Node*>mp;
        while(temp){
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp){
            if(temp->next) mp[temp]->next = mp[temp->next];
            else  mp[temp]->next = nullptr;
            if(temp->random) mp[temp]->random = mp[temp->random];
            else  mp[temp]->random = nullptr;
            temp = temp->next;
        }
        return mp[head];
    }
};