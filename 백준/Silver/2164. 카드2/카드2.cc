#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size() != 1) {
		q.pop();
		int t = q.front();
		q.push(t);
		q.pop();
	}

	cout << q.front();

	return 0;
}