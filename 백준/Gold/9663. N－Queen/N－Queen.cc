#include <iostream>

using namespace std;

static int n;
static int answer;
static bool col[14];
static bool diagonal[27];
static bool antiDiagonal[27];

static void nQueen(const int _row);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	nQueen(0);
	cout << answer;

	return 0;
}

void nQueen(const int _row)
{
	if (_row == n)
	{
		++answer;
		return;
	}

	for (int c = 0; c < n; ++c)
	{
		int d = _row - c + n - 1;
		int ad = _row + c;
		if (!col[c] && !diagonal[d] && !antiDiagonal[ad])
		{
			col[c] = true;
			diagonal[d] = true;
			antiDiagonal[ad] = true;
			nQueen(_row + 1);
			col[c] = false;
			diagonal[d] = false;
			antiDiagonal[ad] = false;
		}
	}
}