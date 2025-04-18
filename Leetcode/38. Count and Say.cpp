class Solution {
public:
    string countAndSay(int n) {
          if(n==1){
              return "1";
          }else{
              string temp=countAndSay(n-1);
              string ans="";
              int count=1;
              char current=temp[0];
              for(int i=1;i<temp.size();i++){
                  if(temp[i]!=current){
                      ans.push_back(count+'0');
                      ans.push_back(current);
                      count=1;
                      current=temp[i];
                  }else{
                      count++;
                  }

              }
              ans.push_back(count+'0');
              ans.push_back(current);
              return ans;
            }
       }
};
