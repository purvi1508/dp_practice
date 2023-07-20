class Solution {
public:
    void select(vector<int>& time, int i, int count, int sum, vector<int>& m) {
        if (i < 0 || count == 2) {
            if (count == 2) {
                m.push_back(sum);
            }
            return;
        }

        select(time, i - 1, count + 1, sum + time[i], m);
        select(time, i - 1, count, sum, m);
    }
    int numPairsDivisibleBy60(vector<int>& time) {
        int count=0;
        vector<int> m;
        select(time, time.size() - 1, 0, 0, m);
        for(int i=0;i<m.size();i++){
            if(m[i]%60==0){
                count++;
            }
        }
        return count;
    }
};
