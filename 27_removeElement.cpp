/**
 * ID: 27
 * Name: removeElement
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 
 * Solution: 
 * caculate the total number of same value provided before every item, then the new
 * position for this item is Pos-cnt; then change its position. 

 * What to learn: 
 * If it ask to complete in constant memory, then you should use only O(n) time, and 
 * don't need to think of chaning all the positions for each caculation. 

 * */

#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(A[i]==elem)
                cnt++;
            else
            A[i-cnt] = A[i]; 
        }
        return n-cnt; 
    }
};





int main()
{
	Solution ans;
	int A[]={0,0,0,1,2,3,4,0,5,0};
	int answer = ans.removeElement(A,sizeof(A)/sizeof(*A),0);
	cout<<"the newLength is :"<<answer<<endl;
	cout<<"the new array is :"<<endl;
	for(int i=0;i<answer;i++)
		cout<<A[i]<<" ";
	return 0;
}