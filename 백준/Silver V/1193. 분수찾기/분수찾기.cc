#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x;
	cin >> x;
	// 몇 번째 줄에 있는지
	int line = 1;
	while (true) {
		if (line * (line + 1) / 2 >= x) break;
		++line;
	}
	// 그 줄의 몇번 째 분수인지
	int place = x - (line * (line + 1) / 2) + line;

	// 홀수 줄에 있다면
	if (line % 2) cout << line + 1 - place << "/" << place;
	else cout << place << "/" << line + 1 - place;

	return 0;
}