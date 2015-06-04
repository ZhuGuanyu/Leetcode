/**
 * ID: 129
 * Name: Sum Root to Leaf Numbers
 * Data Structure: 
 * Time Complexity: 
 * Space Complexity: 
 * Tag: Tree
 * Difficult: Medium
 * Algorithm: DFS recursion
 
 * Problem: 
 Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

 * Solution: 
 * 1. 想好左右子树 还有返回值
 
 * What to learn: 
 * 

 * Note: to ask the interviewer the number maybe too large that the int maybe invalid.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/


#include <iostream>
#include <list>
#include <queue>
 using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};



ListNode* create_list(int* array,int n)
{
    if (n==0)
        return NULL;
    ListNode *head,*current;
    head = current = new ListNode(array[0]);
    for (int i=1;i<n;i++) 
    {
        ListNode *node = new ListNode(array[i]);
        current -> next = node; 
        current = current -> next; 
    }
    return head; 
}

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

void print(TreeNode * root)
{
    if(root == NULL)
        return ;
    queue <TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode *cur =  q.front();
        cout<< cur->val; 
        q.pop();
        if(cur -> left) q.push(cur->left);
        if(cur -> right) q.push(cur->right);
    }
}


class Solution {
public:
    int sumNumbers(TreeNode* root) {  // DFS 想好递归的参数和返回值
        if (root == NULL)
            return 0;
        if (root -> left == NULL && root -> right == NULL)
            return root -> val; 
        int total = root -> val;
        return dfs(root, 0) ;
    }
    int dfs(TreeNode* root, int sum)
    {
        if(root->left == NULL && root->right == NULL)
        {
            return sum*10+root->val;
        }
            
        else if (root ->left != NULL && root -> right != NULL)
            return dfs(root->left, root->val + sum*10) + dfs(root->right, root->val + sum*10);
        else if (root -> right != NULL)
            return dfs(root->right, root->val + sum*10);
        else if (root -> left != NULL)
            return dfs(root->left, root->val + sum*10);
    }
};

int main()
{
    //vector <int> a = {1,3,5};
	Solution ans;
    //string a[13] = {"5","4","8","11","#","13","4","7","1","#","#","#","1"};
    string a[5] = {"1","0","#","#","#"};

    TreeNode * tree = constructTree(a,5);
    int result = ans.sumNumbers(tree);
    cout<<result;

    //for ()
    //ListNode * pure = ans.addTwoNumbers(first,second);
    //if(pure == NULL)
    //    printf("NULL");
    //else
    //print(pure);
    return 0;
    }



