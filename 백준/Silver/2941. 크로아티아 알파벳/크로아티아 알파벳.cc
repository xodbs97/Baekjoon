#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;

    int i = 0, ans = 0;
    while (i < s.length()) {
        if (s[i] == 'c' && i + 1 < s.length() && (s[i + 1] == '=' || s[i + 1] == '-')) ++i;
        else if (s[i] == 'd' && i + 1 < s.length()) {
            if (s[i + 1] == '-') ++i;
            else if (s[i + 1] == 'z' && i + 2 < s.length() && s[i + 2] == '=') i += 2;
        }
        else if (s[i] == 'l' && i + 1 < s.length() && s[i + 1] == 'j') ++i;
        else if (s[i] == 'n' && i + 1 < s.length() && s[i + 1] == 'j') ++i;
        else if (s[i] == 's' && i + 1 < s.length() && s[i + 1] == '=') ++i;
        else if (s[i] == 'z' && i + 1 < s.length() && s[i + 1] == '=') ++i;
        ++ans;
        ++i;
    }
    cout << ans;
    
    return 0;
}