#include <bits/stdc++.h>
using namespace std;
vector<int> table[10001]={};
int ar[10001]={};

int main() {
    int n; cin >> n;

    ar[1]=1;

    while(true) {
        int a, b;
        cin >> a >> b;
        if(a==0 && b==0) {
            break;
        }
        table[a].push_back(b);
    }

    for(int i=1; i<=n; ++i) {
        for(int j=0; j<table[i].size(); ++j) {
             ar[table[i].at(j)]+=ar[i];
        }
    }

    cout << ar[n];
}