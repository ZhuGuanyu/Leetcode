/**
 * ID: 112_pathSum
 * Name: Path Sum
 * Data Structure: Linked List
 * Time Complexity:  
 * Space Complexity:  
 * Tag: LinkList
 * Difficult: Easy
 
 * Problem: 
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that 
 * adding up all the values along the path equals the given sum.
 * For example: 
 * Given the below binary tree and sum = 22
 *            5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

 * Solution: 
 * 
 
 * What to learn: 
 * 

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 **/

#include <iostream>
#include <list>
 using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode *constructTree(string *dat , int len)
{
    if(dat == NULL)
        return NULL;
    TreeNode *root = NULL;
    int index = 0;
    if(len > 0)
        root = new TreeNode(stoi(dat[index]));
    else
        return NULL;
    list<TreeNode *> node; //其实相当于 queue
    node.push_back(root);
    index ++;
    while(index < len)
    {
        if(!node.empty())
        {
            TreeNode *root = node.front();
            if(index < len )
            {
                if(dat[index].compare("#") != 0)
                {
                  root->left = new TreeNode(stoi(dat[index]));    
                  node.push_back(root->left);
                }
                index ++;
            }
            if(index < len )
            {
                if(dat[index].compare("#") != 0)
                {
                  root->right = new TreeNode(stoi(dat[index]));   
                  node.push_back(root->right);
                }
                index ++;
            }
            node.pop_front();
        }
    }
    return root;
}



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*  
 //  一个非常简单的代码
 class Solution {
 public:
    bool hasPathSum(TreeNode *root, int sum) {   // This is very similar to the usual DFS
        if(root == NULL)
            return false; 
        if(root->left==NULL && root->right == NULL && root->val == sum)
            return true; 
        return hasPathSum(root->left,sum - root->val) || hasPathSum(root->right,sum - root->val);
    }
};
*/

// 一个典型的 DFS 代码
 class Solution {
 public:
    bool dfs(TreeNode *node, int sum, int curSum)
    {
        if (node == NULL)
            return false; 
        if (node->left== NULL && node->right == NULL)
            return curSum + node->val == sum; 

        return dfs(node ->left, sum,curSum+node->val) || dfs(node->right, sum, curSum+node->val);
    }
    bool hasPathSum(TreeNode *root, int sum) {   // This is very similar to the usual DFS
        if(root == NULL)
            return false; 
        if(root->left==NULL && root->right == NULL && root->val == sum)
            return true; 
        return hasPathSum(root->left,sum - root->val) || hasPathSum(root->right,sum - root->val);
    }
};




int main()
{
    //vector <int> a = {1,3,5};
	Solution ans;
    string a[13] = {"5","4","8","11","#","13","4","7","1","#","#","#","1"};

    int b[1] = {1};
    TreeNode * first = constructTree(a,13);
    bool check = ans.hasPathSum(first,22);
    cout<<(check? "true":"flase");
    //ListNode * pure = ans.addTwoNumbers(first,second);
    //if(pure == NULL)
    //    printf("NULL");
    //else
    //print(pure);
    return 0;
    }



