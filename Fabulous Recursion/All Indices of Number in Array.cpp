/*
Given an array of length N and an integer x,
you need to find all the indexes where x is present in the input array.
Save all the indexes in an array (in increasing order).
Input :
5
9 8 10 8 8
8
Output :
1 3 4
*/
#include<iostream>
using namespace std;

int allIndexes(int input[], int size, int x, int output[]) {
  
  /*Save all the indexes in the output array passed and return the size of output array.*/
  
    if(size==0)
        return 0;
    int smallOutput=allIndexes(input+1,size-1,x,output);
    for(int i=0; i<smallOutput; i++)
        output[i]++;
    if(input[0]==x)
    {	for(int i=smallOutput; i>=1; i--)
            output[i]=output[i-1];
     output[0]=0;
     return smallOutput+1;
    }
    return smallOutput;

    
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];//0
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;    
    delete [] output;
}
