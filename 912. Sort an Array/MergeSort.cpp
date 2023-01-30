class Solution {
public:
    void merge(vector<int> &nums, int s, int e){
        int mid = s+(e-s)/2;
        int n1 = mid-s+1; //size of first part
        int n2 = e-mid; //size of second part
        vector<int> v1(n1);
        vector<int> v2(n2);
        int mainIndex = s;
        for(int i=0; i<n1; i++){
            v1[i] = nums[mainIndex++];
        }
        mainIndex = mid+1;
        for(int i=0; i<n2; i++){
            v2[i] = nums[mainIndex++];
        }

        //now merge both of v1 & v2

        int i = 0; //for v1
        int j = 0; //for v2
        mainIndex = s;
        while(i < n1 && j < n2){
            if(v1[i] < v2[j])
                nums[mainIndex++] = v1[i++];
            else
                nums[mainIndex++] = v2[j++];    
        }
        while(i < n1)
            nums[mainIndex++] = v1[i++];
        while(j < n2)
            nums[mainIndex++] = v2[j++];    
    }

    void mergeSort(vector<int> &nums, int s, int e){
        if(s >= e)
            return;
        int mid = s+(e-s)/2;

        mergeSort(nums, s, mid);
        mergeSort(nums, mid+1, e);

        merge(nums, s, e);
    }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums;
        int s = 0;
        int e = nums.size()-1;

        mergeSort(nums, s, e);

        return nums;
        
    }
};
