#include <iostream>

using namespace std;

static int n;
static int s;
static int nums[20];
static int answer;
static bool used[20];

static void findSubSet(const int _len, const int _idx, const int _sum);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> s;
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	findSubSet(0, 0, 0);
	cout << answer;

	return 0;
}

void findSubSet(const int _len, const int _idx, const int _sum)
{
	if (_sum == s && _len)
	{
		++answer;
	}

	for (int i = _idx; i < n; ++i)
	{
		if (!used[i])
		{
			used[i] = true;
			findSubSet(_len + 1, i + 1, _sum + nums[i]);
			used[i] = false;
		}
	}
}