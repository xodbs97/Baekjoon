#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 학생의 수, 키를 비교한 횟수
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dag(n + 1, vector<int>(0));
	vector<int> in(n + 1, 0);
	for (int i = 0; i < m; ++i) {
		// 부모 → 자식 방향 그래프
		int j, k;
		cin >> j >> k;
		dag[j].push_back(k);
		// 노드 k는 자신을 가리키는 노드의 개수가 1 증가함을 알 수 있다.
		++in[k];
	}
	// indegree가 0인 노드의 번호 저장
	queue<int> q;
	for (int i = 1; i <= n; ++i) if (in[i] == 0) q.push(i);

	while (q.size()) {
		// 현재 indegree가 0인 node
		int cur = q.front();
		cout << cur << " ";
		q.pop();
		// 자식 node
		for (int node : dag[cur]) {
			// 부모가 사라졌으므로 개수는 1 줄여야 한다.
			--in[node];
			if (in[node]) continue;
			// 만약 indegree가 0이라면 큐에 해당 번호를 넣는다.
			q.push(node);
		}
	}

	return 0;
}