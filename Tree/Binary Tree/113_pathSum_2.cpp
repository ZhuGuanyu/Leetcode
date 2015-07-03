/**
 * ID: 113_pathSum_2
 * Name: Path Sum ii
 * Data Structure: Tree
 * Time Complexity:  
 * Space Complexity:  
 * Tag: Tree
 * Difficult: Medium
 
 * Problem: 
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum 
 * equals the given sum. 
 * For example: 
 * Given the below binary tree and sum = 22,
 *            5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
 * return

 [
   [5,4,11,2],
   [5,8,4,5]
 ]

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
#include <vector>
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



class Solution {
public:   
    vector<vector<int> > pathSum(TreeNode *root, int sum) {

        vector<int>  path;
        vector<vector<int> > allPaths;
        DFS(root,sum,path,allPaths);
        return allPaths; 
    }
    void DFS(TreeNode *root, int sum, vector<int> &path, vector<vector<int> > &allPaths)
    {
        if(root == NULL)
            return ;
        path.push_back(root->val);
        if(root ->left == NULL && root -> right == NULL && root->val == sum)
        {
            allPaths.push_back(path);
        }
        else 
        {
            if(root->left )
                DFS(root->left,sum- root->val,path,allPaths);
            if(root->right)
                DFS(root->right,sum- root->val,path,allPaths);
        }
        path.pop_back();
    }
};



int main()
{
    //vector <int> a = {1,3,5};
	Solution ans;
    string a[14] = {"5","4","8","11","#","13","4","7","2","#","#","#","5","1"};

    int b[1] = {1};
    TreeNode * first = constructTree(a,14);
    vector<vector<int> > result = ans.pathSum(first,22);
    
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
            cout<< result[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
    }



