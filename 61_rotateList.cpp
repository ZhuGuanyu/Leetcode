/**
 * ID: 61
 * Name: Rotate List
 * Data Structure: Linked List
 * Time Complexity:  
 * Space Complexity:  
 * Tag: LinkList
 * Difficult: Medium
 
 * Problem: 
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * Given 1->2->3->4->5->NULL and k = 2
 * return 4->5->1->2->3->NULL.

 * Solution: 
 * The idea of solution is very similar to the the rotate array. 
 * use a new reverse function and reverse the (0,n-k),(n-k,n), then combine them and reverse all the link.
 
 * =======================>>>>> Another Easy solution: 
 * Because this is the Link, so we can connect the tail to the head. So we can directly focus on which is the 
 * result head for the new link, then we split it from the beginning. 


 * What to learn: 
 * For the link, we should consider the circle that we can use for our purpuse. 

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

/*
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || head->next == NULL)
            return head; 
        int length = 0;
        ListNode *p = head; 
        while(p)
        {
            length++;
            p = p -> next; 
        }
        k = k%length; 
        if (k==0)
            return head; 
        int cnt = length - k -1; 
        ListNode *first, *second; 
        first = p = head; 
        while(cnt)
        {
            cnt --;
            p = p->next; 
        }
        second = p->next; 
        p -> next = NULL; 
        first = reverseList(first);
        second = reverseList(second);
        p = first; 
        while(p->next)
        {
            p = p->next; 
        }
        p -> next = second; 
        head = reverseList(first);
        return head; 
    }
    ListNode *reverseList(ListNode *head)
    {
        ListNode * fakeNode = new ListNode(0);
        ListNode *cur, *pre;
        fakeNode -> next = cur = head;
        pre = fakeNode; 

        while(cur)
        {
            ListNode *temp = cur;  // choose a tempary variable and store the current pointer
            cur = cur -> next;  
            temp -> next = pre;   // change the current pointer to point the former one. 
            pre = temp; 
        }
        delete cur; 
        delete fakeNode;
        head ->next = NULL; 
        return pre; 
    }
};
*/


// A new and better solution! 
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || head->next == NULL)
            return head; 
        ListNode * p = head; 
        int length = 1;
        while(p->next)
        {
            length ++;
            p = p->next; 
        }
        if(k==0)
            return head;
        p->next = head; 
        k = k%length;
        int cnt = length - k -1; 
        p = head; 
        while(cnt)
        {
            cnt --;
            p = p->next; 
        }
        head = p -> next; 
        p -> next = NULL ; 
        return head; 
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
    int b[2] = {1,2};
    ListNode * first = create_list(b,2);
    //ListNode * second = create_list(a,3);
    ListNode * pure = ans.rotateRight(first,0);
    if(pure == NULL)
        printf("NULL");
    else
    print(pure);
	return 0;
}



