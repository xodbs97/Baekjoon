#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long A, B;
	cin >> A >> B;
	if (A > B) {
		long long t = A;
		A = B;
		B = t;
	}
	if (A == B || A + 1 == B) {
		cout << 0;
	}
	else {
		cout << B - A - 1 << '\n';
		for (size_t i = A + 1; i < B; i++)
		{
			cout << i << ' ';
		}
	}

	return 0;
}