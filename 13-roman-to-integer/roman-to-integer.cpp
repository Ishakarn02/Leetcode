class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int total = 0;
        int prevVal = 0;

        for(int i=s.size() - 1; i>=0; i--){
            int currVal = roman[s[i]];

            if(currVal < prevVal){
                total -= currVal;
            }
            else{
                total += currVal;
            }
            prevVal = currVal;

        }
        return total;
    }
};