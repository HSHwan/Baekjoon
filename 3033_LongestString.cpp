// Suffix Array
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#define FOR(i,b,n) for (int i = (b); i < (n); i++)
using namespace std;

vector<int> SA(string str){
    int n = str.length();
    vector<int> sa(n), r(n+1), nr(n+1);
    FOR(i,0,n){
        sa[i]=i;
        r[i]=str[i];
    }
    for(int d=1;d<n;d<<=1){
        auto cmp = [&](int i,int j){
            return r[i]<r[j] || (r[i]==r[j] && r[i+d]<r[j+d]); };
        sort(sa.begin(), sa.end(), cmp);

        nr[sa[0]] = 1;
        for(int i=1;i<n;++i)
            nr[sa[i]] = nr[sa[i-1]] + cmp(sa[i-1], sa[i]);
        r = nr;
    }
    return sa;
}

vector<int> LCP(string str){
    int n = str.length();
    vector<int> sa = SA(str), lcp(n), isa(n);
    FOR(i,0,n) isa[sa[i]] = i;
    for(int k=0, i=0;i<n;++i){
        if(isa[i]){
            for(int j=sa[isa[i]-1]; str[i+k]==str[j+k]; ++k);
            lcp[isa[i]] = (k ? k-- : 0);
        }
    } 
    return lcp;
}

int main(){
    int L;
	string str_in;
    cin >> L >> str_in;
    vector<int> SuffixArr = LCP(str_in);
    cout << *max_element(SuffixArr.begin(), SuffixArr.end());
}