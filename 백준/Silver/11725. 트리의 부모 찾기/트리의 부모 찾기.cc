#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	// 행의 개수가 n + 1개인 2차원 벡터
	vector<vector<int>> t(n + 1, vector<int>(0));
	// 각 노드의 부모를 저장하기 위한 n + 1 크기의 벡터, 0은 비어있다는 의미이다.
	vector<int> p(n + 1, 0);
	// n - 1개의 간선을 입력받는다.
	for (int i = 1; i < n; ++i) {
		int j, k;
		cin >> j >> k;
		t[j].push_back(k);
		t[k].push_back(j);
	}
	// BFS 사용하므로 queue를 사용한다.
	queue<int> q;
	q.push(1);
	// 모든 node를 방문할 때까지 반복한다.
	while (q.size()) {
		int cur = q.front();
		q.pop();
		// 현재 노드와 연결된 모든 노드를 확인한다.(부모와 자식)
		for (int node : t[cur]) {
			// node가 cur의 부모라면 넘어간다.
			if (node == p[cur]) continue;
			// node가 cur의 자식이라면 node의 부모가 cur임을 p 벡터에 저장해준다.
			q.push(node);
			p[node] = cur;
		}
	}
	for (int i = 2; i <= n; ++i) cout << p[i] << "\n";

	return 0;
}