#include <bits/stdc++.h>

using namespace std;

// 자연수 개수, 수열 길이
int n, m;
// 완성된 수열이 저장될 배열
int arr[10];

// 현재 예비 번호, 현재 수열 길이
void bt(int num, int k) {
	// 수열이 완성됐다면
	if (k == m) {
		for (int i = 0; i < m; ++i) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; ++i) {
		arr[k] = i;
		bt(i, k + 1);
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	bt(1, 0);

	return 0;
}