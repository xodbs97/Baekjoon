#include <bits/stdc++.h>

using namespace std;

vector<int> v(105);

// 0이면 자기 자신이 루트, 아니면 자식
int find(int i) {
	if (v[i] < 1) return i;
	else return find(v[i]);
}

void merge(int a, int b) {
	int pa = find(a), pb = find(b);
	if (pa == pb) return;
	v[pb] = pa;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 컴퓨터의 수,간선의 수
	int n, m;
	cin >> n >> m;
	// 간선으로 연결되어 있는 컴퓨터들을 그룹으로 묶기
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	int root = find(1);
	int ans = 0;
	for (int i = 2; i <= n; ++i) if (root == find(i)) ++ans;
	cout << ans;

	return 0;
}