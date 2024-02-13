#include <bits/stdc++.h>

using namespace std;

vector<bool> card(20000005);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 숫자 2천만개에 메모리 제한 256mb면 비트맵으로 표현 가능하지 않나? 다해봤자 2mb 정도 사용하니깐? 숫자 중복도 없고.
	int n, i;
	cin >> n;
	while (n--) {
		cin >> i;
		card[i + 10000000] = true;
	}
	cin >> n;
	while (n--) {
		cin >> i;
		cout << (card[i + 10000000] ? 1 : 0) << " ";
	}

	return 0;
}