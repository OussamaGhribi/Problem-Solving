class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int ans = 0;
        int f = 0;
        for(int i = 0 ; i < tickets.size(); i++){
            q.push(i);
        }

        while(tickets[k]>0){
            f = q.front();
            q.pop();
            ans++;

            tickets[f]--;

            if(tickets[f] > 0){
                q.push(f);
            }
        }
        return ans;
    }
};
