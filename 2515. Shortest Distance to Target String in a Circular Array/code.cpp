class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        if(words[startIndex] == target) return 0;
        //move to right
        int right = 1;
        int i = (startIndex+1)%n;
        while(i != startIndex){
            if(words[i] == target) break;
            right++;
            i = (i+1)%n;
        }

        //move to left
        int left = 1;
        int j = (startIndex-1+n)%n;
        while(j != startIndex){
            if(words[j] == target) break;
            left++;
            j = (j-1+n)%n;
        }
        return min(left, right) == n ? -1 : min(left, right);
    }
};
