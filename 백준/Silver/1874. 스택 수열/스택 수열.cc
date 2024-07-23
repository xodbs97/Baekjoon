#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	stack<int> stk;
	vector<bool> notUsed(n + 1, true);
	int big = 0;
	vector<char> printer;

	bool fail = false;

	int nCpy = n;
	while (nCpy--)
	{
		int num;
		cin >> num;

		if (notUsed[num]) // 아직 수를 스택에 넣지 않았다면
		{
			for (int i = big + 1; i <= num; ++i)
			{
				notUsed[i] = false;
				stk.push(i);
				printer.push_back('+');
			}

			big = num;

			stk.pop();
			printer.push_back('-');
		}
		// 스택에 들어갔던 수라면
		else if (stk.empty() || stk.top() != num) // 불가능
		{
			fail = true;
			break;
		}
		else // 가능
		{
			stk.pop();
			printer.push_back('-');
		}
	}

	if (fail)
	{
		cout << "NO";
	}
	else
	{
		for (char& c : printer)
		{
			cout << c << '\n';
		}
	}

	return 0;
}
