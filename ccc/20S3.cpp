#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define INF 1000000007

int A=31; int B=INF;
int* h;
int* p;
ll hsh(string str) {
    int n=str.length();
    ll hash=0;
    ll pp=0;
    for(int i=0; i<n; ++i) {
        int x=pow(A, n-1-i);
        hash+=str[i]*x;
        pp+=x;
        h[i]=hash;
        p[i]=pp;
    }
    return hash;
}

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
    unordered_map<int, bool>map;

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
    hsh(haystack);
    if(check(dp, foo)){
        ans++;
        string temp=haystack.substr(0, n);
        map[hash]=true;
    }
    for(int i=0; i<h-n; ++i) {
        foo[haystack[i]-97]--;
        foo[haystack[i+n]-97]++;
        if(check(dp, foo)){
            string str=haystack.substr(i+1, n);
            if(!map[hash]) {
                ans++;
                map[hash]=true;
            }
        }
    }
    cout << ans;
}
