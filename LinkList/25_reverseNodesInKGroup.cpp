/**
 * ID: 25
 * Name: Reverse Nodes in K-Group
 * Data Structure: Linked List
 * Time Complexity:  
 * Space Complexity:  
 * Tag: LinkList
 * Difficult: Hard
 
 * Problem: 
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is. 
 * You may not alter the values in the nodes, only nodes itself may be changed. 

 * Only constant memory is allowed.
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5

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

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        
        if(head == NULL || head->next == NULL || k<2)
            return head; 
        
        ListNode * fakeNode = new ListNode(0);
        fakeNode -> next = head; 
        ListNode * p = head; 
        int length = 0;
        while(p)
        {
            length++;
            p = p->next; 
        }
        if(k>length)
            return fakeNode->next; 
        ListNode * pre = fakeNode;
        ListNode * start = pre->next; 
        ListNode * then = start ->next;

        int total = 0;
        int cnt = 0;
        while(then!=NULL) 
        {
            while(cnt!=k-1 && then)
            {
                cnt ++;
                start->next = then->next; 
                then->next = pre->next; 
                pre->next = then; 
                then = start->next; 
            }
            total ++;
            if(total == length/k) //可以用for循环代替
                break;
            pre = start; 
            start = pre->next; 
            then = start->next; 
            cnt =0;
        }
        return fakeNode->next; 
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
    int a[2] = {1,2};
    int b[1] = {1};
    ListNode * first = create_list(a,2);
    ListNode * second = create_list(b,1);

    ListNode * pure = ans.reverseKGroup(first,3);
    if(pure == NULL)
        printf("NULL");
    else
    print(pure);
	return 0;
}



