class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes = {2,3,5};
        priority_queue<long, vector<long> , greater<long>> minHeap;
        unordered_set<long> visited;

        minHeap.push(1);
        visited.insert(1);
        long no;
        for(int i = 0;i<n;i++){
            no = minHeap.top();
            minHeap.pop();
            for(int &x: primes){
                long newNo = no*x;
                if(visited.find(newNo) == visited.end()){
                    minHeap.push(newNo);
                    visited.insert(newNo);
                }
            }
        }
        return (int)no;
    }
};