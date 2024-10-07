#include <iostream>

using namespace std;

static int n;
static int m;
static bool used[8];
static int order[8];

static void permutation(const int _len);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	permutation(0);

	return 0;
}

void permutation(const int _len)
{
	if (_len == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << order[i] << ' ';
		}
		cout << '\n';
	}

	for (int i = 0; i < n; ++i)
	{
		if (!used[i])
		{
			used[i] = true;
			order[_len] = i + 1;
			permutation(_len + 1);
			used[i] = false;
		}
	}
}