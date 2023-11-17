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
    long long n, m, d, temp;
    cin >> n >> m >> d;
    vector<long long> vec_x;
    vector<long long> vec_y;
    for(int i = 0; i < d; ++i){
        cin >> temp;
        vec_x.push_back(temp);
        cin >> temp;
        vec_y.push_back(temp);
    }
    long long x = vec_x[0], y = vec_y[0];
    for(int i = 0; i < d; ++i){
        x = min(x, vec_x[i]);
        y = min(y, vec_y[i]);
    }
    cout << x * y << " " << d;
}
