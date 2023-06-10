//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
 public:
    int isPossible(int A, int B, int C){
        // code here
        int x = A, y = B, gcd;
        while(x != 0 && y != 0){
            if(x >= y){
                x = x % y;
            }
            else{
                y = y % x;
            }
        }
        if(x > y) gcd = x;
        else gcd = y;
        if(C % gcd == 0){
            return 1;
        }
        else return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,N;
        cin>>A>>B>>N;
        Solution ob;
        cout << ob.isPossible(A,B,N) << endl;
    }
    return 0;
}
// } Driver Code Ends