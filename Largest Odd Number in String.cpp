class Solution {
public:
    string largestOddNumber(string num) {
        int i=num.size()-1;
        while(num.size()>0){
            if((num[i]-'0')%2){
                break;
            }
            else{
                num.pop_back();
                i--;
            }
        }
        return num;
    }
};
