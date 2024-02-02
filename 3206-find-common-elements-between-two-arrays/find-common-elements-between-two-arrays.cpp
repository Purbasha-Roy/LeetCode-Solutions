class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1;
        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i]]=i;
        }
        unordered_map<int,int> mp2;
        for(int i=0;i<nums2.size();i++){
            mp2[nums2[i]]=i;
        }
        int ans1=0;
        for(int i=0;i<nums1.size();i++){
            if(mp2.find(nums1[i])!=mp2.end()){
                ans1++;
            }
        }
        int ans2=0;
        for(int i=0;i<nums2.size();i++){
            if(mp1.find(nums2[i])!=mp1.end()){
                ans2++;
            }
        }
        return {ans1,ans2};
    }
};