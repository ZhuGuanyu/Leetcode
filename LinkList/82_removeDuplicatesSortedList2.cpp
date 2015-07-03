/**
 * ID: 82
 * Name: Remove Duplicates from Sorted List 2
 * Data Structure: Linked List
 * Time Complexity:  O(n)
 * Space Complexity:  O(n)
 * Tag: LinkList
 
 * Problem: 
 * Given a sorted linked list, delete all nodes that have duplicate numbers
 * leaving only distinct numbers from the original list.

 * Solution: 
 * Compare the current position with the previous and behind it. If it does not equal to them, then we add it to the 
 * new List. 

 * What to learn: 
 * Beware that if the list is NULL or there are only one item in the list, they are specific situation. 
 * Another good solution: 
 * Add a dummy node before the head, and to check if the node is first one that duplicate with others, if it does, then
 * at the following step, delete it. Remember to delete the unused item if you really want to delete it. 
 * To refer : http://bangbingsyb.blogspot.com/2014/11/leetcode-remove-duplicates-from-sorted_19.html

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


class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head; 

        int flag = 0;
        ListNode * newhead,* p, *pre;
        newhead = p = pre = head;
        int prevalue = p->val;

        while(p!=NULL)
        {
            if((p!=newhead && prevalue==p->val)||( p->next!=NULL && p->val==p->next->val)) // consider the regular situation. 
            {
                prevalue = p->val;
                p = p->next;

            }
            else
            {
                if(flag == 0)  // consider the newhead.
                    newhead = p;                     
                flag = 1; 
                prevalue = p->val;
                if(p != head)
                {
                    pre -> next = p; 
                    pre = pre->next;
                } 

                p = p->next;
            }    
            
        }
        if(flag == 0)
            return NULL; 
        pre ->next = NULL; 
        delete(p);      
        return newhead; 
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
    //int a[3] = {1,3,5};
    int b[2] = {1,1};
    ListNode * first = create_list(b,2);
    //ListNode * second = create_list(a,3);
    ListNode * pure = ans.deleteDuplicates(first);
    if(pure == NULL)
        printf("NULL");
    else
    print(pure);
	return 0;
}



