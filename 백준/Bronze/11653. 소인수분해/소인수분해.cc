#include <bits/stdc++.h>
using namespace std;

vector<int> sieve_of_eratosthenes(int n) { // 소수들을 원소로 가지는 벡터 반환
	vector<int> primes;
	vector<bool> state(n + 1, true);
	state[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (!state[i]) continue;
		for (int j = i * i; j <= n; j += i) state[j] = false;
	}
	for (int i = 2; i <= n; i++) if (state[i]) primes.push_back(i);

	return primes;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v = sieve_of_eratosthenes(n);
	for (int i : v) {
		if (i * i > n) { // 남은 n이 약수를 가지고 있다 하더라도 그 크기가 루트n보다 클 수는 없음
			if (n != 1) cout << n;
			break;
		}
		while (n % i == 0) { // 참: 나누어떨어짐
			cout << i << "\n";
			n /= i;
		}
	}

	return 0;
}