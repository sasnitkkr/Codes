/*
You are given a number n. You need to find the digital root of n. DigitalRoot of a number is the recursive sum of its digits until we get a single digit number.
*/
#include <iostream>
using namespace std;

int digitalRoot(int n)
{
    //Your code here
    if(n<=9)
        return n;
    int smallOutput=digitalRoot(n/10);
    int temp=(n%10)+smallOutput;
    if(temp<=9)
        return temp;
    return digitalRoot(temp);
}

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;//taking number n
	    
	    //calling digitalRoot() function
	    cout<<digitalRoot(n)<<endl;  
	}
	return 0;
} 
