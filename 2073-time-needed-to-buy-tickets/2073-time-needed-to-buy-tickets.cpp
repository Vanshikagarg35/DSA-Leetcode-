class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for(int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }
        
        int count = 0;
        
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            
            tickets[i]--;
            count++;
            
            if(tickets[i] == 0 && i == k) {
                return count;
            }
            
            if(tickets[i] > 0) {
                q.push(i);
            }
        }
        
        return count;
    }
};