/**
 * ID: 110
 * Name: Balanced Binary Tree
 * Data Structure: 
 * Time Complexity:  
 * Space Complexity: 
 * Tag: Binary Tree
 * Difficult: Easy
 * Algorithm: 

 * Problem: 
 Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined 
as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

 * Solution: 
// 判断左右子树是不是平衡，然后 左右子树的高度差不大于1 

// 可以把树深度的返回 和 判断平衡树 放在一起
// 用一个特殊的返回值来代表不平衡，这样就少了一层的判断

// Tree depth的定义：为当前节点左右subtree depth中的较大值加1.

 
 * What to learn: 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


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

// 可以把树深度的返回 和 判断平衡树 放在一起
// 用一个特殊的返回值来代表不平衡，这样就少了一层的判断

// Tree depth的定义：为当前节点左右subtree depth中的较大值加1.
// 从下往上，因为是先判断了左右子树，又判断了自身的条件 

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) == -1? false: true;
    }
    int dfs(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        int left = dfs(root -> left);
        int right = dfs(root -> right);
        if (left == -1 || right == -1|| abs(left - right) >1) return -1;
        return max(left,right) +1;
        
    }
};


// 这个相当于从上到下测量 估计
/*
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        if (isBalanced(root->left) && isBalanced(root->right))
            return abs(dfs(root->left) - dfs(root->right)) >1 ? false:true; 
        return false; 
    }
    int dfs(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        if (root ->left == NULL || root->right == NULL )
            return dfs(root->left) + dfs(root ->right) +1 ;
        return max(dfs(root->left),dfs(root->right))+1;
    }
};
*/

int main()
{
    //vector <int> a = {1,3,5};
	Solution ans;
    //string a[13] = {"5","4","8","11","#","13","4","7","1","#","#","#","1"};
    string a[11] = {"1","2","3","4","5","#","#","6","#","#","#"};

    TreeNode * tree = constructTree(a,11);
    int result = ans.isBalanced(tree) ? 1:0;
    printf("%d\n",result);

    //for ()
    //ListNode * pure = ans.addTwoNumbers(first,second);
    //if(pure == NULL)
    //    printf("NULL");
    //else
    //print(pure);
    return 0;
    }



