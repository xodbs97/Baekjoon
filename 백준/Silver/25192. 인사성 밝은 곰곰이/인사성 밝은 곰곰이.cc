#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = 0, tmpCnt = 0;

	set<string> st;

	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;

		if (s == "ENTER") {
			ans += tmpCnt;

			st.clear();
			tmpCnt = 0;
			continue;
		}

		if (st.empty()) {
			++tmpCnt;
			st.insert(s);
			continue;
		}

		if (st.find(s) == st.end()) {
			++tmpCnt;
			st.insert(s);
		}
	}
	cout << ans + tmpCnt;

	return 0;
}