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
        if(head==nullptr) return nullptr;
        Node * temp = head;
        while(temp){
            Node * copy = new Node(temp->val);
            Node * ahead = temp->next;
            temp->next = copy;
            copy->next = ahead;
            temp = ahead;
        }
        temp = head;
        while(temp){
            Node* copy = temp->next;
            if(temp->random) copy->random = temp->random->next;
            else copy->random = nullptr;
            temp = temp->next->next;
        }
        temp = head;
        Node * newHead = temp->next;
        while(temp){
            Node * copy = temp->next;
            if(temp->next) temp->next = temp->next->next;
            if(copy->next) copy->next = copy->next->next;
            temp = temp->next;
        }
        return newHead;
    }
};