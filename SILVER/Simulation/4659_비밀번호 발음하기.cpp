#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
vector<string> passwords;
vector<string> evaluateResults;

bool isVowel(const char& ch) {
    return find(vowels.begin(), vowels.end(), ch) != vowels.end();
}

bool isSameChar(const char& ch1, const char& ch2) {
    return ch1 != 'e' && ch1 != 'o' && ch1 == ch2;
}

bool isThreeCount(const int& cons, const int& vow) {
    return cons == 3 || vow == 3;
}

void input(){
    string inputStr;
    cin >> inputStr;
    while (inputStr != "end") {
        passwords.push_back(inputStr);
        cin >> inputStr;
    }
}

void solve(){
    const string ACCEPT = "acceptable";
    for (string password : passwords) {
        bool acceptCheck = false;
        int consCount = 0, vowelCount = 0;
        char prevChar = ' ';
        FOR(i, password.length()) {            
            if (isVowel(password[i])) {
                vowelCount++;
                consCount = 0;
                acceptCheck = true;
            } else {
                consCount++;
                vowelCount = 0;
            }
            if (isSameChar(prevChar, password[i]) || isThreeCount(consCount, vowelCount)) {
                acceptCheck = false;
                break;
            }
            prevChar = password[i];
        }
        if (acceptCheck) {
            evaluateResults.push_back(ACCEPT);
        } else {
            evaluateResults.push_back("not " + ACCEPT);
        }
    }
}

void output(){
    FOR(i, passwords.size()) {
        cout << "<" + passwords[i] + ">" + " is " + evaluateResults[i] + ".\n";
    }
}

int main(){
    input ();
    solve ();
    output();
}