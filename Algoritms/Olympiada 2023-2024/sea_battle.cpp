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
    int n, m, temp;
    cin >> n >> m;

    vector <int> vec_left(n, 0);
    vector <int> vec_right(m, 0);
    vector <int> time;
    vector <int> pos;

    for(int i = 0; i < n; ++i){
        cin >> temp;
        vec_left[i] = temp;
    }
    for(int i = 0; i < m; ++i){
        cin >> temp;
        vec_right[i] = temp;
    }
    int i = 0, j = 0;

    while(i < n){
        if(j < m && vec_right[j] < vec_left[i]){
            pos.push_back(vec_right[j] + ((vec_left[i] - vec_right[j]) / 2));
            time.push_back((vec_left[i] - vec_right[j]) / 2);
            i += 1;
            j += 1;
        }
        else{
            pos.push_back(vec_left[i]);
            time.push_back(0);
            i += 1;
        }
    }

    while(j < m){
        pos.push_back(vec_right[j]);
        time.push_back(0);
        j += 1;
    }

    for(int i = 0; i < pos.size(); ++i){
        cout << pos[i] << " " << time[i] << "\n";
    }
}
