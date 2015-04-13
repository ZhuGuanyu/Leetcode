/**
 * ID: 24
 * Name: Swap Nodes in Pairs
 * Data Structure: Linked List
 * Time Complexity:  
 * Space Complexity:  
 * Tag: LinkList
 * Difficult: Medium
 
 * Problem: 
 * Given a linked list, swap every two adjacent nodes and return its head.
 * Given 1->2->3->4, you should return the list as 2->1->4->3. 
 * Your algorithm should use only constant space. 
 * You may not modify the values in the list, only nodes itself can be changed.

 * Solution: 
 * ----------> Solution 1:
 * just treate this as reverse function, the difference is just the numbers of swapping.

 *-----------> Solution 2: 
 * using the recursive to solve:
 * as Showing Below:  

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
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *l)
{
    ListNode *head = l;
    while(head!=NULL)
    {
        cout<< head->val<<endl; 
        head = head-> next; 
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

/*
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL || head->next == NULL)
            return head; 
        ListNode * fakeNode = new ListNode(0);
        fakeNode -> next = head; 
        ListNode * pre = fakeNode;
        ListNode * start = pre->next; 
        ListNode * then = start -> next; 
        while(then)
        {
            start -> next = then -> next; 
            then -> next = pre ->next; 
            pre->next = then;
            then = start -> next; 
            pre = start; 
            if(pre->next==NULL)
                break;
            start = start ->next; 
            then = start->next; 
        }
        return fakeNode->next; 
    }
};
*/

// recursive will be a little slower. 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL || head->next == NULL)
            return head; 
        ListNode *next = head->next; 
        ListNode *nextnext = next->next;
        head ->next = this->swapPairs(nextnext);
        next ->next = head; 
        return next; 
    }
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


int main()
{
    //vector <int> a = {1,3,5};
	Solution ans;
    //(2 -> 4 -> 3) + (5 -> 6 -> 4)
    int a[4] = {1,2,3,4};
    int b[1] = {1};
    ListNode * first = create_list(a,4);
    ListNode * second = create_list(b,1);
    ListNode * pure = ans.swapPairs(first);
    if(pure == NULL)
        printf("NULL");
    else
    print(pure);
	return 0;
}



