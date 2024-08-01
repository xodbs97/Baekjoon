#include <iostream>

#include <string>

#include <deque>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; // 테스트 케이스의 개수
	cin >> t;
	while (t--)
	{
		string p; // 수행할 함수
		cin >> p;

		int n; // 배열에 들어있는 수의 개수
		cin >> n;

		deque<int> dq;
		string arr; // 배열에 들어있는 정수
		cin >> arr;

		if (n)
		{
			string num;
			for (size_t i = 1; i < arr.size(); ++i)
			{
				if ('0' <= arr[i] && arr[i] <= '9')
				{
					num.push_back(arr[i]);
				}
				else
				{
					dq.push_back(stoi(num));
					num.clear();
				}
			}
		}

		bool printError = false;
		bool isFrontFront = true;
		for (char& c : p)
		{
			if (c == 'D')
			{
				if (dq.empty())
				{
					printError = true;
					break;
				}

				if (isFrontFront)
				{
					dq.pop_front();
				}
				else
				{
					dq.pop_back();
				}
			}
			else // c == 'R'
			{
				isFrontFront = !isFrontFront;
			}
		}

		if (printError)
		{
			cout << "error\n";
		}
		else if (isFrontFront)
		{
			cout << '[';
			while (!dq.empty() && dq.size() != 1)
			{
				cout << dq.front() << ',';
				dq.pop_front();
			}
			if (dq.size() == 1)
			{
				cout << dq.front();
			}
			cout << "]\n";
		}
		else
		{
			cout << '[';
			while (!dq.empty() && dq.size() != 1)
			{
				cout << dq.back() << ',';
				dq.pop_back();
			}
			if (dq.size() == 1)
			{
				cout << dq.back();
			}
			cout << "]\n";
		}
	}

	return 0;
}
