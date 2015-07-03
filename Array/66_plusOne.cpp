/**
 * ID: 66
 * Name: plusOne
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 
 * Problem: 
 * Given a non-negative number represented as an array of digits, plus one to the number.
 * The digits are stored such that the most significant digit is at the head of the list.

 * Solution: 
 * Firstly, reverse the array, cause this ask the most significant digit at the head of the list. 
 * So if we want to add a new item when it need carry, we always put the new item at the end the vector using the
 * push_back(), and at last return the reverse() vector. 

 * What to learn: 
 * Remember that the vector.size() is to provide the number of items in the vector. But the capacity() is the 
 * total membery that the system assgin to it. So capacity()-size() equal to the remaining space. 
 * */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(),digits.end());
        int len = digits.size();
        for(int i=0;i<len;i++)
        {
            if(digits[i]==9)
            {
                if(i==len-1)
                {
                    digits[i]=0;
                    digits.push_back(1);
                    break;
                }
                else
                {
                    digits[i]=0;
                }
            }
            else
            {
                digits[i] = digits[i]+1;

                break;
            }
        }

        reverse(digits.begin(),digits.end());
        //cout<<"I am here "<<digits.size()<<endl;
        return digits;
    }
};




int main()
{
	Solution ans;
    int A[]={9,9,9};
    vector<int> example(&A[0],&A[0]+3);
    vector<int> result = ans.plusOne(example);
	cout<<"the newLength is :"<<example.size()<<endl;
    for(int i=0;i<example.size();i++)
        cout<<example[i];
	
	return 0;
}