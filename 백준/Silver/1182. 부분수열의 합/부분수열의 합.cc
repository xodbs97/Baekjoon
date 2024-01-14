#include <bits/stdc++.h>

using namespace std;

int n, s; // n은 수열 길이, s는 수열의 원소들의 합
int num[20]; // n이 최대 20이니깐 이렇게 전역으로 정의 및 선언했음
int cnt = 0; // 내가 만든 수열의 원소들의 합이 주어진 값과 동일한 경우 1씩 증가시킴, 공집합도 카운팅 할 수 있으니 이것도 고려해야함

void func(int pos, int sum) { // 여기서 pos는 수열의 위치, n 길이의 수열인 경우 0부터 n-1으로 원소에 접근이 가능함, sum은 현재 수열의 원소들의 합
	if (pos == n) {
		if (sum == s) ++cnt;
		return;
	}

	func(pos + 1, sum);
	func(pos + 1, sum + num[pos]);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> num[i];
	func(0, 0);

	if (s == 0) cout << cnt - 1; // s가 0일 경우 공집합도 맞는 수열로 카운팅되므로 1을 빼주어야 함
	else cout << cnt;

	return 0;
}