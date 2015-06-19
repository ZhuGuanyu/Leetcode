/**
 * ID: 101
 * Name: Symmetric Tree
 * Data Structure: 
 * Time Complexity:  
 * Space Complexity: 
 * Tag: Binary Tree
 * Difficult: Easy
 * Algorithm: 

 * Problem: 
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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

/*  This is recursively
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return isMirror(root->left,root->right);
    }
    bool isMirror(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)
            return true;
        if (root1 == NULL || root2 == NULL)
            return false;
        return (root1->val == root2->val ) && isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
    }
};
*/

// We can use the itratively to solve this problem . treat it as level traversal
// 用递归的方法是，在传递参数的时候把东西倒着传递

// 迭代的方法是，左右子树压进去，每次弹两个，注意压入的顺序
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        queue <TreeNode* > q;
        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);
        while(q.size()>=2) {
            TreeNode* point1 = q.front();
            q.pop();
            TreeNode* point2 = q.front();
            q.pop();
            if (point1->val != point2->val)
                return false; 
            if (point1->left != NULL && point2->right != NULL)
            {
                q.push(point1->left);
                q.push(point2->right);
            }
            else if (point1->left == NULL && point2->right != NULL)
                return false;
            else if (point1->left != NULL && point2->right == NULL)
                return false;
                
            if (point2->left != NULL && point1->right != NULL)
            {
                q.push(point2->left);
                q.push(point1->right);
            } 
            else if (point2->left == NULL && point1->right != NULL)
                return false; 
            else if (point2->left != NULL && point1->right == NULL)
                return false;
        }
        if(!q.empty())
            return false;
        return true; 
    }
};




int main()
{
    //vector <int> a = {1,3,5};
	Solution ans;
    //string a[13] = {"5","4","8","11","#","13","4","7","1","#","#","#","1"};
    string a[7] = {"1","2","2","3","4","4","3"};
    string b[13] = {"1","2","3","4","5","#","#","6","7","#","#"};

    TreeNode * tree = constructTree(a,7);
    //TreeNode * tree2 = constructTree(b,11);
    int result = ans.isSymmetric(tree) ? 1:0;
    printf("%d\n",result);

    //for ()
    //ListNode * pure = ans.addTwoNumbers(first,second);
    //if(pure == NULL)
    //    printf("NULL");
    //else
    //print(pure);
    return 0;
}



