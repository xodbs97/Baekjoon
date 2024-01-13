#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int arr[100001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	if (n > k) {
		cout << n - k;
		return 0;
	}

	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		int cur = q.front();
		if (cur == k) {
			cout << arr[cur];
			return 0;
		}
		q.pop();
		if (cur > 0 && arr[cur - 1] == 0) {
			arr[cur - 1] = arr[cur] + 1;
			q.push(cur - 1);
		}
		if (cur < 100000 && arr[cur + 1] == 0) {
			arr[cur + 1] = arr[cur] + 1;
			q.push(cur + 1);
		}
		if (cur * 2 <= 100000 && arr[cur * 2] == 0) {
			arr[cur * 2] = arr[cur] + 1;
			q.push(cur * 2);
		}
	}

	return 0;
}