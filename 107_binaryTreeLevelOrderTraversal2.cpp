/**
 * ID: 107
 * Name: Binary Tree Level Order Traversal ii
 * Data Structure: 
 * Time Complexity:  
 * Space Complexity: 
 * Tag: Binary Tree
 * Difficult: Easy
 * Algorithm: 

 * Problem: 

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]



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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > v;
        vector<int> level;
        if (root == NULL)
            return v; 
        if (root ->left == NULL && root ->right == NULL)
        {
            level.push_back(root->val);
            v.push_back(level);
            return v; 
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *trail,*cur; // trail record the last item in each level
        trail = cur = root; 
        
        while(!q.empty())
        {
            TreeNode* pointer = q.front();
            q.pop();
            level.push_back(pointer->val);
            if (pointer->left != NULL)
            {
                cur = pointer->left;
                q.push(pointer->left);
            }
            if (pointer->right != NULL)
            {
                cur = pointer->right;
                q.push(pointer->right);
            }
            if (pointer == trail)
            {
                trail = cur;
                v.push_back(level);
                level.clear();
            }    
        }
        reverse(v.begin(),v.end());
        return v;       
    }
};

// other people's method, we can use the NULL as the marker to mark the tail of the level 
/*
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> >  result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> cur_vec;
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t==NULL) {
                result.push_back(cur_vec);
                cur_vec.resize(0);
                if (q.size() > 0) {
                    q.push(NULL);
                }
            } else {
                cur_vec.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return result;
    }
};
*/

// or we can also use the preorder recursive method
/*
vector<vector<int>> ret;

void buildVector(TreeNode *root, int depth)
{
    if(root == NULL) return;
    if(ret.size() == depth)
        ret.push_back(vector<int>());

    ret[depth].push_back(root->val);
    buildVector(root->left, depth + 1);
    buildVector(root->right, depth + 1);
}

vector<vector<int> > levelOrder(TreeNode *root) {
    buildVector(root, 0);
    return ret;
}
*/




int main()
{
    //vector <int> a = {1,3,5};
	Solution ans;
    //string a[13] = {"5","4","8","11","#","13","4","7","1","#","#","#","1"};
    string c[1] = {"1"};
    string a[7] = {"1","2","3","4","5","6","7"};
    string b[11] = {"1","2","3","4","5","#","#","6","7","#","#"};

    TreeNode * tree = constructTree(a,7);
    //TreeNode * tree2 = constructTree(b,11);
    vector<vector<int> > result = ans.levelOrderBottom(tree);

    for (int i=0;i<result.size();i++)
    {
        std::vector<int> temp = result[i];
        for (int j=0;j<temp.size();j++)
        {
            cout<<temp[j]<<" ";
        }
        cout<<endl;
    }
    //for ()
    //ListNode * pure = ans.addTwoNumbers(first,second);
    //if(pure == NULL)
    //    printf("NULL");
    //else
    //print(pure);
    return 0;
}



