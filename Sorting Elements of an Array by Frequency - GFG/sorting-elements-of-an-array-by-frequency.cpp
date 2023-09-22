#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
static bool comp(pair<int,int>&p1, pair<int,int>&p2){
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second > p2.second;
}
int main() {
	int t;
	cin>>t;
	while(t){
	    int n;
	    cin>>n;
	    vector<int> nums(n);
	    for(int i=0; i<n; i++) cin>>nums[i];
	    vector<pair<int,int>> vp(61);
	    for(int i : nums){
	        vp[i].first = i;
	        vp[i].second++;
	    }
	    sort(vp.begin(), vp.end(), comp);
	    int i = 0;
	    for(int j=0; j<vp.size(); j++){
	       // cout<<vp[j].first<<" "<<vp[j].second<<endl;
	        if(vp[j].first == 0) break;
	        int f = vp[j].second;
	        while(f){
	            nums[i++] = vp[j].first;
	            f--;
	        }
	    }
	    for(int i=0; i<n-1; i++){
	        cout<<nums[i]<<" ";
	    }
	    cout<<nums[n-1]<<endl;
	    t--;
	}
	return 0;
}