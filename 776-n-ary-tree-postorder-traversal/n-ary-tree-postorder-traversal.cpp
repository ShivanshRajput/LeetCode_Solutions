/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void dfs(Node * root , vector<int> &ans){
        if(root == nullptr) return ;
        for(auto &it:root->children){
            dfs(it , ans);
            ans.push_back(it->val);
        }
        return ;
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(root==nullptr) return {};
        dfs(root , ans);
        ans.push_back(root->val);
        return ans;
    }
};