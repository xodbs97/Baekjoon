#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    vector<int> v;
    for (char c : s) v.push_back(c - '0');
    sort(v.rbegin(), v.rend());
    for (int i : v) cout << i;

    return 0;
}