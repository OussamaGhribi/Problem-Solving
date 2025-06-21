class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>freq;
        for(auto x:word){
            freq[x]++;
        }
        vector<int>freqs;
        for(auto &[_,v]:freq){
            freqs.push_back(v);
        }

        sort(freqs.begin(),freqs.end());

        int n=freqs.size(),prevDel=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int minF=freqs[i];
            int del=prevDel;
            for(int j=i+1;j<n;j++){
                if(freqs[j]>minF+k) del+=(freqs[j]-minF-k);
            }
            ans=min(ans,del);
            prevDel+=freqs[i];
        }

        return ans;
    }
};
