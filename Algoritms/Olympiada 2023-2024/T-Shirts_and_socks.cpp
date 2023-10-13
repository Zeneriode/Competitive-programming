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
    long long a, b, c, d, ans_1 = 0, ans_2 = 0, x = 0, y = 0;
    cin >> a >> b >> c >> d;
    if((a - b) + (c - d) > (b - a) + (d - c)){
        ans_1 += b + 1 + d + 1;
    }
    else{
        ans_1 += a + 1 + c + 1;
        x = 1;
    }
    if(max(a, b) + 1 < max(c, d) + 1){
        ans_2 += max(a, b) + 1 + 1;
    }
    else{
        ans_2 += max(c, d) + 1 + 1;
        y = 1;
    }
    if(ans_1 < ans_2){
        if(x == 0){
            cout << b + 1 << " " << d + 1;
        }
        else{
            cout << a + 1 << " " << c + 1;
        }
    }
    else {
        if (y == 0) {
            cout << max(a, b) + 1 << " " << 1;
        } else {
            cout << max(c, d) + 1 << " " << 1;
        }
    }
}
