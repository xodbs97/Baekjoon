#include <iostream>

using namespace std;

static int cnt;
static int cand[12];
static int nums[6];

static void lotto(const int _idx, const int _len);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (;;)
	{
		cin >> cnt;
		if (cnt == 0)
		{
			break;
		}

		for (int i = 0; i < cnt; ++i)
		{
			cin >> cand[i];
		}
		lotto(0, 0);
		cout << '\n';
	}

	return 0;
}

void lotto(const int _idx, const int _len)
{
	if (cnt - _idx < 6 - _len)
	{
		return;
	}
	if (_len == 6)
	{
		for (int i = 0; i < 6; ++i)
		{
			cout << nums[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = _idx; i < cnt; ++i)
	{
		nums[_len] = cand[i];
		lotto(i + 1, _len + 1);
	}
}