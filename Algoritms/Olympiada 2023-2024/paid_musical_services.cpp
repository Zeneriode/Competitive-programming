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
    long long n, m;
    cin >> n >> m;
    long long a = 1, d = 1, ans = 0;
    while(d <= m){
        if((n - 1) * d <= m){
            ans += m - (n - 1) * d;
            d += 1;
        }
        else{
            d += 1;
        }
    }
    cout << ans;
}
