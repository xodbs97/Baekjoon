#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

int main(int argc, const char* argv[])
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;
	int compare = n;
	int ascend = 0, descend = 0, mixed = 0;
	for (int i = 0; i < 7; i++) {
		std::cin >> n;
		if (n - compare == 1){
			ascend = 1;
			compare = n;
			if (descend == 1) {
				mixed = 1;
				break;
			}
		}
		else if (n - compare == -1) {
			descend = 1;
			compare = n;
			if (ascend == 1) {
				mixed = 1;
				break;
			}
		}
		else {
			mixed = 1;
			break;
		}
	}

	if (mixed == 1) {
		std::cout << "mixed";
	}
	else if (descend == 0) {
		std::cout << "ascending";
	}
	else {
		std::cout << "descending";
	}

	return 0;
}