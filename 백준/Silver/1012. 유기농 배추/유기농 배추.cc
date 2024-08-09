#include <iostream>

#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	const int X[4] = { 1,-1,0,0 };
	const int Y[4] = { 0,0,1,-1 };

	int t; // 테스트 케이스의 개수
	cin >> t;

	while (t--)
	{
		int col; // 배추밭의 가로길이
		int row; // 배추밭의 세로길이
		int k; // 배추가 심어져 있는 위치의 개수
		cin >> col >> row >> k;

		vector<vector<bool>> field(row, vector<bool>(col, false)); // 배추밭

		int x; // 배추의 위치(가로)
		int y; // 배추의 위치(세로)
		while (k--)
		{
			cin >> x >> y;
			field[y][x] = true;
		}

		int insect = 0;
		queue<pair<int, int>>pos;

		for (int r_ = 0; r_ < row; ++r_)
		{
			for (int c_ = 0; c_ < col; ++c_)
			{
				if (field[r_][c_])
				{
					++insect;

					pos.push({ r_,c_ });
					field[r_][c_] = false;

					pair<int, int> cur;
					pair<int, int> sub;
					while (pos.size())
					{
						cur = pos.front();
						pos.pop();

						for (int d_ = 0; d_ < 4; ++d_)
						{
							sub = { cur.first + X[d_],cur.second + Y[d_] };
							if (sub.first < 0 || row <= sub.first || sub.second < 0 || col <= sub.second || !field[sub.first][sub.second])
							{
								continue;
							}

							pos.push({ sub.first,sub.second });
							field[sub.first][sub.second] = false;
						}
					}
				}
			}
		}

		cout << insect << '\n';
	}

	return 0;
}
