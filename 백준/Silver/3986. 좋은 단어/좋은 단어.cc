#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		stack<char> st;
		string s;
		cin >> s;
		for (char c : s) {
			if (st.size() && st.top() == c) st.pop();
			else st.push(c);
		}
		if (st.empty()) ++ans;
	}
	cout << ans;

	return 0;
}