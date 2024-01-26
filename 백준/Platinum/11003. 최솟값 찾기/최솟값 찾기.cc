#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define X first
#define Y second

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l; // 수의 개수, 수열의 범위를 결정하는 인자 - 해당 수열의 개수와 같다.
	cin >> n >> l;

	deque<pair<ll, int>> dq; // 최솟값, 유효 범위(i + l - 1)
	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		if (dq.size() && dq.back().X >= num) while (dq.size() && dq.back().X >= num && dq.back().Y >= i) dq.pop_back();
		dq.push_back({ num,i + l - 1 });
        
		if (dq.front().Y < i) dq.pop_front();
		cout << dq.front().X << " ";
	}

	return 0;
}