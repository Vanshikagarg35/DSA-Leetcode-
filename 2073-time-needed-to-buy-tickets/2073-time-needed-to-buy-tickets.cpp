class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
       
        queue<int>q;
        for(int i=0; i<tickets.size(); i++){
            q.push(i);

        }
        int count = 0;
        while(!q.empty()){
            int i = q.front();
            if(q.front()==k){
                tickets[k]--;
                int left = tickets[i];
                if(left>0){
                    q.pop();
                    q.push(i);
                    count++;
                }
                else if(left==0){
                    q.pop();
                    count++;
                    return count;
                }
            }
            else{
                tickets[i]--;
                int left = tickets[i];
                if(left>0){
                    q.pop();
                    q.push(i);
                    count++;
                }
                else if(left==0){
                    count++;
                    q.pop();
                }
            }
        }
        return -1;

    }
};