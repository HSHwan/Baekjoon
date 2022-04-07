// DFS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, C;
vector<char> crypto_chr, crypt;

void dfs(int d){
    if (crypt.size() == L){
        int vowelNum = 0;
        for (int i = 0; i < L; i++){
            if (crypt[i] == 'a' || \
                crypt[i] == 'e' || \
                crypt[i] == 'i' || \
                crypt[i] == 'o' || \
                crypt[i] == 'u' ){
                vowelNum++;
            }
        }
        if (vowelNum >= 1 && L - vowelNum >= 2){
            for (auto& ch : crypt)  cout << ch;
            cout << "\n";
        }
    }

    for (int i = d; i < C; i++){
        crypt.push_back(crypto_chr[i]);
        dfs(i+1);
        crypt.pop_back();
    }

}

int main(){
    cin >> L >> C;
   
    char ch;
    for (int i = 0; i < C; i++){
        cin >> ch;
        crypto_chr.push_back(ch);
    }

    sort(crypto_chr.begin(), crypto_chr.end());
    dfs(0);
}