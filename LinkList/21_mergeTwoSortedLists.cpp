/**
 * ID: 21
 * Name: Merge Two Sorted Lists
 * Data Structure: Linked List
 * Time Complexity: 
 * Space Complexity: 
 
 * Problem: 
 * Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first two lists.

 * Solution: 
 * Firstly, if the two lists have items which not added to the newList, then compared each other
 * and choose the smallest one to add. Then add the remaining lists to the new list.  

 * What to learn: 
 * How to merge two links and for the c++, how to init
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

/*
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *newList, *newNode,*current; 
        ListNode *head1 = l1;
        ListNode *head2 = l2;
        if (l1==NULL)
            return l2;
        else if (l2==NULL)
            return l1;
        if(head1 -> val >= head2->val)
        {
            newList = current = new ListNode(head2->val);
            head2 = head2->next;

        }
        else
        {
            newList = current = new ListNode(head1->val);
            head1 = head1 ->next;
        }

        while(head1 && head2)
        {
            if(head1 -> val >= head2->val)
            {
                newNode = new ListNode(head2->val);
                head2 = head2 -> next;
                current ->next = newNode; 

            }
            else
            {
                newNode = new ListNode(head1->val);
                head1 = head1 -> next; 
                current ->next = newNode; 
            }
            current = current -> next;
        }
        if(head1==NULL)
        {
            current ->next = head2;
        }
        else
            current ->next = head1; 
        return newList;
    }
};
*/


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *newList = new ListNode(-1);
        ListNode *current = newList;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                current->next = l1;
                l1 = l1 -> next; 
            }
            else
            {
                current->next = l2;
                l2 = l2 -> next; 
            }
            current = current -> next; 
        }
        current->next = l1? l1:l2;
        return newList->next; 
    }
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
    int a[3] = {1,3,5};
    int b[2] = {2,4};
    ListNode * first = create_list(b,2);
    ListNode * second = create_list(a,3);
    ListNode * merge = ans.mergeTwoLists(first,second);
    print(merge);
	return 0;
}



