class Solution {
public:
    set<string> result; 
    map<int,int> flag;
    string s;

    void solve(string& tiles){

        for(int i=0;i<tiles.size();i++){
            if(flag[i]!=1){
                s.push_back(tiles[i]);
                flag[i]=1;
                result.insert(s);

                solve(tiles);
                s.pop_back();
                flag[i]=0;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        solve(tiles);
        return result.size();
    }
};
