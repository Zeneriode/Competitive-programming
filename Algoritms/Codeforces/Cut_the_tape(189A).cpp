// Copyright 2022 Zener
// Шаблон для олимпиадных задач

#include <bits/stdc++.h>

using namespace std;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //    /*is Single Test case?*/ cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

void solve() {
    int n, a, b, c;
    cin >> n;
    cin >> a >> b >> c;
    int arr[n];
    for(int i = 0; i <= n; ++i){
        arr[i] = -1;
    }
    arr[0] = 0;
    for(int i = 1; i <= n; ++i){
        if(i - a >= 0 && arr[i - a] != -1){
            arr[i] = arr[i - a] + 1;
        }
        if(i - b >= 0 && arr[i - b] != -1){
            arr[i] = max(arr[i], arr[i - b] + 1);
        }
        if(i - c >= 0 && arr[i - c] != -1){
            arr[i] = max(arr[i], arr[i - c] + 1);
        }
    }
    cout << arr[n] << endl;
}