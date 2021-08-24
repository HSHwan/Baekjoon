// Data Structure - Deque
#include <iostream>
#include <deque>
using namespace std;

int N, K, L, X, dir = 0, t, game_time = 0, cnt;
char ch;
int D[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
// RIGHT, BOTTOM, LEFT, TOP 
int Apple[100][2];
deque<int> Tx;
deque<char> Dx;
deque<deque<int>> snake;

bool HitByHead(){
    if (snake[0][0] < 1 || snake[0][1] < 1)
        return true;
    if (snake[0][0] > N || snake[0][1] > N)
        return true;
    for (int i = 1; i < snake.size(); i++){
        if (snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1])
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < K; i++){
        cin >> Apple[i][0] >> Apple[i][1];
    }
    cin >> L;
    for (int i = 0; i < L; i++){
        cin >> t >> ch;
        Tx.push_back(t);
        Dx.push_back(ch);
    }
    deque<int> snake_head (2, 1);
    snake.push_front(snake_head);
    while (true){
        cnt = 0;
        snake_head[0] += D[dir][0];
        snake_head[1] += D[dir][1];
        snake.push_front(snake_head);
        game_time++;
        if (HitByHead())
            break;
        for (int i = 0; i < K; i++){
            if (snake[0][0] == Apple[i][0] && snake[0][1] == Apple[i][1]){
                Apple[i][0] = 0; 
                Apple[i][1] = 0;
                cnt++;
                break;
            }
        }
        if (!cnt){
            snake.pop_back();
        }
        if (!Tx.empty()){
            if (game_time == Tx.front()){
                if (Dx.front() == 'D'){
                    dir = (dir + 1) % 4;
                }
                else if (Dx.front() == 'L'){
                    if(!dir)
                        dir = 3;
                    else
                        dir--;
                }
                Tx.pop_front();
                Dx.pop_front();
            }
        }
    }
    cout << game_time;
}