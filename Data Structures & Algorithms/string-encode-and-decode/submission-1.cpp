class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for(auto& str : strs){
            encoded_string += str + '#' + to_string(str.size());
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string>strs;
        string word = "";
        for(int i = 0; i+1 < s.size();++i){
            if(s[i] == '#' && word.size() ==  s[i+1]-'0'){
                strs.push_back(word);
                word = "";
                i+=1;
            }else{
                word += s[i];
            }
        }
        return strs;

    }
};
