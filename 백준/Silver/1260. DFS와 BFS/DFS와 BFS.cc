#include <bits/stdc++.h>

using namespace std;

bool cmp(const int& a, const int& b) {
	return a > b;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 정점의 개수, 간선의 개수, 탐색을 시작할 정점의 번호
	int n, m, v;
	cin >> n >> m >> v;

	vector<vector<int>> g(n + 1, vector<int>(0));
	while (m--) {
		int i, j;
		cin >> i >> j;
		g[i].push_back(j);
		g[j].push_back(i);
	}
	// 각 노드와 연결된 노드 정보 내립차순 정렬
	for (int i = 1; i <= n; ++i) sort(g[i].begin(), g[i].end(), cmp);

	// DFS 수행
	stack<int> dfs;
	vector<bool> vis(n + 1, false);
	stack<int> s;
	s.push(v);
	while (s.size()) {
		int node = s.top();
		if (!vis[node]) {
			vis[s.top()] = true;
			cout << node << " ";
		}
		s.pop();
		for (int i : g[node]) {
			if (vis[i]) continue;
			s.push(i);
		}
	}
	cout << "\n";

	// 각 노드와 연결된 노드 정보 오름차순 정렬
	for (int i = 1; i <= n; ++i) sort(g[i].begin(), g[i].end());
	// BFS 수행
	fill(vis.begin(), vis.end(), false);
	queue<int> q;
	q.push(v);
	while (q.size()) {
		int node = q.front();
		if (!vis[node]) {
			vis[node] = true;
			cout << node << " ";
		}
		q.pop();
		for (int i : g[node]) {
			if (vis[i]) continue;
			q.push(i);
		}
	}

	return 0;
}