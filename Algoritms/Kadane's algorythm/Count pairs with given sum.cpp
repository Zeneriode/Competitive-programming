//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
 public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int x = 0;
        unordered_map <int, int> hm;
        for(int i = 0; i < n; ++i){
            hm[arr[i]] += 1;
        }
        for(int i = 0; i < n; ++i){
            x += hm[k - arr[i]];
            if(k - arr[i] == arr[i]){
                x -= 1;
            }
        }
        return x/2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
}
// } Driver Code Ends
