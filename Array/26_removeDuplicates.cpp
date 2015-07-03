/**
 * ID: 26
 * Name: removeDuplicates
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 
 * Solution: 
 * caculate the total number of duplicates before every item, then the new
 * position for this item is Pos-cnt; then change its position. 

 * What to learn: 
 * If it ask to complete in constant memory, then you should use only O(n) time, and 
 * don't need to think of chaning all the positions for each caculation. 

 * */





#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	int newLength = n;
    	int cnt = 0; 
        for (int i=0;i<n-1;i++)
        {
        	if(A[i]==A[i+1])
        	{
        		newLength--;
        		cnt ++ ;
        	}
        	A[i+1-cnt]=A[i+1];
        }
        return newLength; 
    }
};

int main()
{
	Solution ans;
	int A[]={0,0,0};
	int answer = ans.removeDuplicates(A,sizeof(A)/sizeof(*A));
	cout<<"the newLength is :"<<answer<<endl;
	cout<<"the new array is :"<<endl;
	for(int i=0;i<answer;i++)
		cout<<A[i]<<" ";
	return 0;
}