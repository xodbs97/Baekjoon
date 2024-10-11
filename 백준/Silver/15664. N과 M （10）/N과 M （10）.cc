#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static int n;
static int m;
static int nums[8];
static vector<int> v;

static void permutation(const int _idx, const int _len);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	permutation(0, 0);

	return 0;
}

static void permutation(const int _idx, const int _len)
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

	int lvl = 0;
	for (int i = _idx; i < n; ++i)
	{
		if (lvl && v[i] == lvl)
		{
			continue;
		}
		lvl = v[i];
		nums[_len] = v[i];
		permutation(i + 1, _len + 1);
	}
}