//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
 public:
    vector<int> sieveOfEratosthenes(int N)
    {
        vector<int> vec;
        int x = 0;
        for(int j = 2; j <= N; ++j){
            for(int i = 2; i <= sqrt(j); ++i){
                if(j % i == 0){
                    x += 1;
                }
            }
            if(x == 0){
                vec.push_back(j);
            }
            x = 0;
        }
        return vec;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends