#include <bits/stdc++.h>
using namespace std;

int M, Q;
int* nums;
string* names;
int maxNum[101][101]={};
vector<int> sizes;


//try graph theory using predeccessor tree
int foo(int a, int b) {
    if(a>=Q) {
        return 0;
    }
    int ret=INT_MAX;
    for(int i=M-1; i>=0; --i) {
        ret=min(ret, maxNum[a][a+i]+foo(a+i+1, min(b, Q)));
    }
    return ret;
}

int main() {
    cin >> M >> Q;

    nums=new int[Q];
    names= new string[Q];
    for(int i=0; i<Q; ++i) {
        cin >> names[i];
        int num;
        cin >> num;
        nums[i]=num;
        maxNum[i][i]=num;
    }
    for(int k=0; k<Q; ++k) {
        for(int i=0, j=i+1+k; i<Q, j<Q; ++i, ++j) {
            maxNum[i][j]=max(maxNum[i][j-1], maxNum[i+1][j]);
        }
    }

   cout << foo(0, M-1);

}