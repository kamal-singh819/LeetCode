class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        
        //mp1 stores the frequencies of nums1 array elements
        for(int i=0; i<nums1.size(); i++){
            mp1[nums1[i]]++;
        }
        
        //mp2 stores the frequencies of nums2 array elements
        for(int i=0; i<nums2.size(); i++){
            mp2[nums2[i]]++;
        }

        vector<int> vec1;
        //now search the elements of mp1 into mp2
        for(auto x : mp1){
            if(!mp2.count(x.first))
                vec1.push_back(x.first);
        }
        ans.push_back(vec1);

        vector<int> vec2;
        //now search the elements of mp2 into mp1
        for(auto x : mp2){
            if(!mp1.count(x.first))
                vec2.push_back(x.first);
        }
        ans.push_back(vec2);

        return ans;
        
    }
};
