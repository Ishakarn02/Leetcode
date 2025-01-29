class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int lastoddIndex = -1;

        for(int i = num.size(); i >= 0; i--){
            if(num[i] % 2 != 0){
                lastoddIndex = i;
                break;
            }
        }

        

        for(int i=0; i <= lastoddIndex; i++){
            ans += num[i];
        }

        return ans;
    }
};