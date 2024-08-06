#include <iostream>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int paint_num = 0;
	int paint_size;
	int largest_paint = 0;

	int i;
	int j;
	int k;
	int n; // 도화지의 세로 크기
	int m; // 도화지의 가로 크기
	std::cin >> n >> m;

	const int X[4] = { 0,0,1,-1 };
	const int Y[4] = { 1,-1,0,0 };

	int** board = new int* [n];
	for (i = 0; i < n; ++i)
	{
		board[i] = new int[m];
		for (j = 0; j < m; ++j)
		{
			std::cin >> board[i][j];
		}
	}

	int* row_stk = new int[n * m * 2];
	int* col_stk = new int[n * m * 2];
	int size = 0;

	int cur_row;
	int cur_col;
	int sub_row;
	int sub_col;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			if (board[i][j])
			{
				++paint_num;

				paint_size = 1;
				row_stk[size] = i;
				col_stk[size] = j;
				++size;
				board[i][j] = 0;

				while (size)
				{
					cur_row = row_stk[size - 1];
					cur_col = col_stk[size - 1];
					--size;

					for (k = 0; k < 4; ++k)
					{
						sub_row = cur_row + X[k];
						sub_col = cur_col + Y[k];

						if (sub_row < 0 || n <= sub_row || sub_col < 0 || m <= sub_col || board[sub_row][sub_col] == 0)
						{
							continue;
						}

						++paint_size;
						row_stk[size] = sub_row;
						col_stk[size] = sub_col;
						++size;
						board[sub_row][sub_col] = 0;
					}
				}

				largest_paint = std::max(largest_paint, paint_size);
			}
		}
	}

	std::cout << paint_num << '\n' << largest_paint;

	for (i = 0; i < n; ++i)
	{
		delete[] board[i];
	}
	delete[] board;

	delete[] row_stk;
	delete[] col_stk;

	return 0;
}
