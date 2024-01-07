#include <bits/stdc++.h>
#include <string>
using namespace std;

int pre[5001], dat[5001], nxt[5001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fill(pre, pre + 5000, -1);
	fill(nxt, nxt + 5000, -1);

	int n, k;
	cin >> n >> k;
	int loc = 1;
	int tmp = n;
	while (tmp--) {
		pre[loc] = loc - 1;
		dat[loc] = loc;
		nxt[loc] = loc + 1;
		++loc;
	}
	pre[1] = n;
	nxt[0] = 1;
	nxt[n] = 1;

	loc = 0;
	tmp = n;
	cout << "<";
	while (tmp--) {
		int m = k;
		while (m--) {
			loc = nxt[loc];
		}

		cout << dat[loc];
		if (tmp != 0) {
			cout << ", ";
		}

		nxt[pre[loc]] = nxt[loc];
		pre[nxt[loc]] = pre[loc];
	}
	cout << ">";

	return 0;
}