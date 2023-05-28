//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
 public:
    long long primeProduct(long long L, long long R){
        long long int x = 0, y = 1;;
        for(long long int j = L; j <= R; ++j){
            if (j == 2){
                y = (y * 2) % 1000000007;
            }
            else {
                for (long long int i = 2; i <= sqrt(j); ++i) {
                    if (j % i == 0) {
                        x += 1;
                        break;
                    }
                }
                if (x == 0 && j != 1) {
                    y = (y * j) % 1000000007;
                }
                x = 0;
            }
        }
        return y;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;

        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}
// } Driver Code Ends