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

	vector<vector<bool>> plate(n, vector<bool>(n, true));
	carving(plate, 0, 0, n);

	for (vector<bool>& line : plate)
	{
		for (bool elem : line)
		{
			cout << (elem ? '*' : ' ');
		}
		cout << '\n';
	}

	return 0;
}

void carving(vector<vector<bool>>& plate, const int rowOffset, const int colOffset, const int len)
{
	if (len == 1)
	{
		return;
	}

	for (int rs = 0; rs < 3; ++rs)
	{
		for (int cs = 0; cs < 3; ++cs)
		{
			if (rs == 1 && cs == 1)
			{
				for (int ri = rowOffset + len / 3; ri < rowOffset + len / 3 * 2; ++ri)
				{
					for (int ci = colOffset + len / 3; ci < colOffset + len / 3 * 2; ++ci)
					{
						plate[ri][ci] = false;
					}
				}
			}
			else
			{
				carving(plate, rowOffset + len / 3 * rs, colOffset + len / 3 * cs, len / 3);
			}
		}
	}
}