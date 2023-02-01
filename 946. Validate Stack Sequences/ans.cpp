class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size())
            return false;
        stack<int> st; //stack for pushed array
        st.push(-1);

        int j=0; //for array popped
        int n = pushed.size();

        for(int i=0; i<n; i++){
            if(pushed[i] != popped[j]){
                while(st.top() == popped[j]){
                    st.pop();
                    j++;
                }
                st.push(pushed[i]);
            }
            else{
                j++;
            }
        }

        while(!st.empty() && j<n){
            if(st.top() == popped[j]){
                j++;
                st.pop();
            }
            else
                return false;
        }
        return true;
        
    }
};
