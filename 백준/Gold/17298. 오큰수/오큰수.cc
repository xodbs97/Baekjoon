#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; // 수열 크기
	cin >> n;

	stack<int> st; // nge가 필요한 수들을 저장하기 위한 공간
	vector<int> nge(n, 0); // 각각의 수열의 nge 값을 저장하기 위한 공간
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (st.size()) { // stack이 차있는 경우, 즉 nge를 기다리는 수가 1개 이상인 경우
			if (st.top() < a) { // nge가 나타났을 때
				int idx = i - 1;
				while (st.size() && st.top() < a) { // 모든 수가 nge를 가지거나 스택에서 더 큰 수를 만나기 전까지
					if (nge[idx] == -1) { // nge를 찾은 경우
						nge[idx] = a;
						st.pop();
					}
					--idx;
				}
			}
		}
		st.push(a);
		nge[i] = -1;
	}
	for (int i : nge) cout << i << " ";

	return 0;
}