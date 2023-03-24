class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int ans = 0;
        string num1 = "", num2 = "";
        bool flag = true;
        for(char x : s){
            if(flag){
              num1 += x;
              flag = false;
            }else{
              num2 += x;
              flag = true;
            }
        }
        return stoi(num1) + stoi(num2); 
    }
};
