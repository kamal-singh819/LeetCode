// HERE WE HAVE USED EXTRA PAIR VECTOR OF PAIR S.C = (n)

class Solution {
public:
    static bool comp(pair<int, string> a, pair<int, string> b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = dictionary.size();
        vector<pair<int, string> > pair;
        for(int i=0; i<n; i++) pair.push_back({dictionary[i].length(), dictionary[i]});

        sort(pair.begin(), pair.end(), comp);

        for(int i=0; i<n; i++){
            string str = pair[i].second;
            int j = 0;
            int k = 0;
            while(j < s.length() && k < pair[i].first){
                if(s[j] == str[k]){
                    j++;
                    k++;
                }
                else j++;
            }
            if(k == pair[i].first) return str;
        }
        return "";
    }
};

//  WITHOUT USING ANY EXTRA SPACE

class Solution {
private:
    bool isPossibleToMake(string str, string &s){
        int i=0; //for string str
        int j=0; //for string s
        while(i < str.length() && j < s.length()){
            if(str[i] == s[j]){
                i++;
                j++;
            }
            else j++;
        }
        if(i == str.length()) return true;
        return false;
    }
public:
    string findLongestWord(string s, vector<string>& dict) {
        string ans = "";
        for(auto str : dict){
            if(isPossibleToMake(str, s)){
                if(ans.length() < str.length() || (ans.length() == str.length() && str < ans))
                    ans = str;
            }
        }
        return ans;
        
    }
};
