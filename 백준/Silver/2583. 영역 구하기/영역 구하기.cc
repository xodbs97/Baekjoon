#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

using pos = pair<int, int>;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	const int R4[4] = { 0,0,1,-1 };
	const int C4[4] = { 1,-1,0,0 };

	int row;
	int col;
	int k; // 직사각형의 개수
	cin >> row >> col >> k;

	vector<vector<bool>> rectangle(row, vector<bool>(col, false));

	for (int i = 0; i < k; ++i)
	{
		int c1;
		int r1;
		int c2;
		int r2;
		cin >> c1 >> r1 >> c2 >> r2;
		for (int r = r1; r < r2; ++r)
		{
			for (int c = c1; c < c2; ++c)
			{
				rectangle[r][c] = true;
			}
		}
	}

	int area = 0;
	int cnt;
	vector<int> space;

	queue<pos> qr;
	pos cus;
	int sr;
	int sc;
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			if (rectangle[r][c] == false)
			{
				++area;

				qr.push({ r,c });
				rectangle[r][c] = true;
				cnt = 1;

				while (!qr.empty())
				{
					cus = qr.front();
					qr.pop();

					for (int i = 0; i < 4; ++i)
					{
						sr = cus.first + R4[i];
						sc = cus.second + C4[i];
						if (sr < 0 || row <= sr || sc < 0 || col <= sc || rectangle[sr][sc])
						{
							continue;
						}

						qr.push({ sr,sc });
						rectangle[sr][sc] = true;
						++cnt;
					}
				}

				space.push_back(cnt);
			}
		}
	}

	sort(space.begin(), space.end());

	cout << area << '\n';
	for (int& num : space)
	{
		cout << num << ' ';
	}

	return 0;
}
