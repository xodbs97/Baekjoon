#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n, k;
	std::cin >> n >> k;

	int ans = 1;
	for (int i = n - k + 1; i <= n; i++) {
		ans *= i;
	}
	for (int i = 1; i <= k; i++) {
		ans /= i;
	}
	std::cout << ans;

	return 0;
}