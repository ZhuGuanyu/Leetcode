/**
 * ID: 83
 * Name: Remove Duplicates from Sorted List
 * Data Structure: Linked List
 * Time Complexity: 
 * Space Complexity: 
 
 * Problem: 
 * Given a sorted linked list, delete all duplicates such that each element appear only once.

 * Solution: 
 * just compare the current point and the next point, then move on

 * What to learn: 
 * Don't forget to check the head is NULL or not !!!!!

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

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head==NULL) // this is very important!!
            return NULL; 
        ListNode* current = head;
        while(current->next!=NULL)
        {
            if(current->val == current->next->val)
            {
                current->next = current->next->next; 
            }
            else
            {
                current = current->next; 
            }
            
        } 
        return head; 
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
    //int a[3] = {1,3,5};
    int b[8] = {1,1,2,2,4,5,6,6};
    ListNode * first = create_list(b,8);
    //ListNode * second = create_list(a,3);
    ListNode * pure = ans.deleteDuplicates(first);
    print(pure);
	return 0;
}



