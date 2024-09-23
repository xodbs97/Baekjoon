#include <iostream>
#include <stack>

using namespace std;

stack<int> stk[3];

static void Hanoi(const int num, const int curpos, const int nxtpos);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; // 첫 번째 장대에 쌓인 원판의 개수
	cin >> n;

	int k = 0; // 옮긴 횟수
	for (int i = 1; i <= n; ++i)
	{
		k = k * 2 + 1;
	}
	cout << k << '\n';

	for (int i = n; 0 < i; --i)
	{
		stk[0].push(i);
	}

	Hanoi(n, 1, 3);

	return 0;
}

void Hanoi(const int num, const int curpos, const int nxtpos)
{
	if (num == 0)
	{
		return;
	}

	Hanoi(num - 1, curpos, 6 - curpos - nxtpos);

	stk[curpos - 1].pop();
	stk[nxtpos - 1].push(num);
	cout << curpos << ' ' << nxtpos << '\n';

	Hanoi(num - 1, 6 - curpos - nxtpos, nxtpos);
}