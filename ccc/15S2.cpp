#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007

class Node{
public:
    int s;
    int m;
    int l;
    Node() {
        s=0;
        m=0;
        l=0;
    }
};

int main() {
    int J, A;
    cin >> J >> A;
    Node* a[1000001]={};
    for (int i = 0; i < J; ++i) {
        char c;
        cin >> c;
        a[i+1]=new Node();
        if(c=='S') {
            a[i+1]->s++;
        }else if(c=='M') {
            a[i+1]->m++;
        }else if(c=='L') {
            a[i+1]->l++;
        }
    }
    int ans=0;
    for(int i=0; i<A; ++i) {
        char c; int num;
        cin >> c >> num;
        if(c=='S') {
            if(a[num]->s>0) {
                ans++;
                a[num]->s--;
            }else if(a[num]->l>0) {
                ans++;
                a[num]->l--;
            }else if(a[num]->m>0) {
                ans++;
                a[num]->m--;
            }
        }else if(c=='M') {
            if(a[num]->m>0) {
                ans++;
                a[num]->m--;
            }else if(a[num]->l>0) {
                ans++;
                a[num]->l--;
            }
        }else {
            if(a[num]->l>0) {
                ans++;
                a[num]->l--;
            }
        }
    }
    cout << ans;
}
