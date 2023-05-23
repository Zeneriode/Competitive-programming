#include <iostream>
using namespace std;

int main() {
    //code
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        int n;
        cin >> n;
        int arr[n];
        for(int j = 0; j < n; ++j){
            cin >> arr[j];
        }
        for(int j = 0; j < n; ++j){
            int minimal = 1000000;
            int temp = 0;
            for(int x = j; x < n; ++x){
                if(arr[x] + temp <= arr[x]){
                    temp += arr[x];
                }
                else{
                    temp = arr[x];
                }
                minimal = min(temp, minimal);
            }
            cout << minimal << " ";
        }
        cout << endl;
    }
    return 0;
}