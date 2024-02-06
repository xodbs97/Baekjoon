#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m; // node, edge 개수
	cin >> n >> m;

	vector<vector<int>> graph(n + 1, vector<int>(0)); // 1번 ~ n번 노드들과 연결된 노드들의 번호를 저장
	vector<bool> vis(n + 1, 0); // 이미 방문한 노드 표시

	for (int i = 0; i < m; i++) { // 무방향 그래프
		int j, k;
		cin >> j >> k;
		graph[j].push_back(k);
		graph[k].push_back(j);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue; // 이미 방문한 노드인 경우

		queue<int> q;
		q.push(i);
		vis[i] = true;

		while (q.size()) {
			int cur = q.front();
			q.pop();
			for (int node : graph[cur]) {
				if (vis[node]) continue;
				q.push(node);
				vis[node] = true;
			}
		}
		++ans;
	}
	cout << ans;

	return 0;
}