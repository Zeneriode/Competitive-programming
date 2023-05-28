//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
    int kThSmallestFactor(int N , int K) {
        int x = 0, i = 0;
        while(x < K && i <= N){
            i += 1;
            if(N % i == 0){
                x += 1;
            }
        }
        if(x == K){
            return i;
        }
        else return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;

        cin>>N>>K;

        Solution ob;
        cout << ob.kThSmallestFactor(N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends
