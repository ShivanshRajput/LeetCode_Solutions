class Solution
{
private:
    int increasingsubs(vector<int> &rating, int n)
    {
        vector<int> greaterahead(n);
        vector<int> smallerbehind(n);
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (rating[j] > rating[i])
                    count++;
            }
            greaterahead[i] = count;
        }
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (rating[j] < rating[i])
                    count++;
            }
            smallerbehind[i] = count;
        }
        int increasing = 0;
        for (int i = 0; i < n; i++)
        {
            increasing += greaterahead[i] * smallerbehind[i];
        }

        return increasing;
    }

    int decreasingsubs(vector<int> &rating, int n)
    {
        vector<int> greaterbehind(n);
        vector<int> smallerahead(n);
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (rating[j] < rating[i])
                    count++;
            }
            smallerahead[i] = count;
        }
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (rating[j] > rating[i])
                    count++;
            }
            greaterbehind[i] = count;
        }
        int decreasing = 0;
        for (int i = 0; i < n; i++)
        {
            decreasing += greaterbehind[i] * smallerahead[i];
        }
        return decreasing;
    }

public:
    int numTeams(vector<int> &rating)
    {
        int n = rating.size();
        int increasing = increasingsubs(rating, n);
        int decreasing = decreasingsubs(rating, n);
        return increasing + decreasing;
    }
};