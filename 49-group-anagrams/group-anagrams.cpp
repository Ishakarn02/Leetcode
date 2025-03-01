class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;

        for(string word: strs){
            string eachWord = word;

            sort(eachWord.begin(), eachWord.end());
            ans[eachWord].push_back(word);
        }

        vector<vector<string>> res;
        for(auto& group: ans){
            res.push_back(group.second);
        }
        return res;

    }
};