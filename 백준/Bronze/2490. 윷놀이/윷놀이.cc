#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r = 3;
	while (r--) {
		vector<int> v;
		for (int i = 0; i < 4; i++) {
			int n;
			cin >> n;
			v.push_back(n);
		}
		sort(v.begin(), v.end());

		int  o = 0;
		for (auto i : v) {
			if (i) {
				++o;
			}
		}
		switch (o)
		{
		case 0:
			cout << "D\n";
			break;
		case 1:
			cout << "C\n";
			break;
		case 2:
			cout << "B\n";
			break;
		case 3:
			cout << "A\n";
			break;
		case 4:
			cout << "E\n";
			break;
		}
	}

	return 0;
}