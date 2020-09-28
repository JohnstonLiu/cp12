#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ii> vii;

int T, G;
int score[5];
vii v;

int r(int i, int left, int* s) {
    if(left==0) {
        int temp=s[T];
        sort(s, s+5);
        if(temp==s[4] && s[3]!=s[4]) {
            return 1;
        }
        return 0;
    }
    int a=v[i].first; int b=v[i].second;

    int s1[]={0, s[1], s[2], s[3], s[4]};
    s1[a]+=3;

    int s2[]={0, s[1], s[2], s[3], s[4]};
    s2[b]+=3;

    int s3[]={0, s[1], s[2], s[3], s[4]};
    s3[a]+=1; s3[b]+=1;

    return r(i+1, left-1, s1)+r(i+1, left-1, s2)+r(i+1, left-1, s3);
}

int main() {
    for(int i=0; i<5; ++i) {
        score[i]=0;
    }
    cin >> T >> G;

    v={make_pair(1, 2), make_pair(1,3), make_pair(1, 4), make_pair(2, 3),
       make_pair(2, 4), make_pair(3, 4)};

    for(int i=0; i<G; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ii temp;
        temp.first=min(a, b);
        temp.second=max(a, b);
        //auto j=find(v.begin(), v.end(), temp);
        //v.erase(v.begin()+distance(v.begin(), j));
        v.erase(remove(v.begin(), v.end(), temp), v.end());

        if(c>d) {
            score[a]+=3;
        }else if(c<d) {
            score[b]+=3;
        }else {
            score[a]+=1; score[b]+=1;
        }
    }

    cout << r(0, 6-G, score);
}
