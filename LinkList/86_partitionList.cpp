/**
 * ID: 86
 * Name: Partition List
 * Data Structure: Linked List
 * Time Complexity:  
 * Space Complexity:  
 * Tag: LinkList
 * Difficult: Medium
 
 * Problem: 
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes 
 * greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.

 * Solution: 
 * ---> Solution1: 
 * Use to vector to store the two partitions, smaller values store in one vector, and then combine them. 
 * ---> Solution 2: 
 * Just use the two new list to store the partitions.  



 * What to learn: 
 * refer to the Blogs. 

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
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL)
            return head; 

        std::vector<ListNode*> v1,v2;
        int cnt,length;
        length = 0;
        ListNode * p = head; 
        while(p)
        {
            if(p->val < x)
                v1.push_back(p);
            else
                v2.push_back(p);
            p = p->next;
            length ++; 
        }
        
        for (int i=0;i<v2.size();i++)
            v1.push_back(v2[i]);

        ListNode *newhead; 
        newhead = p = v1[0];

        for(int i=0;i<length-1;i++)
            v1[i]->next = v1[i+1];
        v1[length-1]->next = NULL; 
        return newhead; 
    }
};
*/

//New Solution: we can use two Lists to store the partitions separately. 
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL)
            return head; 

        ListNode * p = head; 

        ListNode *head1, *p1, *head2, *p2; 
        int flag1, flag2; 
        flag1 = flag2 = 0;
        while(p)
        {
            if(p->val < x)
            {
                if(flag1 == 0)
                {
                    flag1 = 1;
                    p1 = head1 = p; 
                }
                else
                {
                    p1 ->next = p;
                    p1 = p1->next; 
                }
            }
                
            else
            {
                if(flag2 == 0) // 使用这种方法来判断头，还不如插入个 fakenode来的方便. 
                {
                    flag2 = 1;
                    p2 = head2 = p; 
                }
                else
                {
                    p2 ->next = p;
                    p2 = p2->next; 
                }
            }
            p = p->next;
        }
        if(flag1 == 0)
        {
            p2 -> next =NULL;
            return head2; 
        }
        if (flag2 == 0)
        {
            p1 -> next = NULL; 
            return head1; 
        }
        p1->next = head2; 
        p2 -> next = NULL;
        ListNode *newhead; 
         
        return head1; 
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
    //1->4->3->2->5->2
    int b[4] = {1,2,3,4};
    ListNode * first = create_list(b,4);
    //ListNode * second = create_list(a,3);
    ListNode * pure = ans.partition(first,0);
    if(pure == NULL)
        printf("NULL");
    else
    print(pure);
	return 0;
}



