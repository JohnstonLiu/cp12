#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define INF 1000000007

int A=31; int B=INF;
int* h;
int* p;
void hsh(string str) {
    ll hash=0;
    int n=str.length();
    for(int i=0; i<n; ++i) {
        ll pw=pow(A, n-i-1);
        h[i+1]=(hash+=str[i]*pw)%B;
        p[i+1]=pw%B;
    }
}

int id(int a, int b) {
   if(a==0) {
       return h[b];
   } 
   return(h[b]-h[a-1]*p[b-a+1])%B;
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
    int l1=needle.length();
    int l2=haystack.length();
    h=new int[l2+1];
    p=new int[l2+1];

    if(l1>l2){
        cout << 0;
        return 0;
    }

    for(int i=0; i<l1; ++i) {
        foo[haystack[i]-97]++;
    }
    hsh(haystack);
    if(check(dp, foo)){
        ans++;
        string temp=haystack.substr(0, l1);
        map[id(0, l1-1)]=true;
    }
    for(int i=0; i<l2-l1; ++i) {
        foo[haystack[i]-97]--;
        foo[haystack[i+l1]-97]++;
        if(check(dp, foo)){
            string str=haystack.substr(i+1, l1);
            int hash=id(i+1, i+l1);
            if(!map[hash]){
                ans++;
                map[hash]=true;
            }
        }
    }
    cout << ans;
}
