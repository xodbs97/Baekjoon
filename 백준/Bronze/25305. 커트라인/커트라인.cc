#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.rbegin(), v.rend());
    cout << v[k - 1];

    return 0;
}