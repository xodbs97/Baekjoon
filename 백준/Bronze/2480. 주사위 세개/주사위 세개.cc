#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	for (int i = 0; i < 3; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());

	int same_num = v[0] == v[1] ? (v[1] == v[2] ? 3 : 2) : (v[1] == v[2] ? 2 : 1);
	int prize = 0;
	switch (same_num)
	{
	case 1:
		prize = v[2] * 100;
		break;
	case 2:
		prize = v[1] * 100 + 1000;
		break;
	case 3:
		prize = v[1] * 1000 + 10000;
		break;
	}
	cout << prize;

	return 0;
}