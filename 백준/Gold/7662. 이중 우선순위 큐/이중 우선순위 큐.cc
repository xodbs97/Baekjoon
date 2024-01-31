#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define X first
#define Y second

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		multiset<int> ms;

		int n;
		cin >> n;
		cin.ignore();
		while (n--) {
			string s;
			getline(cin, s);
			int i = stoi(s.substr(s.find(" ")));
			if (s[0] == 'I') ms.insert(i); // Insert
			else { // Delete
				if (ms.size()) {
					multiset<int>::iterator it;
					if (i == 1) {
						it = ms.upper_bound(INT_MAX);
						--it;
						ms.erase(ms.find(*it));
					}
					else {
						it = ms.lower_bound(INT_MIN);
						ms.erase(ms.find(*it));
					}
				}
			}
		}
		if (ms.size()) {
			multiset<int>::iterator it;
			it = ms.upper_bound(INT_MAX);
			--it;
			cout << *it << " "; // 최댓값
			it = ms.lower_bound(INT_MIN);
			cout << *it << "\n"; // 최솟값
		}
		else cout << "EMPTY\n"; // 비어있다면 EMPTY 출력
	}
	return 0;
}