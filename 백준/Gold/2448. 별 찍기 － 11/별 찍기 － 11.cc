#include <iostream>
#include <vector>

using namespace std;

static void carving(vector<vector<bool>>& plate, const int rowOffset, const int colOffset, const int len);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<bool>> plate(n, vector<bool>(n * 2 - 1, true));
	carving(plate, 0, 0, n);

	for (int ri = 0; ri < n; ++ri)
	{
		for (int si = 0; si < n - ri - 1; ++si)
		{
			cout << ' ';
		}
		for (int ci = 0; ci < ri * 2 + 1; ++ci)
		{
			cout << (plate[ri][ci] ? '*' : ' ');
		}
		for (int si = 0; si < n - ri; ++si)
		{
			cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}

void carving(vector<vector<bool>>& plate, const int rowOffset, const int colOffset, const int len)
{
	if (len == 3)
	{
		plate[rowOffset + 1][colOffset + 1] = false;
		return;
	}

	for (int ri = rowOffset + len / 2; ri < rowOffset + len; ++ri)
	{
		for (int ci = colOffset + 1 + (ri - rowOffset) * 2 - len; ci < colOffset + len; ++ci) // colOffset + 1 + (ri - rowOffset - len / 2) * 2
		{
			plate[ri][ci] = false;
		}
	}

	carving(plate, rowOffset, colOffset, len / 2);
	carving(plate, rowOffset + len / 2, colOffset, len / 2);
	carving(plate, rowOffset + len / 2, colOffset + len, len / 2);
}