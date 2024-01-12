#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int sum = 0;
	int stick = 0;
	bool isRazer = false;
	for (auto c : str) {
		if (c == '(') {
			++stick;
			isRazer = true;
		}
		else {
			--stick;
			sum += isRazer ? stick : 1;
			isRazer = false;
		}
	}
	cout << sum;

	return 0;
}