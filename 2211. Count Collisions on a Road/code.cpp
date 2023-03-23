class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.length();
        if(n == 1) return 0; //if string length is 1 only
        int i = 0;
        int ans = 0;
        stack<char> st;
        while(i < n){
            if(i < n && directions[i] == 'L' && st.empty()) i++; //if many 'L' is presents at starting of directions string
            if(i < n && directions[i] == 'S'){  //if many 'S' is presents at starting of directions string
                st.push('S');
                i++;
            }
            else if(i < n && !st.empty() && directions[i] == 'L'){  //if L occur comes after some occurence of 'S' or 'R'
                ans += 1;
                st.push('S');
                i++;
            }
            else if(i < n && directions[i] == 'R'){ //if 'R' occur
                if(i == n-1) break; //if i is at the end then break
                if(directions[i+1] == 'R'){
                    st.push('R');
                    i++;
                }
                if(directions[i+1] == 'L'){
                    ans += 2;
                    st.push('S');
                    i = i+2;
                }
                else if(directions[i+1] == 'S'){
                    ans += 1;
                    st.push('S');
                    i = i+2;
                }

            }
        }
        while(!st.empty() && st.top() == 'R') st.pop(); //if many 'R' are present at last of directions string, remove them
        while(!st.empty()){
            if(st.top() == 'R'){
                ans += 1;
            }
            st.pop();
        }
        return ans;
    }
};
