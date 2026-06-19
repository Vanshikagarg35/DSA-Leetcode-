class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>result(gain.size()+1);
        result[0]=0;
        for(int i=1; i<gain.size()+1; i++){
            result[i] = gain[i-1]+result[i-1];
        }
        int maxl = 0;
        for(int i=0; i<result.size(); i++){
            maxl = max(maxl , result[i]);
        }
        return maxl;
    }
};