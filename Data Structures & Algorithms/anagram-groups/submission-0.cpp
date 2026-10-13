class Solution {
private:
    bool checkAnagram(string s,string t){
        int check[26] = {0};
        for(int i = 0;i<s.size();i++){
            check[s[i] - 'a']++;
            check[t[i] - 'a']--;
        }
        for(int i = 0; i<26;i++){
            if(check[i] != 0) return false;
        }
        return true;
    }
    int findPush (vector<vector<string>>& ans,string& str){
        for(int i = 0;i<ans.size();i++){
            if(ans[i][0].size() != str.size()) continue;
            if(checkAnagram(ans[i][0],str)){
                return i;
            }
        }
        return -1;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        ans.push_back({strs[0]});
        for(int i = 1;i<strs.size();i++){
            
            int pushInd = findPush(ans,strs[i]);
            if(pushInd != -1){
                ans[pushInd].push_back(strs[i]);
            }else{
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};
