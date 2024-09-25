#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<char> q;

static void compress(const vector<vector<int>>& image, const int rowOffset, const int colOffset, const int len)
{
	int num = image[rowOffset][colOffset];
	if (len == 1)
	{
		q.push('0' + num);
		return;
	}

	for (int ri = rowOffset; ri < rowOffset + len; ++ri)
	{
		for (int ci = colOffset; ci < colOffset + len; ++ci)
		{
			if (image[ri][ci] != num)
			{
				q.push('(');
				for (int rs = 0; rs < 2; ++rs)
				{
					for (int cs = 0; cs < 2; ++cs)
					{
						compress(image, rowOffset + len / 2 * rs, colOffset + len / 2 * cs, len / 2);
					}
				}
				q.push(')');
				return;
			}
		}
	}

	q.push('0' + num);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> image(n, vector<int>(n));
	for (int ri = 0; ri < n; ++ri)
	{
		string line;
		cin >> line;
		for (int ci = 0; ci < n; ++ci)
		{
			image[ri][ci] = line[ci] - '0';
		}
	}

	compress(image, 0, 0, n);

	while (!q.empty())
	{
		cout << q.front();
		q.pop();
	}

	return 0;
}