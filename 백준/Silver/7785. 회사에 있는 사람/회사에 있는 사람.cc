#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_set<string> us;

	int n;
	cin >> n;
	while (n--) {
		string name, state;
		cin >> name >> state;
		if (state == "enter") us.insert(name);
		else us.erase(name);
	}
    
	vector<string> v(us.begin(), us.end());
	sort(v.begin(), v.end(), greater<string>());
	for (string name : v) cout << name << "\n";
	return 0;
}