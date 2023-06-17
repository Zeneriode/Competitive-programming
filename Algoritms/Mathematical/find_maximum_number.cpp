//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
    string findMax(string N) {
        string answ="";
        int arr[N.size()];
        for(int i = 0; i < N.size(); ++i){
            arr[i] = int(N[i]);
        }
        sort(arr, arr + N.size());
        for(int i = N.size() - 1; i >= 0; --i){
            answ += arr[i];
        }
        return answ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string N;

        cin>>N;

        Solution ob;
        cout << ob.findMax(N) << endl;
    }
    return 0;
}
// } Driver Code Ends