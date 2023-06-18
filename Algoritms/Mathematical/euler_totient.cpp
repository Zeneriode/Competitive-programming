//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
 public:
    long long maximizeEulerRatio(long long N){
        if(flag){
            Sieve();
            flag = false;
        }
        long long res = 1 , i = 2;
        while(res * i <= N){
            if(P[i])
                res *= i;
            i++;
        }
        return res;
    }
    bool P[100];
    bool flag = true;
    void Sieve(){
        memset(P, true, sizeof(P));
        for(int i = 2 ; i * i <= 100 ; i++){
            if(P[i]){
                for(int j = i * i ; j <= 100 ; j += i){
                    P[j] = false;
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;

        cin>>N;

        Solution ob;
        cout << ob.maximizeEulerRatio(N) << endl;
    }
    return 0;
}
// } Driver Code Ends