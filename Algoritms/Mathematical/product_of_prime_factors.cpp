//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
 public:
    long long int primeProduct(int N){
        vector<int> vec;
        vector<int> primes;
        int answ = 1, x = 0;
        for(int i = 2; i <= N; ++i){
            if(N % i == 0){
                vec.push_back(i);
            }
        }
        for(int i = 0; i < vec.size(); ++i){
            for(int j = 2; j <= sqrt(vec[i]); ++j){
                if(vec[i] % j == 0){
                    ++x;
                }
            }
            if(x == 0){
                primes.push_back(vec[i]);
            }
            x = 0;
        }
        for(int i = 0; i < primes.size(); ++i){
            answ *= primes[i];
        }
        return answ;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.primeProduct(N) << endl;
    }
    return 0;
}
// } Driver Code Ends