/*PROBLEM STATEMENT:
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/

//CODE:

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];
        
        int currentMax = 0;
        int currentMin = 0;
        int finalAns = 0;
        int previousMax = 0;
        int previousMin = 0;
        
        for(int i=0;i<nums.size();i++){
            currentMax = max(previousMax*nums[i],max(previousMin*nums[i],nums[i]));
            currentMin = min(previousMax*nums[i],min(previousMin*nums[i],nums[i]));
            finalAns = max(finalAns,currentMax);
            previousMax = currentMax;
            previousMin = currentMin;
        }
        
        return finalAns;
    }
};
