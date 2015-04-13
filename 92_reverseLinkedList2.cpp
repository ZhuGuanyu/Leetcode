/**
 * ID: 92
 * Name: Reverse Linked List
 * Data Structure: Linked List
 * Time Complexity:  
 * Space Complexity:  
 * Tag: LinkList
 * Difficult: Medium
 
 * Problem: 
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4. 
 * return 1->4->3->2->5->NULL.
 * Given m, n satisfy the following condition
 * 1 ≤ m ≤ n ≤ length of list

 * Solution: 
 * -------> Solution 1
 * General it's easy that we use the vector to deal with the linklist movement problem.
 * -------> Solution 2
 * just reverse the item from m to n. the difference is just the method. 
 * below provided the very easy way to do it. 
  

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m==n || head == NULL)
            return head; 
        std::vector<ListNode *> v;
        ListNode *p = head; 
        while(p)
        {
            v.push_back(p);
            p = p->next; 
        }
        int len = (n-m)/2+1;
        for(int i=0; i< len;i++)
        {
            ListNode * temp = v[i+m-1];
            v[i+m-1] = v[n-i-1];
            v[n-i-1] = temp; 
            
        }
        for(int i=0;i<v.size()-1;i++)
            v[i]->next = v[i+1];
        v[v.size()-1] ->next = NULL;
        return v[0];
    }
};
*/
/*
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m==n || head == NULL)
            return head; 
        ListNode *fakeNode = new ListNode(0);
        ListNode *first, *last, *pre,*cur; 
        fakeNode -> next = cur = head;
        pre = fakeNode;
        int cnt = 0; 
        int flag = 0;
        while(pre->next)
        {
            //cout<< " I am here "<<pre->val<<" "<<cnt<<endl;
            cnt ++;
            if((m==1&&cnt==1) || cnt == m)
            {
                first = pre; 
                cur = cur->next;
                pre = pre->next; 
            }
                
            else if(cnt >=m && cnt<=n)
            {
                if (cnt == n)
                { 
                    last = first -> next;
                    first -> next = cur;
                    //cout<<" "<<first->val <<" "<<cur->val<<endl;
                    if(cur->next == NULL)
                    {
                        flag =1;
                        last -> next=NULL;
                        //break;
                    }
                }
                ListNode * temp = cur;
                
                if(cur->next != NULL)
                    cur = cur->next; 
                temp->next = pre;
                pre = temp; 
                if(flag)
                    break;
            }
            else if(cnt == n+1)
            {
                 last -> next = cur;
                 //cout<<" "<<last->val<<" "<<cur->val<<endl;
                 pre = cur; 
                 cur = cur->next;
                  
                 //cout<<"**** "<<pre->val<<endl;
            }
            else
            {
                pre = cur; 
                cur = cur->next; 
                
            }
        }
        //cout<<"&&&&  "<<cnt<<endl;
        if(cnt == n)
        {
             last -> next = NULL;
            
        }

        return fakeNode->next; 
        
    }
};
*/
// very good 
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        //make a head by myself
        ListNode *newHead=new ListNode(0);
        newHead->next=head;
        ListNode *p0=newHead;
        ListNode *p1=nullptr,*p2=nullptr;
        int i;
        //find position of p0
        for(i=1;i<m;i++)
            p0=p0->next;
        p1=p0->next;
        //reverse one by one
        while(i<n)
        {
            p2=p1->next;
            p1->next=p2->next;
            p2->next=p0->next;
            p0->next=p2;
            i++;
        }

        // p is the true head

        ListNode *p=newHead->next;
        delete newHead;
        return p;
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
    int a[5] = {1,2,3,4,5};
    int b[1] = {1};
    ListNode * first = create_list(a,5);
    ListNode * second = create_list(b,1);
    ListNode * pure = ans.reverseBetween(first,2,5);
    if(pure == NULL)
        printf("NULL");
    else
    print(pure);
	return 0;
}



