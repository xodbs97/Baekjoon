#include <iostream>

#include <vector>
#include <queue>

using namespace std;

struct pos3
{
	int height;
	int row;
	int col;
};

using d1 = vector<char>;
using d2 = vector<d1>;
using d3 = vector<d2>;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const int H6[6] = { 0,0,0,0,1,-1 };
	const int R6[6] = { 0,0,1,-1,0,0 };
	const int C6[6] = { 1,-1,0,0,0,0 };

	int height;
	int row;
	int col;

	pos3 start;
	pos3 cur;
	int time;
	int sh;
	int sr;
	int sc;

	bool escaped;
	for (;;)
	{
		cin >> height >> row >> col;
		if (height == 0 && row == 0 && col == 0)
		{
			break;
		}

		d3 sangbum(height, d2(row, d1(col)));

		for (int h = 0; h < height; ++h)
		{
			for (int r = 0; r < row; ++r)
			{
				for (int c = 0; c < col; ++c)
				{
					cin >> sangbum[h][r][c];
					if (sangbum[h][r][c] == 'S')
					{
						start = { h,r,c };
					}
				}
			}
		}

		escaped = false;

		queue<pair<pos3, int>> q; // 위치,시간
		q.push({ start,0 });

		while (!q.empty() && !escaped)
		{
			cur = q.front().first;
			time = q.front().second;
			q.pop();

			for (int i = 0; i < 6; ++i)
			{
				sh = cur.height + H6[i];
				sr = cur.row + R6[i];
				sc = cur.col + C6[i];
				if (sh < 0 || height <= sh || sr < 0 || row <= sr || sc < 0 || col <= sc || sangbum[sh][sr][sc] == 'S' || sangbum[sh][sr][sc] == '#')
				{
					continue;
				}

				if (sangbum[sh][sr][sc] == 'E')
				{
					escaped = true;
					++time;
					break;
				}

				q.push({ {sh,sr,sc},time + 1 });
				sangbum[sh][sr][sc] = 'S';
			}
		}

		if (escaped)
		{
			cout << "Escaped in " << time << " minute(s).\n";
		}
		else
		{
			cout << "Trapped!\n";
		}
	}

	return 0;
}
