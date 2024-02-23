#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    vector<bool> v(200001,false);
    for(int i : nums) v[i]=true;
    
    int answer = 0;
    for(int i=1;i<=200000;++i){
        if(v[i]) ++answer;
    }
    
    return answer >= (int)nums.size() / 2 ? (int)nums.size() / 2:answer;
}