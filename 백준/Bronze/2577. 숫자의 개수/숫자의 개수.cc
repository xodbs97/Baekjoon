#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
	int mul = a * b * c;
	int arr[10]{};
	while (mul) {
		++arr[mul % 10];
		mul /= 10;
	}
	for (auto i : arr) {
		cout << i << '\n';
	}

	return 0;
}