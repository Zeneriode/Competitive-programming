//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
 public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

 public:
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector <int> vec(N, 0);
        vec[0] = A[0];
        vec[1] = max(A[1], A[0] + A[1]);
        for(int i = 2; i < N; ++i){
            vec[i] = max(A[i] + vec[i - 1], A[i] + vec[i - 2]);
        }
        return max(vec[N - 1], vec[N - 2]);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){

        int N;
        scanf("%d",&N);


        vector<int> A(N);
        IntArray::input(A,N);

        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);

        cout<<res<<endl;

    }
}

// } Driver Code Ends