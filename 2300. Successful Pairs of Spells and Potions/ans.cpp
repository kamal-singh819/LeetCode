//I have not taken any extra space modified in spells vector.
//Time Complexitty O(N.log(N))  & S.C is O(1)

//If we use, double for loop, that will give Time Limit Exceeded- (O(N^2)) 


class Solution {
private:
    int binarySearch(vector<int> &p, int &x, long long &success){
        int start = 0;
        int end = p.size()-1;
        int mid = start + (end-start)/2;
        while(start <= end){
            long long mul = (long long)x * p[mid];
            if(mul >= success)
                end = mid-1;
            else
                start = mid+1;

            mid = start + (end-start)/2;        
        }
        return start;
    }    
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        for(int i=0; i<n; i++){
            spells[i] = m-binarySearch(potions, spells[i], success);  //First, we will find out the size of array of product of their strengths which is less than success using binary search. Then subtract from the size of potions.
        }  
        return spells;
    }
};
