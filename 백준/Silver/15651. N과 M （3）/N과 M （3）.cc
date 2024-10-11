#include <iostream>

using namespace std;

static int n;
static int m;
static int nums[7];

static void permutation(const int _idx, const int _len);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	permutation(0, 0);

	return 0;
}

void permutation(const int _idx, const int _len)
{
	if (m == _len)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << nums[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		nums[_idx] = i;
		permutation(_idx + 1, _len + 1);
	}
}