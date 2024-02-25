#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> human(n, pair<int, int>());

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		human[i] = { x,y };
	}

	vector<int> rank(n, 1);
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			// human[i], human[j] 두 사람간의 비교
			if (human[i].first == human[j].first || human[i].second == human[j].second) continue;
			// 몸무게 비교
			bool weight = human[i].first > human[j].first;
			// 키 비교
			bool height = human[i].second > human[j].second;
			if (weight && height) ++rank[j];
			else if (!weight && !height) ++rank[i];
		}
	}
	for (int i = 0; i < n; ++i) cout << rank[i] << " ";

	return 0;
}