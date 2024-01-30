#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> vn(n), vm(m);
	for (int i = 0; i < n; i++) cin >> vn[i];
	for (int i = 0; i < m; i++) cin >> vm[i];
	sort(vn.begin(), vn.end());
	sort(vm.begin(), vm.end());

	vector<string> va;
	int pn = 0, pm = 0;
	while (pn < n && pm < m) {
		if (vn[pn] > vm[pm]) ++pm;
		else if (vn[pn] < vm[pm]) ++pn;
		else {
			va.push_back(vn[pn++]);
			++pm;
		}
	}
	cout << (int)va.size() << "\n";
	for (string s : va) cout << s << "\n";

	return 0;
}
