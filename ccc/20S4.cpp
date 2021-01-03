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
        int h=i+aStep;
        int ab=b[h]-b[i]; int ac=c[h]=c[i]; 
        if(h>n) {
            int q=h%n;
            h-=(n*q);
            ab=(b[n]-b[i])+(b[h]);
            ac=(c[n]-c[i])+c[h];
        }
        int j=h+bStep;
        int ba=a[j]-a[h]; int bc=c[j]=c[h]; 
        if(j>n) {
            int q=j%n;
            j-=(n*q);
            ba=(a[n]-a[h])+a[j];
            bc=(c[n]-c[h])+c[j];
        }
        int k=j+cStep;
        int ca=a[k]-a[j]; int cb=b[k]-b[j];
        if(k>n) {
            int q=k%n;
            k-=(n*q);
            ca=(a[n]-a[j])+a[k];
            cb=(b[n]-b[j])+b[k];
        }

        int an=max(ab+ac, ba+bc)+ca+cb;
        ans=min(ans, an);
    }
    for(int i=0; i<n; ++i) {
        int h=i+aStep;
        int ab=b[h]-b[i]; int ac=c[h]=c[i]; 
        if(h>n) {
            int q=h%n;
            h-=(n*q);
            ab=(b[n]-b[i])+(b[h]);
            ac=(c[n]-c[i])+c[h];
        }
        int j=h+cStep;
        int ca=a[j]-a[h]; int cb=b[j]-b[h]; 
        if(j>n) {
            int q=j%n;
            j-=(n*q);
            ca=(a[n]-a[h])+a[j];
            cb=(b[n]-b[h])+b[j];
        }
        int k=j+bStep;
        int ba=a[k]-a[j]; int bc=c[k]-c[j];
        if(k>n) {
            int q=k%n;
            k-=(n*q);
            ba=(a[n]-a[j])+a[k];
            bc=(c[n]-c[j])+c[k];
        }

        int an=max(ab+ac, ca+cb)+ba+bc;
        ans=min(ans, an);
    }
    cout << ans;
}
