/**
 * ID: 94
 * Name: Binary Tree Inorder Traversal
 * Data Structure: 
 * Time Complexity:  
 * Space Complexity: 
 * Tag: Binary Tree
 * Difficult: Medium
 * Algorithm: 

 * Problem: 
 Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

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
#include <queue>
#include <stack>
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
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == NULL)
            return v;
        if (root->left == NULL && root ->right == NULL)
        {
            v.push_back(root->val);
            return v; 
        }
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);

        v.insert(v.end(), left.begin(), left.end());
        v.push_back(root->val);
        v.insert(v.end(), right.begin(), right.end());

        return v; 
    }
};
*/
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == NULL)
            return v; 
        TreeNode * p = root; 
        stack<TreeNode*> s; 
        while(p)
        {
            while(p) //把左边的树一直压进去
            {
                s.push(p);
                p = p->left; 
            }
            while (!s.empty()) // 弹出一个点，看有没有右孩子，有的话，拿出来作为根来遍历
            {
                TreeNode * cur = s.top();
                s.pop();
                v.push_back(cur->val);
                if(cur->right)
                {
                    p = cur->right;
                    break;
                }
            }
        }
        return v; 
    }
};
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> v;
        if (root == NULL)
            return v; 
        if (root ->left == NULL && root -> right == NULL ) {
            v.push_back(root->val);
            return v; 
        } 
        stack <pair<TreeNode*, int> > s;
        s.push(make_pair(root,0));
        while(!s.empty())
        {
            TreeNode * p = s.top().first;
            int index = s.top().second; 
            s.pop();
            if (!index)
            {
                if(p->right)
                    s.push(make_pair(p->right,0));
                s.push(make_pair(p,1));
                if(p->left)
                    s.push(make_pair(p->left,0));
            } else {
                v.push_back(p->val);
            }
        } 
        return v; 
    }
};


int main()
{
    //vector <int> a = {1,3,5};
	Solution ans;
    //string a[13] = {"5","4","8","11","#","13","4","7","1","#","#","#","1"};
    string a[11] = {"1","2","3","4","5","#","#","6","#","#","#"};
    string b[11] = {"1","2","3","4","5","#","#","6","7","#","#"};
    string c[4] = {"1","#","2","3"};

    TreeNode * tree = constructTree(b,11);
    std::vector<int> result = ans.inorderTraversal(tree);
    for(int i = 0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
    }



