#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    if(n > m){
        return ineq == ">" ? 1 : 0;
    }else{
        if(n == m){
            return eq == "=" ? 1 : 0;
        }
        
        return ineq == "<" ? 1 : 0;
    }
}