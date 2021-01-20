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
    //a[h]-a[i], a[i] is exclusive a[h] is inclusive
    //h/j/k-n = excess length to loop around
    int ans=INT_MAX;
    for(int i=0; i<n; ++i) {
        int ac, ab, bc, ba, ca, cb;
        int h=i+aStep;
        if(h>n) {
            h=h%n;
            ab=(b[n]-b[i])+(b[h]);
            ac=(c[n]-c[i])+c[h];
        }else {
            ab=b[h]-b[i]; ac=c[h]-c[i];
        }

        int j=h+bStep;
        if(j>n) {
            j=j%n;
            ba=(a[n]-a[h])+a[j];
            bc=(c[n]-c[h])+c[j];
        }else {
            ba=a[j]-a[h]; bc=c[j]-c[h];
        }

        int k=j+cStep;
        if(k>n) {
            k=k%n;
            ca=(a[n]-a[j])+a[k];
            cb=(b[n]-b[j])+b[k];
        }else {
            ca=a[k]-a[j]; cb=b[k]-b[j];
        }

        int an=max(ab, ba)+ca+cb;
        ans=min(ans, an);
    }
    for(int i=0; i<n; ++i) {
        int ac, ab, bc, ba, ca, cb;
        int h=i+aStep;
        if(h>n) {
            h=h%n;
            ab=(b[n]-b[i])+(b[h]);
            ac=(c[n]-c[i])+c[h];
        }else {
            ab=b[h]-b[i]; ac=c[h]-c[i];
        }

        int j=h+cStep;
        if(j>n) {
            j=j%n;
            ca=(a[n]-a[h])+a[j];
            cb=(b[n]-b[h])+b[j];
        } else {
            ca=a[j]-a[h]; cb=b[j]-b[h];
        }

        int k=j+bStep;
        if(k>n) {
            k=k%n;
            ba=(a[n]-a[j])+a[k];
            bc=(c[n]-c[j])+c[k];
        }else {
            ba=a[k]-a[j]; bc=c[k]-c[j];
        }

        int an=max(ac, ca)+ba+bc;
        ans=min(ans, an);
    }
    cout << ans;
}
