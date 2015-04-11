/**
 * ID: 19
 * Name: Remove Nth Node From End of List
 * Data Structure: Linked List
 * Time Complexity:  
 * Space Complexity:  
 * Tag: LinkList
 * Difficult: Easy
 
 * Problem: 
 * Given a linked list, remove the nth node from the end of list and return its head.
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Try to do this in one pass

 * Solution: 
 * 1 -->
 * just run one pass to get the length of the list ,then caculate the position from the beginning. 
 * then delete that item. 
 * 2 -->
 * Use one vector to store the every Node, then we can use the index in the array to operate the link
 * list directly. 

 * What to learn: 
 * When to consider give some cur->next value, firstly you should consider the original value maybe NULL.

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
         
        ListNode *fakenode = new ListNode(0);
        fakenode->next = head; 
        int length = 0;
        ListNode * p = fakenode; 
        while(p)
        {
            length++;
            p = p->next; 
        }
        length--;
        delete p;
        int cnt = length-n;
        ListNode *cur = fakenode;
        while(cnt)
        {
            cur=cur->next; 
            cnt --;
        }
        if(cur->next)
            cur->next = cur->next->next; 
        return fakenode->next; 
    }
};
*/
//second solution
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL)
            return NULL; 
         
        std::vector<ListNode *> v;
        ListNode *p = head; 
        while(p)
        {
            v.push_back(p);
            p = p->next;
        } 
        //cout<<v.size();
        int position = v.size() - n; 
        if(position == 0)
            return v[position]->next;
        else if(position == v.size()-1)
            v[position-1]->next = NULL;
        else
            v[position-1]->next = v[position]->next;
        return v[0];

    }
};

// the third solution
class RemoveNthNodeFromEndofList {
public: ListNode *removeNthFromEnd(ListNode *head, int n) {
        if( head == NULL ) {
            if( n == 0 )
                return head;
        }
        if( head->next == NULL ) {
            if( n == 1 )
                head = NULL;
            return head;
        }       
        ListNode* EndPointer = head;
        ListNode* Pre = new ListNode(-1); 
        Pre->next = head;
        ListNode* Cur = head;
        int DistanceToEnd = 0;
        while( EndPointer != NULL ) {
            //cout<<"DistanceToEnd: "<<DistanceToEnd<<" EndPointer->val: "<<EndPointer->val<<endl;
            if( DistanceToEnd == n ) {
                Pre = Cur;
                Cur = Cur->next;
            }
            else 
                DistanceToEnd++;
            EndPointer = EndPointer->next;           
        }
        if( Cur == head ) 
            head = Cur->next;
        else
            Pre->next = Cur->next;
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
	RemoveNthNodeFromEndofList ans;
    //int a[3] = {1,3,5};
    int b[8] = {1,2,3,4,5,6,7,8};
    ListNode * first = create_list(b,8);
    //ListNode * second = create_list(a,3);
    ListNode * pure = ans.removeNthFromEnd(first,2);
    if(pure == NULL)
        printf("NULL");
    else
    print(pure);
	return 0;
}



