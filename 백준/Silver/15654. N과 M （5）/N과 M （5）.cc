#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static int n;
static int m;
static vector<int> v;
static int nums[8];
static bool used[8];

static void permutation(const int _len);

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
	permutation(0);

	return 0;
}

void permutation(const int _len)
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

	for (int i = 0; i < n; ++i)
	{
		if (!used[i])
		{
			used[i] = true;
			nums[_len] = v[i];
			permutation(_len + 1);
			used[i] = false;
		}
	}
}