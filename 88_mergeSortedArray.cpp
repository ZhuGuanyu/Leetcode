/**
 * ID: 88
 * Name: mergeSortedArray
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 
 * Problem: 
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 * Note:
 * You may assume that A has enough space (size that is greater or equal to m + n) to 
 * hold additional elements from B. The number of elements initialized in A and B are m 
 * and n respectively.

 * Solution: 
 * We can don't need extra space to store the data. Because the A array has lots of empty space, so
 * we can store our new array from the end to the begin in the origin A array. 

 * What to learn: 
 * When we don't need extra space, to figure out where the space is empty and we can put our data there
 * */

#include <iostream>
using namespace std;

/* Good method (don't need new array) */

class Solution {
public:
    void merge(int A[], int m, int B[], int n){
        int newLength = m + n -1;
        int pointA = m -1;
        int pointB = n -1; 

        for (int i=newLength;i>=0;i--)
        {
            if(pointA>=0 && pointB>=0)
            {
                if (A[pointA]>B[pointB])
                    A[i] = A[pointA--];
                else 
                    A[i] = B[pointB--];
            }
            else if(pointB >=0)
            {
                A[i] = B[pointB--];
            }
        }
    }

};


/*  stupid method 
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int newArray[m+n+5];
        memset(newArray,0,sizeof(newArray));
        int pointA=0;
        int pointB=0;
        int cnt = 0 ;
        while(cnt < m+n)
        {

            if(pointA<m && pointB<n)
            {
                if(A[pointA]>B[pointB])
                {
                    newArray[cnt++] = B[pointB++];
                }
                else
                    newArray[cnt++] = A[pointA++];
            }
            else if(pointA == m)
            {
                newArray[cnt++] = B[pointB++];

            }
            else if(pointB == n)
            {
                newArray[cnt++] = A[pointA++];
            }  
        }
        for(int i=0;i<cnt;i++)
            A[i]=newArray[i];
    }
};
*/



int main()
{
	Solution ans;
    int A[50]={1,3,5,6,7,8,9,10};
    int B[]={2,4,6};
    ans.merge(A,8,B,3);
    for(int i=0;i<11;i++)
        cout<<A[i]<<" ";
	
	return 0;
}