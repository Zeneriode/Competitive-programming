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
    //*is Single Test case?*/ cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

void solve() {
    int n, t_before, t_after, a, b;
    double percent, result_a, result_b, answ;
    cin >> n >> t_before >> t_after >> percent;
    percent = 1 - percent / 100.;
    vector<pair<int, double>> vec;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        result_a = a * t_before * percent + b * t_after;
        result_b = b * t_before * percent + a * t_after;
        answ = max(result_a, result_b);
        vec.emplace_back(i, answ);
    }
    sort(vec.begin(), vec.end(), [](const pair<int, double> &a, const pair<int, double> &b) {
        return (a.second > b.second) | (a.second == b.second & a.first < b.first);
    });
    for(auto & i : vec){
        cout << i.first << " " << fixed << setprecision(2) << i.second << "\n";
    }
}
