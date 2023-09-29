// Copyright 2022 Zener
// Шаблон для олимпиадных задач

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
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
    ull n, m;
    cin >> n >> m;
    ull k = (min(n, m) + 1) / 2;
    ull x = (n + m + n + m - 4 * (k - 1)) / 2 * k;

    if (n - m != 1 || min(n, m) & 1) {
        x--;
    }

    cout << x;
}