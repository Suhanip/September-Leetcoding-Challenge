/*PROBLEM STATEMENT
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:
Input: nums = [1,2,3,1], k = 3, t = 0
Output: true

Example 2:
Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/

//CODE
class Solution {
    public:
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
            bool result=false;
            vector<pair<int,int>> pp(nums.size());
            for(int i=0;i<nums.size();i++){
                pp[i].first = nums[i];
                pp[i].second = i;
            }

            sort(pp.begin(),pp.end());
            for(int i=0;i<pp.size();i++){
                for(int j=i+1;j<pp.size();j++){
                    if(pp[i].first+t>=pp[j].first){
                        if(abs(pp[i].second-pp[j].second)<=k){
                            result = true;
                        }
                    }
                    else
                        break;
                }
            }
            return result;
        }
};
