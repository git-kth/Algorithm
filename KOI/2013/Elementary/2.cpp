#include <iostream>
#include <algorithm>

#define N_MAX 2001
#define M_MAX 10001

typedef struct{
    int start, end, cnt;
}BOX;

using namespace std;

int N, C, M;
int capacity[N_MAX];
BOX box[M_MAX];

bool comp(const BOX &a, const BOX &b) {
    if(a.end == b.end) return a.start < b.start;
    else return a.end < b.end;
}

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> C >> M;
    for(int i = 1;i <= M;i++){
        cin >> box[i].start >> box[i].end >> box[i].cnt;
    }
}

int min_value(int x, int y){
    int m = 987654321;
    for(int i = x;i <= y;i++){
        m = min(m, capacity[i]);
    }
    return m;
}

int main(){
    input();
    sort(box + 1, box + M + 1, comp);
    fill(capacity + 1, capacity + N + 1, C);
    int answer = 0;
    for(int i = 1;i <= M;i++){
        int start, end, cnt;
        start = box[i].start; end = box[i].end; cnt = box[i].cnt;
        int t = min_value(start, end - 1);
        if(t >= cnt){
            for(int i = start;i < end;i++){
                capacity[i] -= cnt;
            }
            answer += cnt;   
        }else{
            for(int i = start;i < end;i++){
                capacity[i] -= t;
            }
            answer += t;
        }
    }

    cout << answer << '\n';
    return 0;
}
