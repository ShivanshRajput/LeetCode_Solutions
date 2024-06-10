class Node{
    public:
        string data;
        Node* next;
        Node* prev;
        Node(): data(0), next(NULL), prev(NULL) {} ;
        Node(string x): data(x), next(NULL), prev(NULL) {} ;
        Node(string x , Node* _next , Node* _prev): data(x), next(_next), prev(_prev) {} ;
};
class BrowserHistory {
public:
    Node* currentPage;
    BrowserHistory(string homepage) {
        currentPage = new Node(homepage);
    }
    
    void visit(string url) {
        Node * newNode = new Node(url);
        currentPage->next = newNode;
        newNode->prev = currentPage;
        currentPage = newNode;
    }
    
    string back(int steps) {
        while(steps--){
            if(currentPage->prev) currentPage = currentPage->prev;
            else  break;
        }
        return currentPage->data;
    }
    
    string forward(int steps) {
        while(steps--){
            if(currentPage->next) currentPage = currentPage->next;
            else  break;
        }
        return currentPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */