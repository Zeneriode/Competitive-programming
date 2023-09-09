//// Copyright 2022 Zener
//// Шаблон для олимпиадных задач

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
    int m, n, x = 0, ans = 0, max_x = 0;
    cin >> n >> m;
    int matrix[n][m];
    for(int i = 0; i < n; ++i){
        if(n % 2 == 0) {
            if (i >= n / 2) {
                x -= 1;
            }
        }
        for(int j = 0; j < m; ++j){
            if(x > 0){
                matrix[i][j] = matrix[i - 1][j];
                if(j < m - x && j >= x){
                    matrix[i][j] = x;
                }
            }
            else {
                matrix[i][j] = 0;
            }
        }
        if(n % 2 == 0) {
            if (i < n / 2) {
                x += 1;
            }
        }
        else{
            if (i < n / 2) {
                x += 1;
            }
            if(i >= n / 2){
                x -= 1;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j) {
            if(matrix[i][j] > max_x){
                max_x = matrix[i][j];
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j) {
            if(matrix[i][j] == max_x){
                ans += 1;
            }
        }
    }
    cout << ans;
}

////if((n % 2 != 0 && m % 2 == 0) || (n % 2 == 0 && m % 2 != 0)){
////    cout << 2 << "\n";
////}
////else if(m % 2 == 0 && n % 2 == 0){
////    cout << 4 << "\n";
////}
////else{
////    cout << 1 << "\n";
////}