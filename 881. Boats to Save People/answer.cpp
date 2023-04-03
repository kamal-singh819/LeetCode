class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int ans = 0;
        int i = 0;
        int j = n-1;
        while(i <= j){
            if(people[i] + people[j] <= limit){
                ans++;
                i++;
                j--;
            }
            else if(people[j] <= limit){
                ans++;
                j--;
            }
        }
        return ans;  
    }
};

//Some optimization in sorted part  instead of O(nlogn) sort the array O(limit) time and O(limit) space
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        //sorting using extra vector T.C = O(limit)
        vector<int> count(limit+1, 0); //create an array of limit+1 size
        for(int p : people) count[p]++; //store count of each element of given array in count array
        int index = 0;
        for(int i=1; i<= limit; i++){ //and again fill the values into people array in sorted way
            while(count[i] > 0){
                people[index++] = i;
                count[i]--;
            }
        }
        ////////////////////////////////
        //remains code is same 
        int ans = 0;
        int i = 0;
        int j = n-1;
        while(i <= j){
            if(people[i] + people[j] <= limit){
                ans++;
                i++;
                j--;
            }
            else if(people[j] <= limit){
                ans++;
                j--;
            }
        }
        return ans;  
    }
};
