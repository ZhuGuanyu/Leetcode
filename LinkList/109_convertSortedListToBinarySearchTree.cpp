/**
 * ID: 109
 * Name: Convert Sorted List to Binary Search Tree
 * Data Structure: 
 * Time Complexity: nlog(n)(first) O(n)(second)
 * Space Complexity: 
 * Tag: Tree
 * Difficult: Medium
 * Algorithm: 
 
 * Problem: 
 * Given a singly linked list where elements are sorted in ascending order, 
 * convert it to a height balanced BST.

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
    ListNode(int x) : val(x), next(NULL) {}
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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL)
            return NULL;
        ListNode *p = head; 
        TreeNode *root = new TreeNode(head->val);

        if(head->next == NULL)
            return root; 
        int length = 0;
        while(p)
        {
            length ++;
            p = p->next; 
        }

        ListNode *fakeHead = new ListNode(0);
        fakeHead->next = head; 
        ListNode * p1 = head; 
        ListNode * pre = fakeHead;
        int mid = 1;
        while(mid != (length+1)/2)
        {
            mid++;
            pre = pre->next; 
            p1 = p1->next; 
        }
        pre->next = NULL;
        root->val = p1->val; 
        ListNode *first = head; 
        ListNode *second = p1->next; 
        p1->next = NULL;
        
        root->right = sortedListToBST(second);
        p1->next = NULL;
        if(length>=3)
            root->left = sortedListToBST(first);
        return root;   
    }
};

/*
// second solution 
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int listLen = 0;
        ListNode *cur = head;
        while(cur) {
            listLen++;
            cur = cur->next;
        }
        return sortedListToBST(head, 0, listLen-1);
    }
    
    TreeNode *sortedListToBST(ListNode *&head, int start, int end) {
        if(start>end) return NULL;
        int mid = start + (end-start)/2;
        TreeNode *leftChild = sortedListToBST(head, start, mid-1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        TreeNode *rightChild = sortedListToBST(head, mid+1, end);
        root->left = leftChild;
        root->right = rightChild;
        return root;
    }
};
*/

int main()
{
    //vector <int> a = {1,3,5};
	Solution ans;
    string a[13] = {"5","4","8","11","#","13","4","7","1","#","#","#","1"};

    int b[8] = {1,2,3,4,5,6,7,8};
    ListNode * first = create_list(b,8);
    TreeNode * result = ans.sortedListToBST(first);
    print(result);

    //for ()
    //ListNode * pure = ans.addTwoNumbers(first,second);
    //if(pure == NULL)
    //    printf("NULL");
    //else
    //print(pure);
    return 0;
    }



