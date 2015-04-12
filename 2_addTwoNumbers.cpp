/**
 * ID: 2
 * Name: Add Two Numbers
 * Data Structure: Linked List
 * Time Complexity:  
 * Space Complexity:  
 * Tag: LinkList
 * Difficult: Medium
 
 * Problem: 
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8

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
// Another new method!!!
// Using a new List, and to check if the l1 l2 and carry is not NULL. 
// Add the value separately
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0), *p = dummy;
        int carry = 0;
        while(l1 || l2 || carry) {
            if(l1) {
                carry+=l1->val;
                l1 = l1->next;
            }
            if(l2) {
                carry+=l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(carry%10); // every time create a new node. 
            carry /= 10;
            p = p->next;
        }
        return dummy->next;
    }
};


/*
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)
            return l2; 
        if(l2 == NULL)
            return l1; 

        ListNode *fakeNode1 = new ListNode(0);
        ListNode *fakeNode2 = new ListNode(0);
        fakeNode1 -> next = l1; 
        fakeNode2 -> next = l2; 
        ListNode *p1 = fakeNode1; 
        ListNode *p2 = fakeNode2; 
        int carry = 0;
        int sum = 0;

        while(p1->next && p2->next)
        {
            p1 = p1->next; 
            p2 = p2->next;
            sum = carry + p1->val + p2->val;
            carry = sum/10;
            p1->val = sum%10;  
             
        }
        
        if(p1->next==NULL && p2->next!=NULL)
        {
            p1->next = p2->next; 
        }
        delete p2;
        delete fakeNode2; 
        while(p1->next)
        {
            p1 = p1->next; 
            sum = carry + p1->val ;
            carry = sum/10;
            p1->val = sum%10;
        }
       if(carry!=0)
        {
            ListNode *last = new ListNode(carry);
            p1->next = last;              
        }  
        return fakeNode1->next; 
    }
};
*/


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
    int a[4] = {9,9,9,9};
    int b[1] = {1};
    ListNode * first = create_list(a,4);
    ListNode * second = create_list(b,1);
    ListNode * pure = ans.addTwoNumbers(first,second);
    if(pure == NULL)
        printf("NULL");
    else
    print(pure);
	return 0;
}



