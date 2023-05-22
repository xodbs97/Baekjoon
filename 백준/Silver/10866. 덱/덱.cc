#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <string>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	std::deque<int> DQ;
	
	int n;
	std::cin >> n;

	int num = 0;
	while (n--) {
		std::string str;
		std::cin >> str;

		if (str == "push_front") {
			std::cin >> num;
			DQ.push_front(num);
		}
		else if (str == "push_back") {
			std::cin >> num;
			DQ.push_back(num);
		}
		else if (str == "pop_front") {
			if (!DQ.empty()) {
				std::cout << DQ.front() << "\n";
				DQ.pop_front();
			}
			else {
				std::cout << "-1\n";
			}
		}
		else if (str == "pop_back") {
			if (!DQ.empty()) {
				std::cout << DQ.back() << "\n";
				DQ.pop_back();
			}
			else {
				std::cout << "-1\n";
			}
		}
		else if (str == "size") {
			std::cout << DQ.size() << "\n";
		}
		else if (str == "empty") {
			std::cout << DQ.empty() << "\n";
		}
		else if (str == "front") {
			if (!DQ.empty()) {
				std::cout << DQ.front() << "\n";
			}
			else {
				std::cout << "-1\n";
			}
		}
		else if (str == "back") {
			if (!DQ.empty()) {
				std::cout << DQ.back() << "\n";
			}
			else {
				std::cout << "-1\n";
			}
		}
	}

	return 0;
}