#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int w = dots[0][0], h = dots[0][1];
    bool wf = true, hf = true;
    for(auto v : dots){
        if(wf){
            if(w != v[0]){
                w = w - v[0] > 0 ? w - v[0] : v[0] - w;
                wf = false;
            }
        }
        if(hf){
            if(h != v[1]){
                h = h - v[1] > 0 ? h - v[1] : v[1] - h;
                hf = false;
            }
        }
        if(!wf && !hf){
            break;
        }
    }
    return w * h;
}