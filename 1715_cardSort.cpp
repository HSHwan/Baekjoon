#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

int N, input, card_sort = 0, card_merge, cardSize, McardSize;
deque<int> card;
queue<int> merged_card;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> input;
        card.push_back(input);
    }

    sort(card.begin(), card.end());
    
    cardSize = card.size(); McardSize = merged_card.size();
    while ((cardSize + McardSize) > 1){
        card_merge = 0;
        if(!McardSize){
            card_merge += card.front(); card.pop_front();
            card_merge += card.front(); card.pop_front();
        }

        else if(!cardSize){
            card_merge += merged_card.front(); merged_card.pop();
            card_merge += merged_card.front(); merged_card.pop();
        }

        else {
            for(int i = 0; i < 2; i++){
                if (card.front() <= merged_card.front()){
                    card_merge += card.front();
                    card.pop_front();
                    if (card.empty() && !i){
                        card_merge += merged_card.front();
                        merged_card.pop();
                        break;
                    }
                }
                else {
                    card_merge += merged_card.front();
                    merged_card.pop();
                    if (merged_card.empty() && !i){
                        card_merge += card.front();
                        card.pop_front();
                        break;
                    }
                }
            }
        }
       
        card_sort += card_merge;
        merged_card.push(card_merge);
        cardSize = card.size(); McardSize = merged_card.size();
    }

    cout << card_sort;
}