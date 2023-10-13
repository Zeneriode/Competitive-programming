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
    unsigned long long n, x = 1, ans = 0;
    cin >> n;
    while(n != 1){
        if(n % 9 == 0){
            ans += 9 * x;
            n /= 9;
            x *= 10;
        }
        else if(n % 8 == 0){
            ans += 8 * x;
            n /= 8;
            x *= 10;
        }
        else if(n % 7 == 0){
            ans += 7 * x;
            n /= 7;
            x *= 10;
        }
        else if(n % 6 == 0){
            ans += 6 * x;
            n /= 6;
            x *= 10;
        }
        else if(n % 5 == 0){
            ans += 5 * x;
            n /= 5;
            x *= 10;
        }
        else if(n % 4 == 0){
            ans += 4 * x;
            n /= 4;
            x *= 10;
        }
        else if(n % 3 == 0){
            ans += 3 * x;
            n /= 3;
            x *= 10;
        }
        else if(n % 2 == 0){
            ans += 2 * x;
            n /= 2;
            x *= 10;
        }
        else{
            cout << -1;
            return;
        }
    }
    cout << ans;
}
