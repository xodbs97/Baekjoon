#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static int l;
static int c;
static vector<char> v;
static char pwds[15];

static void password(const int _idx, const int _len, const int _cCnt, const int _vCnt);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> l >> c;
	for (int i = 0; i < c; ++i)
	{
		char chr;
		cin >> chr;
		v.push_back(chr);
	}
	sort(v.begin(), v.end());
	password(0, 0, 0, 0);

	return 0;
}

void password(const int _idx, const int _len, const int _cCnt, const int _vCnt)
{
	if (_len == l)
	{
		if (2 <= _cCnt && 0 < _vCnt)
		{
			for (int i = 0; i < l; ++i)
			{
				cout << pwds[i];
			}
			cout << '\n';
		}
		return;
	}
	if (c - _idx < l - _len)
	{
		return;
	}

	for (int i = _idx; i < c; ++i)
	{
		pwds[_len] = v[i];
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
		{
			password(i + 1, _len + 1, _cCnt, _vCnt + 1);
		}
		else
		{
			password(i + 1, _len + 1, _cCnt + 1, _vCnt);
		}
	}
}