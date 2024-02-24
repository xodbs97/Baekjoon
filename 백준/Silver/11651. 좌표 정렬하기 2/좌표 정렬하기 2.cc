#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<pair<int,int>> v;
    
    int n;
    cin>>n;
    while (n--) {
        int x,y;
        cin>>x>>y;
        v.push_back({y,x});
    }
    sort(v.begin(),v.end());
    
    for (pair<int,int> p : v) cout<<p.second<<" "<<p.first<<"\n";
    
    return 0;
}