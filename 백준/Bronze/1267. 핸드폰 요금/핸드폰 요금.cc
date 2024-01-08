#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int ys = 0, ms = 0;
	int n;
	cin >> n;
	while (n--) {
		int k;
		cin >> k;
		ys += k / 30 * 10 + 10;
		ms += k / 60 * 15 + 15;
	}
	if (ys == ms) {
		cout << "Y M " << ys;
	}
	else if (ys < ms) {
		cout << "Y " << ys;
	}
	else {
		cout << "M " << ms;
	}

	return 0;
}