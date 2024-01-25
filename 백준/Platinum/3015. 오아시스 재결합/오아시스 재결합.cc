#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define X first
#define Y second

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll ans = 0;
	stack<pair<int, int>> st; // <키, 같은 키를 가진 연속한 사람 수>

	int n; // 총 인원
	cin >> n;

	for (int i = 0; i < n; i++) {
		int h; // 사람 키
		cin >> h;
		if (st.size()) { // 스택이 비어있지 않아야 top() 등의 메소드에서 오류가 나지 않음
			// 확인해야 할 사항
			// 1. top과 h간의 비교
			// top이 클 때
			// ++ans, st.push({h, 1})
			if (st.top().X > h) {
				++ans;
				st.push({ h,1 });
			}
			// top과 같을 때
			// st.size()가 1일 때, ans += st.top().Y
			// st.size()가 1이상일 때 ans += (st.top().Y + 1)
			// ++st.top().Y
			else if (st.top().X == h) {
				if (st.size() == 1) {
					ans += st.top().Y;
					++st.top().Y;
				}
				else {
					int same = 0;
					while (st.size() && st.top().X <= h) {
						ans += st.top().Y;
						if (st.top().X == h) {
							same += st.top().Y;
						}
						st.pop();
					}
					if (st.size()) {
						++ans;
						st.push({ h,same + 1 });
					}
					else {
						st.push({ h,same + 1 });
					}
				}
			}
			// top이 작을 때
			// top과 비교하면서 st.size() == 0이거나, st.top() > h일 때까지 ans += st.top().Y, st.pop()
			else {
				int same = 0;
				while (st.size() && st.top().X <= h) {
					ans += st.top().Y;
					if (st.top().X == h) {
						same += st.top().Y;
					}
					st.pop();
				}
				if (st.size()) {
					++ans;
					st.push({ h,same + 1 });
				}
				else {
					st.push({ h,same + 1 });
				}
			}
		}
		else {
			st.push({ h,1 });
		}
	}
	cout << ans;

	return 0;
}