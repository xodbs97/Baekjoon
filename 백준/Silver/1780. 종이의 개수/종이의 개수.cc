#include <iostream>
#include <vector>

using namespace std;

static int numOfPapers[3];

static void countingPapers(vector<vector<int>>&, const int);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> paper(n, vector<int>(n));
	for (int ri = 0; ri < n; ++ri)
	{
		for (int ci = 0; ci < n; ++ci)
		{
			cin >> paper[ri][ci];
		}
	}

	countingPapers(paper, n);

	for (int i = 0; i < 3; ++i)
	{
		cout << numOfPapers[i] << '\n';
	}

	return 0;
}

static void countingPapers(vector<vector<int>>& paper, const int len)
{
	int num = paper[0][0];
	if (len == 1)
	{
		++numOfPapers[num + 1];
		return;
	}

	for (int ri = 0; ri < len; ++ri)
	{
		for (int ci = 0; ci < len; ++ci)
		{
			if (paper[ri][ci] != num)
			{
				for (int rs = 0; rs < 3; ++rs)
				{
					for (int cs = 0; cs < 3; ++cs)
					{
						vector<vector<int>> partion(len / 3, vector<int>(len / 3));
						for (int rp = 0; rp < len / 3; ++rp)
						{
							for (int cp = 0; cp < len / 3; ++cp)
							{
								partion[rp][cp] = paper[rp + len / 3 * rs][cp + len / 3 * cs];
							}
						}
						countingPapers(partion, len / 3);
					}
				}
				return;
			}
		}
	}

	++numOfPapers[num + 1];
	return;
}