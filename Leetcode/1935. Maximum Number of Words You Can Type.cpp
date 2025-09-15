class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int res = 0;
        string ch = "";
        vector<string> words;
        bool bl = false;

        for(int i = 0 ; i < text.size() ; i++){
            if(text[i] != ' '){
                ch += text[i];
            }else{
                words.push_back(ch);
                ch = "";
            }
        }
        words.push_back(ch);

        for(int i = 0 ; i < words.size() ; i++){
            bl = false;
            for(int j = 0 ; j < brokenLetters.size() ; j++){
                if(words[i].find(brokenLetters[j]) != -1){
                    bl = true;
                }
            }
            if(!bl){
                res++;
            }
        }
        return res;

    }
};
