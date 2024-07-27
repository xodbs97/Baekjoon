#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string answer;

	stack<int> stk;
	int curMax = 0;
	bool fail = false;

	int n;
	cin >> n;
	while (n--)
	{
		int num;
		cin >> num;

		if (curMax < num) // 아직 수를 스택에 넣지 않았다면
		{
			for (int i = curMax + 1; i <= num; ++i)
			{
				stk.push(i);
				answer.append("+\n");
			}

			curMax = num;

			stk.pop();
			answer.append("-\n");
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
			answer.append("-\n");
		}
	}

	if (fail)
	{
		cout << "NO";
	}
	else
	{
		cout << answer;
	}

	return 0;
}
