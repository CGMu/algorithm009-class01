class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size=m+n;
        vector<int> result;
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){result.push_back(nums1[i++]);}
            else{result.push_back(nums2[j++]);} 
        }
        
        if(i<m){
            for(int k=i; k<m; k++) result.push_back(nums1[k]);
        }
        if(j<n){
            for(int l=j; l<n; l++) result.push_back(nums2[l]);
        }
        for(int n=0; n<size; n++) nums1[n]=result[n];
    }
};