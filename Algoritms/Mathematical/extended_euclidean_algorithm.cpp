//{ Driver Code Starts



#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    int gcdExtended(int a, int b, int &x, int &y){
        if (b == 0){
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1;
        int GCD = gcdExtended(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return GCD;
    }
 public:
    vector<int> gcd(int a, int b){
        // code here
        int x, y, GCD;
        vector<int> vec;
        GCD = gcdExtended(a, b, x, y);
        vec.push_back(GCD);
        vec.push_back(x);
        vec.push_back(y);
        return vec;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        Solution ob;
        vector<int> v = ob.gcd(a,b);
        if(v.size()!=3)
            return 0;
        cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
    }
    return 0;
}
// } Driver Code Ends