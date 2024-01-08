#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int card[21]{};
	for (int i = 0; i < 21; i++) {
		card[i] = i;
	}

	int r = 10;
	while (r--) {
		int a, b;
		cin >> a >> b;
		int m = (a + b) / 2;
		int j = 0;
		for (int i = a; i <= m; i++) {
			int t = card[i];
			card[i] = card[b - j];
			card[b - j] = t;
			++j;
		}
	}
	for (int i = 1; i < 21; i++) {
		cout << card[i] << ' ';
	}

	return 0;
}