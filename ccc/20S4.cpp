#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int n=str.length();
    int a[n+1];
    int b[n+1];
    int c[n+1];
    int aStep=0, bStep=0, cStep=0;
    for(int i=0; i<n; ++i) {
        a[0]=0;
        b[0]=0;
        c[0]=0;
        if(str[i]=='A') {
            aStep++;
        }else if(str[i]=='B') {
            bStep++;
        }else if(str[i]=='C') {
            cStep++;
        }
        a[i+1]=aStep;
        b[i+1]=bStep;
        c[i+1]=cStep;
    }
    //min(a-c, c-a)+min(a-b, b-a)+min(b-c, c-b)

    int ans=INT_MAX;
    for(int i=0; i<n; ++i) {
        int h=i+aStep;
        int ab=b[h]-b[i]; int ac=c[h]=c[i]; int ba=a[j]-a[h]; int bc=c[j]=c[h]; int ca=a[k]-a[j]; int cb=b[k]-b[j];
        if(h>n) {
            h-=n;
            ab=(b[n]-b[i])+(b[h]);
            ac=(c[n]-c[i])+c[h];
        }
        int j=h+bStep;
        if(j>n) {
            j-=n;
            ba=(a[j]-a[h])+
        }
        int k=j+cStep;
        if(k>n) {
            k-=n;
        }

        int an=max(ab+ac, ba+bc)+ca+cb;
        ans=min(ans, an);
    }
    for(int i=0; i<n; ++i) {
        int an=max((b[i+aStep]-b[i])+(c[i+aStep]-c[i]), ((a[i+aStep+bStep]-a[i+aStep])+c[i+aStep+bStep]-c[i+aStep]));
    }
    //max(!a, !b)+!c


    /*
    for(int i=0; i<aStep+bStep+cStep; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i=0; i<aStep+bStep+cStep; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    for(int i=0; i<aStep+bStep+cStep; ++i) {
        cout << c[i] << " ";
    }
    cout << endl;
    */

    /*
    for(int i=0; i<n; ++i) {
        for(int j=i; j<i+aStep; ++j) {
            a[j]++;
        }
        for(int j=i; j<i+bStep; ++j) {

        }
        for(int j=i; j<i+cStep; ++j) {

        }
    }
     */


    //three arrays for each letter representing how many are in the range from the i starting point
    //triplet or sth for each index
}
