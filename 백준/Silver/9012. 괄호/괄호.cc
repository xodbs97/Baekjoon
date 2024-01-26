#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		stack<char> st;
		string s;
		cin >> s;
		for (char c : s) {
			if (st.size() && (st.top() == '(' && c == ')')) st.pop();
			else st.push(c);
		}
		cout << (st.size() ? "NO" : "YES") << "\n";
	}

	return 0;
}