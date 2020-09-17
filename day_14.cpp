/*PROBLEM STATEMENT
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:
0 <= nums.length <= 100
0 <= nums[i] <= 400

*/

//CODE:

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        int v1=nums[0], v2= max(v1,nums[1]);
        //v2 is max of 0th and 1st element
        //we have element till 1 so i will start from 2
        
        for(int i=2;i<n;i++){
            int temp=v2;
            v2= max(v2,nums[i]+v1);
            v1= temp; 
            }
        
        return v2;
    }
};
