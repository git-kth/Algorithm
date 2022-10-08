#include <iostream>
#include <algorithm>

#define MAX 500001

using namespace std;

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

int N;
pair<long long, long long> p[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    long long x, y;
    for(int i = 0;i < N;i++){
        cin >> x >> y;
        p[i] = make_pair(x, y);
    }
    cin >> x >> y;
    for(int i = 0;i < N;i++){
        p[i].first -= x;
        p[i].second -= y;
    }
    int check[4] = {1, 1, 1, 1};
    for(int i = 0;i < N;i++){
        x = p[i].first; y = p[i].second;
        if(x == 0 & y > 0) check[UP] = 0;
        else if(x == 0 && y < 0) check[DOWN] = 0;
        else if(y == 0 && x > 0) check[RIGHT] = 0;
        else if(y == 0 && x < 0) check[LEFT] = 0;
        else{
            if(x > 0 && y > 0){
                if(x - y <= 0) check[UP] = 0;
                if(y - x <= 0) check[RIGHT] = 0;
            }else if(x < 0 && y > 0){
                if(-x - y <= 0) check[UP] = 0;
                if(y + x <= 0) check[LEFT] = 0;
            }else if(x < 0 && y < 0){
                if(-x + y <= 0) check[DOWN] = 0;
                if(-y + x <= 0) check[LEFT] = 0;
            }else{
                if(x + y <= 0) check[DOWN] = 0;
                if(-y - x <= 0) check[RIGHT] = 0;
            }
            
        }
        int j = 0;
        for(auto k : check){
            j += k;
        }
        if(j == 0) break;
    }
    for(auto k : check){
        if(k == 1){
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
    return 0;
}

