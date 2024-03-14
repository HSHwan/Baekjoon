// Queue or Stack
#include <iostream>
#include <deque>
#include <stack>
#include <string>
using namespace std;

string str, bomb;
int bomb_len;

int main() {
    cin >> str >> bomb;
    if (str.length() < bomb.length()){
        cout << str;
        return 0;
    }
    deque<char> RestS;
    stack<char> Explo;
    bomb_len = bomb.length();
    for (int i = 0; str[i] != '\0'; i++){
        RestS.push_back(str[i]);
        if (str[i] == bomb[bomb_len-1] && RestS.size() >= bomb_len){
            for (int j = bomb_len-1; j >= 0 && !RestS.empty(); j--){
                if (bomb[j] == RestS.back()){
                    Explo.push(RestS.back()); 
                    RestS.pop_back();
                }
                else {
                    while (!Explo.empty()){
                        RestS.push_back(Explo.top());
                        Explo.pop();
                    }
                    break;
                }
            }
            while(!Explo.empty()){Explo.pop();}
        }
    }
    if (RestS.empty())
        cout << "FRULA";
    else {
        while(!RestS.empty()){
            cout << RestS.front();
            RestS.pop_front();
        }
    }
}