#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 301

using namespace std;

int n, m;
int board[MAX][MAX];
int dp[MAX][MAX];

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> board[i][j];
        }
    }
}

bool check(int x, int y){
    if(1 <= x && x <= n && 1 <= y && y <= m) return true;
    return false;
}


int main(){
    input();
    for(int i = 1;i <= n;i++){
        dp[i][0] = 0;
        dp[i][1] = board[i][1];
        for(int j = 2;j <= m;j++){
            dp[i][j] = dp[i][j - 1] + board[i][j];
        }
    }
    int answer = 0;
    for(int a = 1;a <= m;a++){
        for(int b = 1;b <= n;b++){
            if(a * b > 10) continue;
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= m;j++){
                    int sum = 0;
                    if(check(i + b - 1, j + a - 1)){
                        for(int k = i;k <= i + b - 1;k++) sum += (dp[k][j + a - 1] - dp[k][j - 1]);
                        if(sum == 10) answer++;
                    }
                }
            }
        }
    }
    cout << answer << '\n';
}
