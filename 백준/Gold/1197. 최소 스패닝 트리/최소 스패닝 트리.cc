#include <bits/stdc++.h>

using namespace std;

// 정점 개수, 간선 개수
int v, e;
// 정점의 루트를 저장하는 벡터
vector<int> p;
// 간선의 가중치를 저장하는 튜플. cost, vertex, vertex순으로 저장
vector<tuple<int, int, int>> edges;

int find(int n) {
	if (p[n] <= 0) return n;
	p[n] = find(p[n]);
	return p[n];
}

bool isDiffGroup(int a, int b) {
	// 각 정점의 그룹의 루트를 찾아서 저장
	int pa = find(a), pb = find(b);
	// 부모가 서로 같을 때
	if (pa == pb) return false;
	// 부모가 서로 다를 때 타 그룹의 부모를 현 그룹의 부모로 변환
	p[pb] = pa;
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> v >> e;
	p.resize(v + 1, 0);
	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a < b ? edges.push_back({ c, a, b }) : edges.push_back({ c, b, a });
	}
	// cost 오름차순으로 정렬
	sort(edges.begin(), edges.end());
	// 그룹의 크기, 최소 가중치
	int group = 0, ans = 0;
	for (auto edge : edges) {
		int cost, a, b;
		tie(cost, a, b) = edge;
		if (!isDiffGroup(a, b)) continue;
		// 두 정점이 서로 다른 그룹일 때 가중치 값 더하고 그룹에 속해있는 수 늘려주기
		ans += cost;
		++group;
		if (group == v - 1) break;
	}
	cout << ans;

	return 0;
}