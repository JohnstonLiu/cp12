#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007
pair<string, char> arr[20];
int n; int len=0;

bool solve(string str, string ans) {
    if(str=="") {
        cout << ans;
        return true;
    }
    for(int i=1; i<=len; ++i) {
       for(int j=0; j<n; ++j) {
           if(arr[j].first==str.substr(0, i)) {
               if(solve(str.substr(i), ans+arr[j].second)) {
                   exit(0);
               }
           }
       }
    }
    return false;
}

int main() {
    cin >> n;
    for(int i=0; i<n; ++i) {
        char c; cin >> c;
        string s; cin >> s;
        len=max(len, (int)s.length());
        arr[i]={s, c};
    }
    string seq; cin >> seq;
    solve(seq, "");
}
