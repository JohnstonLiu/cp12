#include <bits/stdc++.h>
using namespace std;

int main() {
    //min(a-c, c-a)+min(a-b, b-a)+min(b-c, c-b)
    string str;
    getline(cin, str);
    int n=str.length();
    int a[1000000]={};
    int b[1000000]={};
    int c[1000000]={};
    int aStep=0, bStep=0, cStep=0;
    for(int i=0; i<n; ++i) {
        if(str[i]=='A') {
            aStep++;
        }else if(str[i]=='B') {
            bStep++;
        }else if(str[i]=='C') {
            cStep++;
        }
    }

    for(int i=0; i<n; ++i) {
        for(int j=i; j<i+aStep; ++j) {
            a[j]++;
        }
        for(int j=i; j<i+bStep; ++j) {

        }
        for(int j=i; j<i+cStep; ++j) {

        }
    }


    //three arrays for each letter representing how many are in the range from the i starting point
    //triplet or sth for each index
}
