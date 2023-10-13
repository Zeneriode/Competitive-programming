//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        int left = 0, right = 0, ans = 0;
        vector <int> vec_a(n, 0);
        vector <int> vec_b(m, 0);
        for(int i = 0; i < n; ++i){
            vec_a[i] = a[i];
        }
        for(int i = 0; i < m; ++i){
            vec_b[i] = b[i];
        }
        sort(vec_a.begin(), vec_a.end());
        sort(vec_b.begin(), vec_b.end());
        while(left < n && right < m){
            if (left > 0 && vec_a[left] == vec_a[left - 1]){
                left += 1;
                continue;
            }
            if(vec_a[left] > vec_b[right]){
                right += 1;
            }
            else if(vec_b[right] > vec_a[left]){
                left += 1;
            }
            else{
                ans += 1;
                right += 1;
                left += 1;
            }
        }
        return ans;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends