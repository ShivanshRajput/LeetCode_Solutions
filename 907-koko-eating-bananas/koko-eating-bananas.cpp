class Solution {
public:

    long long calculatehours(vector<int>& piles,int mid)
    {
        long long time=0;
        for(int i=0;i<piles.size();i++)
        {
            if((piles[i]%mid)!=0)
            time=time+(piles[i]/mid)+1;
            else
            time=time+(piles[i]/mid);
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            maxi=max(maxi,piles[i]);
        }
        int low=1,high=maxi;;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(calculatehours(piles,mid)<=h)
            {
                high=mid-1;
            }
            else 
            {
                low=mid+1;
            }
        }
        return low;
    }
};