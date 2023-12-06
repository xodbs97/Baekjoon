#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string letter) {
    string answer = "";
    vector<string> m = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
	while (letter.find(" ") != string::npos) {
		string morse = letter.substr(0, letter.find(" "));
		auto idx = find(m.begin(), m.end(), morse) - m.begin();
		answer += 'a' + static_cast<char>(idx);
		letter.erase(0, letter.find(" ") + 1);
	}
	answer += 'a' + static_cast<char>(find(m.begin(), m.end(), letter) - m.begin());

    return answer;
}