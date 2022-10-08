#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
using ll = long long;

ll w, h, L;

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> w >> h >> L;
}

ll quarter_circle_carrot(ll r){
    ll ret = 0;
    for(ll x = 1;x < r;x++){
        ll y = (ll) sqrt(r * r - x * x);
        ret += y;
    }
    return ret;
}

int main(){
    input();
    ll qc = quarter_circle_carrot(L);
    ll carrot = 3 * qc + 2 * L;
    if(w < L){
        carrot += (quarter_circle_carrot(L - w) + L - w);
    }
    if(h < L){
        carrot += (quarter_circle_carrot(L - h) + L - h);
    }
    if(L - h > w && L - w > h){
        for(ll x = w + 1;x < L - h;x++){
            ll y = L - w - 1;
            while(y > h){
                if((x - w) * (x - w) + y * y <= (L - w) * (L - w) && x * x + (y - h) * (y - h) <=(L - h) * (L - h)) break;
                y--;
            }
            carrot -= (y - h);
        }
    }
    cout << carrot << '\n';
    return 0;
}
