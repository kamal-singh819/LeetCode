/////////////   USing Hash table

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(auto it=hash.begin();it!=hash.end();it++){
            if(k==0){
                if(it->second>=2)
                    cnt++;
            }          
            else if(hash.find(it->first+k)!=hash.end())
                cnt++;
        }
        return cnt;
               
    }
};

//////////////////////Using Binary Search


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        if(k != 0){
            for(int i=0; i<n-1; i++){
                while(i < n-1 && nums[i] == nums[i+1]) i++;
                int x = nums[i]+k;
                int s = i+1;
                int e = n-1;
                while(s <= e){
                    int mid = s + (e-s)/2;
                    if(nums[mid] == x){
                        ans++;
                        cout<<nums[i]<<" "<<x<<endl;
                        break;
                    }
                    else if(nums[mid] < x) s = mid+1;
                    else e = mid-1;
                }
            }
        }
        else{
            bool flag = false;
            for(int i=0; i<n-1; i++){
                if(nums[i] == nums[i+1]){
                    flag = true;
                    if(flag && i == n-2)
                        ans++;
                }
                else if(flag && nums[i] != nums[i+1]){
                    ans++;
                    flag = false;
                }
            }
        }
        return ans;
        
    }
};
