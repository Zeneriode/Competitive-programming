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
    int n, m;
    cin >> n >> m;
    vector <int> vec_left;
    vector <int> vec_right;
    for(int i = 0; i < n; ++i){
        cin >> vec_left[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> vec_right[i];
    }

}
