/**
 * ID: 189
 * Name: rotateArray
 * Time Complexity: 
 * Space Complexity: 
 
 * Problem: 
 * Rotate an array of n elements to the right by k steps.
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 * Could you do it in-place with O(1) extra space?

 * Solution: 
 * We should firstly check if the K is larger than n, and then make sure the k = k%n
 * and we need to get the common divisor of the two numbers. It means that how many self circle they have 
 * Then change the item place to a new place after store the value of the that new postion's value. 
 * When all the numbers are replaced then return. 

 * Another Easy Way: 
 * We should firstly check if the K is larger than n, and then make sure the k = k%n
 * and we need to get the common divisor of the two numbers. It means that how many self circle they have 
 * Then change the item place to a new place after store the value of the that new postion's value. 
 * When all the numbers are replaced then return. 

 * The most Easy Way: 
 * The most important thing is to consider the boundary!!!! k==0? k>n ?
 * the most easy way is to reverse the [0,n-k-1], [n-k,n-1], and finally, reverse [0,n-1] 



 * What to learn: 
 * When mention rotation, remember the cycle. So firstly make sure the length of rotation step is smaller than the 
 * length of array. Then to check some extreme case.  
 * */

#include <iostream>
using namespace std;

/* 1 solution */
/*
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k= k%n; // should make sure k less than n 
        int origin = 1;
        int newPosition = (origin+k)%n;
        int old_value = nums[origin-1];
        int new_value;
        int cnt = n;
        if (k==0)
            return;
        if(n%k) 
        {
            if(n%(n%k)) //[1,2,3,4,5,6,7], 3
            {
                while(cnt)
                {
                    if(newPosition==0)
                        newPosition = n;
                    new_value = nums[newPosition-1];
                    nums[newPosition-1] = old_value;
                    //cout<<newPosition<<": "<<old_value<<endl;
                    old_value = new_value;
                    newPosition = (newPosition+k)%n;
                    cnt --;    
                } 
            }
            else  // [1,2,3,4,5,6], 4
            {
                for(int origin=1;origin<=n%k;origin++)
                {
                    newPosition = (origin+k)%n;
                    old_value = nums[origin-1];
                    while(1)
                    {
                        if(newPosition==0)
                            newPosition = n;
                        new_value = nums[newPosition-1];
                        nums[newPosition-1] = old_value;
                        if (newPosition == origin)
                            break;
                        //cout<<newPosition<<": "<<old_value<<endl;
                        old_value = new_value;
                        newPosition = (newPosition+k)%n;  
                    } 
                } 

            }
            
        }
        else  // [1,2,3,4,5,6], 2
        {
            for(int origin=1;origin<=k;origin++)
            {
                cnt = 0;
                newPosition = (origin+k)%n;
                old_value = nums[origin-1];
                while(cnt != n/k)
                {
                    if(newPosition==0)
                        newPosition = n;
                    new_value = nums[newPosition-1];
                    nums[newPosition-1] = old_value;
                    //cout<<newPosition<<": "<<old_value<<endl;
                    old_value = new_value;
                    newPosition = (newPosition+k)%n;
                    cnt ++;    
                } 
            } 
        }
    }
};
*/

// We should firstly check if the K is larger than n, and then make sure the k = k%n
// and we need to get the common divisor of the two numbers. It means that how many self circle they have 
// Then change the item place to a new place after store the value of the that new postion's value. 
// When all the numbers are replaced then return. 
/*
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k= k%n; // should make sure k less than n 
        if (k==0)
            return;
        int a = n;
        int b = k; 
        int common_divisior = a%b; 
        while(common_divisior!=0)
        {
            a = b;
            b = common_divisior;
            common_divisior = a%b;
        }
        common_divisior = b; 
        for(int origin=1;origin<=common_divisior;origin++)
        {
            int new_value;
            int newPosition = (origin+k)%n;
            int old_value = nums[origin-1];
            while(1)
            {
                if(newPosition==0)
                    newPosition = n;
                new_value = nums[newPosition-1];
                nums[newPosition-1] = old_value;
                if (newPosition == origin)
                    break;
                //cout<<newPosition<<": "<<old_value<<endl;
                old_value = new_value;
                newPosition = (newPosition+k)%n;
            } 
        }
    }
};
*/

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k%n; 
        if(k==0)
            return; 
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);

    }
    void reverse(int nums[],int left, int right)
    {
        int n = right - left + 1;
        for(int i=0;i<n/2;i++){
            int temp = nums[left+i];
            nums[left+i] = nums[right-i];
            nums[right-i] = temp;
        }

    }
};


int main()
{
	Solution ans;
    int nums[] = {1,2,3,4,5,6,7};
    ans.rotate(nums,7,3);
    for(int i=0;i<7;i++)
        cout<<nums[i]<<" ";
	
	return 0;
}