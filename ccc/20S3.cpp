#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define INF 1000000007
#define F first
#define S second
#define PB push_back
#define MP make_pair
bool check(int a[], int b[]) {
    for(int i=0; i<26; ++i) {
        if(a[i]!=b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string needle;
    getline(cin, needle);
    string haystack;
    getline(cin, haystack);

    int ans=0;
    int dp[26]={};
    int foo[26]={};
    unordered_map<string, bool> hash={};
    for(char c : needle) {
        ++dp[c-97];
    }
    int n=needle.length();
    int h=haystack.length();

    if(n>h){
        cout << 0;
        return 0;
    }

    for(int i=0; i<n; ++i) {
        foo[haystack[i]-97]++;
    }
    if(check(dp, foo)){
        ans++;
        string temp=haystack.substr(0, n);
        hash[temp]=true;
    }
    for(int i=0; i<h-n; ++i) {
        foo[haystack[i]-97]--;
        foo[haystack[i+n]-97]++;
        if(check(dp, foo)){
            string str=haystack.substr(i+1, n);
            if(!hash[str]) {
                hash[str]=true;
                ans++;
            }
        }
    }
    cout << ans;
}