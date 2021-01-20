#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll* h; ll* p;
ll* h1; ll*p1;
const ll A=31; const ll B=1e9+9;
const ll A1=31; const ll B1=972663749;
void init(string str) {
    h[0]=str[0];
    p[0]=1;
    for(int i=1; i<str.length(); ++i) {
        h[i]=(((h[i-1]*A+str[i])%B)+B)%B;
        p[i]=(((p[i-1]*A)%B)+B)%B;
    }
}

void init1(string str) {
    h1[0]=str[0];
    p1[0]=1;
    for(int i=1; i<str.length(); ++i) {
        h1[i]=(((h1[i-1]*A1+str[i])%B1)+B1)%B1;
        p1[i]=(((p1[i-1]*A1)%B1)+B1)%B1;
    }
}

ll hsh(int a, int b) {
    if(a==0) {
        return h[b];
    }
    return (((h[b]-h[a-1]*p[b-a+1])%B)+B)%B;
}

ll hsh1(int a, int b) {
    if(a==0) {
        return h1[b];
    }
    return (((h1[b]-h1[a-1]*p1[b-a+1])%B1)+B1)%B1;
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
    unordered_map<ll, bool>map;
    unordered_map<ll, bool>map1;

    for(char c : needle) {
        ++dp[c-97];
    }
    int l1=needle.length();
    int l2=haystack.length();
    h=new ll[l2]; p=new ll[l2];
    h1=new ll[l2]; p1=new ll[l2];

    if(l1>l2){
        cout << 0;
        return 0;
    }

    for(int i=0; i<l1; ++i) {
        foo[haystack[i]-97]++;
    }
    init(haystack);
    init1(haystack);
    ll hash;
    ll hash1;
    if(check(dp, foo)){
        ans++;
        hash=hsh(0, l1-1);
        hash1=hsh1(0, l1-1);
        map[hash]=true;
        map1[hash1]=true;
    }
    for(int i=1; i<l2-l1+1; ++i) {
        foo[haystack[i-1]-97]--;
        foo[haystack[i+l1-1]-97]++;
        if(check(dp, foo)){
            hash=hsh(i, i+l1-1);
            hash1=hsh1(i, i+l1-1);
            if(map[hash] && map1[hash1]){
                continue;
            }else {
                ans++;
                map[hash]=true;
                map1[hash1]=true;
            }
        }
    }
    cout << ans;
}
