#include <iostream>

#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	const int R8[8] = { -2,-1,1,2,2,1,-1,-2 };
	const int C8[8] = { 1,2,2,1,-1,-2,-2,-1 };

	int num; // 테스트 케이스의 개수
	cin >> num;
	while (num--)
	{
		int l; // 체스판의 한 변의 길이
		cin >> l;

		vector<vector<int>> board(l, vector<int>(l, 0)); // 체스판

		int fr; // 나이트가 현재 있는 칸(행)
		int fc; // 나이트가 현재 있는 칸(열)
		cin >> fr >> fc;
		int tr; // 나이트가 이동하려고 하는 칸(행)
		int tc; // 나이트가 이동하려고 하는 칸(열)
		cin >> tr >> tc;

		if (fr == tr && fc == tc) // 출발지와 목적지가 같을 때
		{
			cout << 0 << '\n';
			continue;
		}

		queue<int> qr;
		queue<int> qc;

		qr.push(fr);
		qc.push(fc);
		board[fr][fc] = 1;

		bool check = false;
		int cr;
		int cc;
		int sr;
		int sc;
		while (qr.size())
		{
			cr = qr.front();
			cc = qc.front();
			qr.pop();
			qc.pop();

			for (int i = 0; i < 8; ++i)
			{
				sr = cr + R8[i];
				sc = cc + C8[i];
				if (sr < 0 || l <= sr || sc < 0 || l <= sc || board[sr][sc])
				{
					continue;
				}

				qr.push(sr);
				qc.push(sc);
				board[sr][sc] = board[cr][cc] + 1;

				if (sr == tr && sc == tc)
				{
					check = true;
					cout << board[sr][sc] - 1 << '\n';
					break;
				}
			}
			if (check)
			{
				break;
			}
		}
	}

	return 0;
}
