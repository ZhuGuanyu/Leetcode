/**
 * ID: 117
 * Name: Populating Next Right Pointers in Each Node 2
 * Data Structure: 
 * Time Complexity:  O(logN)
 * Space Complexity: 
 * Tag: Tree
 * Difficult: Medium
 * Algorithm: 

 * Problem: 
 Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

 * Solution: 
 

 *******************************************
 very important
 The problem states that you can only use constant space. To get to the leaf nodes, 
 a recursive solution needs to be log2(n) calls deep, and each call has a call stack, 
 which takes up memory. This means that a recursive solution isn't constant memory, 
 but O(log(n)) memory. To solve this, 
 you just replace the recursive call with a while loop wrapping all of your logic.

 2. 方法二只用了一个 空间
 有一个 p 负责父节点的横向走, current 是负责子节点的链接问题，要先确定第一个子节点和非第一个子节点
 因为这个没有最左边的子节点
 
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
        TreeLinkNode * current = root;
        int flag = 0;
        while (root ->left || root ->right || root->next)
        {
            p = root; 
            flag = 0;
            while(p!=NULL)
            {
                if(p->left == NULL && p->right == NULL)
                {
                    p = p -> next;
                    continue; 
                }
                else 
                {
                    if (flag == 0)
                    {
                        current = p->left ? p->left:p->right; 
                        if (p->left != NULL && p->right != NULL)
                        {
                            current ->next = p ->right ;
                            current = current ->next ; 
                        }
                        flag = 1;
                    }
                    else 
                    {
                        if(p->left && p->right)
                        {
                            current ->next = p->left; 
                            p->left ->next = p -> right;
                            current = p->right; 
                        }
                        else if(p->left!=NULL && p->right==NULL)
                        {
                            current ->next = p->left; 
                            current = p->left; 
                        }
                        else 
                        {
                            current ->next = p->right; 
                            current = p->right; 
                        }
                    }
                }  
                p = p->next;
            }
            if (root -> left)
                root = root ->left; 
            else if (root ->right)
                root = root ->right; 
            else if(root ->next)
                root = root ->next; 
        }
    }
};



int main()
{
    //vector <int> a = {1,3,5};
	Solution ans;
    //string a[13] = {"5","4","8","11","#","13","4","7","1","#","#","#","1"};
    string a[7] = {"1","2","3","4","#","#","7"};

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



