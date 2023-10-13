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
    /*is Single Test case?*/ cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

void solve() {
    int a, b;
    float k, m, y;
    cin >> a >> b >> k >> m;
    float z = k + 1 - m, D;
    D = k * k - 4 * (-1) * z;
    float x1, x2;
    if (D > 0) {
        x1 = ((-k) + sqrt(D)) / (-2);
        x2 = ((-k) - sqrt(D)) / (-2);
        if (x1 > x2 && !(0 > x1 || x1 > a)) {
            y = k - x1;
            if (!(0 > y || y > b)) {
                cout << y << " " << x1;
            } else {
                cout << -1;
                return;
            }
        } else if (!(0 > x2 || x2 > a)) {
            y = k - x2;
            if (!(0 > y || y > b)) {
                cout << y << " " << x2;
            } else {
                cout << -1;
                return;
            }
        } else {
            cout << -1;
        }
    } else if (D == 0) {
        x1 = ((-k) + sqrt(D)) / (-2);
        if (!(0 > x1 || x1 > a)) {
            y = k - x1;
            if (!(0 > y || y > b)) {
                cout << y << " " << x1;
            } else {
                cout << -1;
                return;
            }
        } else {
            cout << -1;
            return;
        }
    } else {
        cout << -1;
        return;
    }
}