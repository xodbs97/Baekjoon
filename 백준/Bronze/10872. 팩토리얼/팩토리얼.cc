#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n, ans = 1;
	std::cin >> n;

	if (n) {
		for (int i = 1; i <= n; i++) {
			ans *= i;
		}
		std::cout << ans;
	}
	else {
		std::cout << 1;
	}

	return 0;
}