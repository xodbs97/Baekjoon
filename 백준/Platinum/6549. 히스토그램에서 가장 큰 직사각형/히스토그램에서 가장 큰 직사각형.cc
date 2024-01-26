#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define X first
#define Y second

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n) {
		ll max_area = 0;
		stack<pair<ll, int>> st_begin; // 높이, 시작 위치
		int idx = 0;
		for (; idx < n; idx++) {
			ll h;
			cin >> h;
			if (st_begin.size() && st_begin.top().X == h) continue;
			st_begin.push({ h,idx });
		}

		stack<pair<ll, int>> st_end; // 높이, 끝 위치
		while (st_begin.size()) {
			if (st_end.size()) {
				if (st_end.top().X > st_begin.top().X) {
					int end_idx = 0;
					while (st_end.size() && st_end.top().X > st_begin.top().X) {
						max_area = max(max_area, st_end.top().X * (st_end.top().Y - idx));
						end_idx = st_end.top().Y;
						st_end.pop();
					}
					if (st_end.size() && st_end.top().X == st_begin.top().X) {
						idx = st_begin.top().Y;
						st_begin.pop();
					}
					else { // st2.top().X < st.top().X 혹은 st_end가 비어있을 때
						st_end.push({ st_begin.top().X,end_idx });
						idx = st_begin.top().Y;
						st_begin.pop();
					}
				}
				else if (st_end.top().X == st_begin.top().X) {
					idx = st_begin.top().Y;
					st_begin.pop();
				}
				else { // st2.top().X < st.top().X
					st_end.push({ st_begin.top().X,idx });
					idx = st_begin.top().Y;
					st_begin.pop();
				}
			}
			else {
				st_end.push({ st_begin.top().X,idx });
				idx = st_begin.top().Y;
				st_begin.pop();
			}
		}
		while (st_end.size()) {
			max_area = max(max_area, st_end.top().X * st_end.top().Y);
			st_end.pop();
		}
		cout << max_area << "\n";

		cin >> n;
	}

	return 0;
}