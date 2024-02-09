#include <bits/stdc++.h>

using namespace std;

vector<int> lc(27);
vector<int> rc(27);

// 전위 순회
void pre(int node) {
	cout << (char)('A' + node);
	if (lc[node]) pre(lc[node]);
	if (rc[node]) pre(rc[node]);
	return;
}
// 중위 순회
void in(int node) {
	if (lc[node]) in(lc[node]);
	cout << (char)('A' + node);
	if (rc[node]) in(rc[node]);
}
// 후위 순회
void post(int node) {
	if (lc[node]) post(lc[node]);
	if (rc[node]) post(rc[node]);
	cout << (char)('A' + node);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 노드의 개수
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		// 현재 노드, 왼쪽 자식, 오른쪽 자식 → 자식이 없으면 '.'을 입력받는다.
		char a, b, c;
		cin >> a >> b >> c;
		// 알파벳 - 'A' 위치에 자식 노드를 저장한다. '.'을 입력받았을 때는 0을 유지한다.
		if (b != '.') lc[a - 'A'] = b - 'A';
		if (c != '.') rc[a - 'A'] = c - 'A';
	}
	pre(0);
	cout << "\n";
	in(0);
	cout << "\n";
	post(0);

	return 0;
}