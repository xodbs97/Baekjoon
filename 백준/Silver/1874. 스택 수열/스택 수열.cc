#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int* stk = new int[n + 1];
	int* ans = new int[n * 2];
	fill(stk, stk + n + 1, 1);

	int num;
	cin >> num;
	int max = num;
	int last = num;
	stk[num] = 0;
	int a_idx = 0;
	while (num--) {
		ans[a_idx++] = '+';
	}
	ans[a_idx++] = '-';

	int rpt = n - 1;
	while (rpt--) {
		cin >> num;
		if (num < last - 1) {
			for (int i = last - 1; i > num; i--) {
				if (stk[i]) {
					cout << "NO";
					return 0;
				}
			}
		}
		else if (num > last) {
			for (int i = max + 1; i <= num; i++) {
				ans[a_idx++] = '+';
			}
			max = num;
		}
		last = num;
		stk[num] = 0;
		ans[a_idx++] = '-';
	}
	for (int i = 0; i < n * 2; i++) {
		cout << (char)ans[i] << "\n";
	}

	delete[] stk;
	delete[] ans;
	return 0;
}