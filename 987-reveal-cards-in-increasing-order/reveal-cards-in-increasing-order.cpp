class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());   // sorting the cards in deck

        int n = deck.size();
        vector<int> ans(n);
        deque<int> ind;

        for(int i=0;i<n;i++){  // inititalizing the index as 0,1,2,3,4...
            ind.push_back(i);
        }

        for(int c:deck){
            int i = ind.front();   // Get the next available index
            ind.pop_front();   // Remove the index from the front
            ans[i]=c;        // Place the card in the result array
            if(!ind.empty()){
                ind.push_back(ind.front());  // Move the used index to the end of deque
                ind.pop_front();  // Remove the index from the front
            }
        }
        return ans;
    }
};