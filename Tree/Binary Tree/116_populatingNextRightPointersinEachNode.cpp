/**
 * ID: 116
 * Name: Populating Next Right Pointers in Each Node
 * Data Structure: 
 * Time Complexity:  O(logN)
 * Space Complexity: 
 * Tag: Tree
 * Difficult: Medium
 * Algorithm: recursion

 * Problem: 
 Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

 * Solution: 
 1. This is not "You may only use constant extra space" 
 * 如果是递归的 dfs 那么一般步骤是 ： 
 1. 先判断返回或是异常条件 
 2. 做一些逻辑上的判断
 3. 基本是 左右子树的判断

 *******************************************
 very important
 The problem states that you can only use constant space. To get to the leaf nodes, 
 a recursive solution needs to be log2(n) calls deep, and each call has a call stack, 
 which takes up memory. This means that a recursive solution isn't constant memory, 
 but O(log(n)) memory. To solve this, 
 you just replace the recursive call with a while loop wrapping all of your logic.

 2. 方法二只用了一个 空间
 有一个 p 负责父节点的横向走
 然后始终维持着最左边的点
 
 * What to learn: 
 * 

 * Note: to ask the interviewer the number maybe too large that the int maybe invalid.

/**
 * Definition for a binary tree node.
 * struct TreeLinkNode {
 *     int val;
 *     TreeLinkNode *left;
 *     TreeLinkNode *right;
 *     TreeLinkNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/


#include <iostream>
#include <list>
#include <queue>
 using namespace std;


struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
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

TreeLinkNode *constructTree(string *dat , int len)
{
    if(dat == NULL)
        return NULL;
    TreeLinkNode *root = NULL;
    int index = 0;
    if(len > 0)
        root = new TreeLinkNode(stoi(dat[index]));
    else
        return NULL;
    list<TreeLinkNode *> node; //其实相当于 queue
    node.push_back(root);
    index ++;
    while(index < len)
    {
        if(!node.empty())
        {
            TreeLinkNode *root = node.front();
            if(index < len )
            {
                if(dat[index].compare("#") != 0)
                {
                  root->left = new TreeLinkNode(stoi(dat[index]));    
                  node.push_back(root->left);
                }
                index ++;
            }
            if(index < len )
            {
                if(dat[index].compare("#") != 0)
                {
                  root->right = new TreeLinkNode(stoi(dat[index]));   
                  node.push_back(root->right);
                }
                index ++;
            }
            node.pop_front();
        }
    }
    return root;
}

void print(TreeLinkNode * root)
{
    if(root == NULL)
        return ;
    queue <TreeLinkNode *> q;
    q.push(root);
    while(!q.empty())
    {
        TreeLinkNode *cur =  q.front();
        cout<< cur->val; 
        q.pop();
        if(cur -> left) q.push(cur->left);
        if(cur -> right) q.push(cur->right);
    }
}


void printleft(TreeLinkNode * root)
{
    if (root == NULL)
        return;
     TreeLinkNode *p = root; 
    while(p)
    {
        printf("%d -> ",p->val);
        p = p->next; 
    }
    cout<<endl;
    printleft(root->left);
}


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 /*
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        if (root->right == NULL && root ->left == NULL)
            return; 
        root->left ->next = root -> right; 
        if(root->next != NULL && root->next->left != NULL)
            root->right ->next = root ->next ->left;
        connect(root->left);
        connect(root->right);
        
    }
};
*/


class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        if (root->right == NULL && root ->left == NULL)
            return;
        TreeLinkNode * p = root;
        while (root ->left)
        {
            p = root; 
            while(p!=NULL)
            {
                p->left ->next = p -> right;
                if (p->next != NULL)
                    p->right ->next = p ->next ->left;
                p = p->next;
            }
            root = root -> left;
        }
    }
};



int main()
{
    //vector <int> a = {1,3,5};
	Solution ans;
    //string a[13] = {"5","4","8","11","#","13","4","7","1","#","#","#","1"};
    string a[7] = {"1","2","3","4","5","6","7"};

    TreeLinkNode * tree = constructTree(a,7);
    ans.connect(tree);
    printleft(tree);

    //for ()
    //ListNode * pure = ans.addTwoNumbers(first,second);
    //if(pure == NULL)
    //    printf("NULL");
    //else
    //print(pure);
    return 0;
    }



