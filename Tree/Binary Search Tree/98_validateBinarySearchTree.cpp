/**
 * ID: 98
 * Name: Validate Binary Search Tree
 * Data Structure: 
 * Time Complexity:  
 * Space Complexity: 
 * Tag: Binary Search Tree
 * Difficult: Medium
 * Algorithm: 

 * Problem: 

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

 * Solution: 

 
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
#include <stack>
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
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        if (root->left == NULL && root->right == NULL)
            return true;
        stack<TreeNode*> s;
        TreeNode* p = root; 
        int left,flag;
        flag = 0;
        while(p)
        {
            while(p)
            {
                s.push(p);
                p = p->left;
            }
            while(!s.empty())
            {
                TreeNode * cur = s.top();
                s.pop();
                if(flag == 0)
                {
                    flag = 1;
                    left = cur->val;
                }
                else if(cur->val <= left)
                    return false;
                left = cur->val;
                if(cur->right)
                {
                    p = cur->right;
                    break;
                }

            }
            
        }
        return true;
    }
};

// 递归调用中跟遍历 左根右， 然后用一个全局变量引导
/*

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        static int m = INT_MIN;
        if(root == NULL) return true;
        if(!isValidBST(root->left)) return false;
        if(!(root->val > m)) {
            return false;
        }
        m = root->val;
        return isValidBST(root->right);
    }
};
*/



int main()
{
    //vector <int> a = {1,3,5};
	Solution ans;
    //string a[13] = {"5","4","8","11","#","13","4","7","1","#","#","#","1"};
    string c[5] = {"1","#","2","#","3"};
    string a[7] = {"10","5","15","#","#","6","20"};
    string b[11] = {"1","2","3","4","5","#","#","6","7","#","#"};

    TreeNode * tree = constructTree(a,7);
    //TreeNode * tree2 = constructTree(b,11);
    bool result = ans.isValidBST(tree);
    printf("%d\n",result?1:0);
    //for ()
    //ListNode * pure = ans.addTwoNumbers(first,second);
    //if(pure == NULL)
    //    printf("NULL");
    //else
    //print(pure);
    return 0;
}



