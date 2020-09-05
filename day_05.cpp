/*PROBLEM STATEMENT
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

Example 1:
      2                 1
    /   \             /   \
   1     4           0     3

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Example 2:
Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]

*/

//CODE:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inordertraversal(TreeNode* root,vector<int> &arr){
        
        if(root==NULL) return;
        
        inordertraversal(root->left,arr);
        arr.push_back(root->val);
        inordertraversal(root->right,arr);
        
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1,arr2;
        
        inordertraversal(root1,arr1);
        inordertraversal(root2,arr2);
        
        int i=0;
        int j=0;
        vector<int> ans;
        while(i<arr1.size() and j<arr2.size()){
            if(arr1[i]<=arr2[j]){
                ans.push_back(arr1[i]);
                i++;
            }
            else{
                ans.push_back(arr2[j]);
                j++;
            }
        }
        
        //if there is some remaining value of i and j
        while(i<arr1.size()){
            ans.push_back(arr1[i]);
            i++;
        }
        while(j<arr2.size()){
            ans.push_back(arr2[j]);
            j++;
        }

        
        return ans;
    }
};
