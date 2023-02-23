class Solution {
public:
    string postfixx(string& s) {
        auto precedence = [](char c){return c == '*' || c == '/';};
        stack<char> op;
        string post = "";
        for(auto c : s){ 
            if(c == ' ') continue;
            else if(isdigit(c)) post += c;
            else {
                post += '|';                              // markers to separate numbers
                while(!op.empty() && precedence(c) <= precedence(op.top())){
                    post += op.top();
                    op.pop();
                }
                op.push(c);
            }
        }
        post += '|';
        while(!op.empty()){
            post += op.top();
            op.pop(); 
        }       
        return post;
    }
    int calculate(string& s) {
        s = postfixx(s);
        stack<int> num;
        for(int i = 0; i < s.size(); i++) 
            if(isdigit(s[i])) {
                int cur = 0;
                while(i < s.size() && isdigit(s[i]))
                    cur = cur * 10 + (s[i++] - '0');
                num.push(cur);
            }
            else {
                int num1 = num.top(); num.pop();
                int num2 = num.top(); num.pop();
                if(s[i] == '*')      num.push(num2 * num1);
                else if(s[i] == '/') num.push(num2 / num1);
                else if(s[i] == '+') num.push(num2 + num1);
                else if(s[i] == '-') num.push(num2 - num1);
            }
        
        return num.top();
    }
};
