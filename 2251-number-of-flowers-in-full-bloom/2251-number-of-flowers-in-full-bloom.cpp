class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start;
        vector<int> end;

        vector<int> result(people.size()); 
        
        for(int i = 0; i < flowers.size(); i++) {
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        for(int i = 0; i < people.size(); i++) {
            int l = 0;
            int r = start.size()-1;
            
            while(l<=r){
                int mid = l + (r-l)/2;
                if(people[i]<start[mid]) r = mid-1;
                else if(people[i]>=start[mid]) l = mid+1;
            }
            int startcount = l;
            l = 0;
            r = end.size()-1;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(people[i]<=end[mid]) r = mid-1;
                else if(people[i]>end[mid]) l = mid+1;
            }
            int endcount = l;
            result[i] = startcount - endcount;
        }
        return result;

        
    }
};