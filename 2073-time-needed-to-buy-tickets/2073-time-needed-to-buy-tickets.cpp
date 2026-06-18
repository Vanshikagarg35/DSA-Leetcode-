class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        for(int i=0; i<tickets.size(); i++){
            q.push({i,tickets[i]});
        }
        int count = 0;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.front().second--;
            count++;
            if(i==k && q.front().second==0){
                q.pop();
                return count;
            }
            else if(i!=k && q.front().second==0){
              
                q.pop();

            }
            else{
                q.push({i,q.front().second});
                q.pop();
            }
        }
        return -1;
    }
};