class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        sort(seats.begin() , seats.end());
        sort(students.begin() , students.end());
        int_fast16_t moves = 0;
        for(int_fast8_t i=0;i<seats.size();i++){
            moves += abs(seats[i] - students[i]);
        }
        return moves;
    }
};