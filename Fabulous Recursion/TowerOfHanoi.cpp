#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int A, int C, int B) {
        // Your code here
        if(N==1)
        {
            cout<<"move disk 1 from rod "<<A<<" to rod "<<C<<"\n";
            return 1;
        }
        else
        {
            int so1=toh(N-1,A,B,C);
            cout<<"move disk "<<N<<" from rod "<<A<<" to rod "<<C<<"\n";
            int so2=toh(N-1,B,C,A);
            return 1+so1+so2;
        }
    }
};

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        long long moves = 0;
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        moves = ob.toh(N, 1, 3, 2);
        cout << moves << endl;
    }
    return 0;
}
