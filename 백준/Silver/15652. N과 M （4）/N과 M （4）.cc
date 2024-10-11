#include <iostream>

using namespace std;

static int n;
static int m;
static int nums[8];

static void permutation(const int _idx, const int _num, const int _len);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	permutation(0, 1, 0);

	return 0;
}

void permutation(const int _idx, const int _num, const int _len)
{
	if (_len == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << nums[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = _num; i <= n; ++i)
	{
		nums[_idx] = i;
		permutation(_idx + 1, i, _len + 1);
	}
}