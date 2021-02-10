#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007
bool flag[11][10]={};
string grid[11][10]={};
void print() {
    for(int i=1; i<=10; ++i) {
        for(int j=1; j<=9; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
bool done[11][10]={};
int dfs(int r, int c) {
    string s=grid[r][c];
    if((done[r][c] && s[0]>=65 )|| s=="*") {
        grid[r][c]="*";
        return -1;
    }
    done[r][c]=true;
    if(!(s[0]>=65 && s[0]<=74))return stoi(grid[r][c]);
    int sum=0;
    for(int i=0; i<s.length(); i+=3) {
        string str=s.substr(i, 2);
        int a=str[0]-64; int b=str[1]-48;
        int x=dfs(a, b);
        if(x<0)return -1;
        sum+=x;
    }
    grid[r][c]=to_string(sum);
    return sum;
}

int main() {
    for(int i=1; i<=10; ++i) {
        for(int j=1; j<=9; ++j) {
            string str;
            cin >> str;
            grid[i][j]=str;
            if(str[0]>=65 && str[0]<=74)flag[i][j]=true;
        }
    }

    for(int i=1; i<=10; ++i) {
        for(int j=1; j<=9; ++j) {
            if(flag[i][j]) {
                int x=(dfs(i, j));
                if(x<0)grid[i][j]="*";
                else grid[i][j]=to_string(x);
            }
        }
    }
    
    print();
}
