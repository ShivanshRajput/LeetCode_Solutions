class Solution {
private:
    long long timeTaken(int speed , vector<int>&piles){
        long long time = 0;
        for(int &bananas:piles){
            time += (bananas/speed) + (bananas%speed != 0);
        }
        return time;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int highSpeed = *max_element(piles.begin() , piles.end());
        int lowSpeed = 1;
        int minimumSpeed = INT_MAX;
        while(lowSpeed<=highSpeed){
            int midSpeed = lowSpeed + (highSpeed - lowSpeed)/2;
            if(timeTaken(midSpeed , piles) <= h){
                minimumSpeed = midSpeed;
                highSpeed = midSpeed - 1;
            }
            else{
                lowSpeed = midSpeed + 1;
            }
        }
        return minimumSpeed;
    }
};