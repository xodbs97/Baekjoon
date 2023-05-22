#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

int main()
{
	time_t rawTime;
	struct tm* pTimeInfo;

	rawTime = time(NULL);					// 현재 시간을 받음
	pTimeInfo = localtime(&rawTime);		// 현재 시간을 이쁘게 struct tm에 넣음

	int year = pTimeInfo->tm_year + 1900;	// 연도에는 1900 더해줌
	int month = pTimeInfo->tm_mon + 1;		// 월에는 1 더해줌
	int day = pTimeInfo->tm_mday;

	if (month < 10) {
		std::cout << year << "-" << 0 << month << "-" << day;
	}
	else {
		std::cout << year << "-" << month << "-" << day;
	}

	return 0;
}