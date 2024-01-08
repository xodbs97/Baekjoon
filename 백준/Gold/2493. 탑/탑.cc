#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int** tower = new int* [n];
	for (int i = 0; i < n; i++) {
		tower[i] = new int[2];
	}

	int valid = 0;
	tower[0][0] = 1;
	cin >> tower[0][1];
	cout << 0 << ' ';

	for (int i = 2; i <= n; i++) {
		int h;
		cin >> h;
		if (h > tower[0][1]) {
			valid = 0;
			tower[0][0] = i;
			tower[0][1] = h;
			cout << 0 << ' ';
		}
		else if (valid) {
			for (int j = valid; j >= 0; j--) {
				if (h > tower[j][1]) {
					continue;
				}
				valid = j + 1;
				tower[valid][0] = i;
				tower[valid][1] = h;
				cout << tower[j][0] << ' ';
				break;
			}
		}
		else {
			++valid;
			tower[1][0] = i;
			tower[1][1] = h;
			cout << tower[0][0] << ' ';
		}
	}

	for (int i = 0; i < n; i++) {
		delete[] tower[i];
	}
	delete[] tower;

	return 0;
}