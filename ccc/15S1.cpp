#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; long long m;
    cin >> n >> m;
    vector<long long> v;
    for(int i=0; i<n; ++i) {
        long long a; cin >> a;
        if(a<=m) {
            v.push_back(a);
        }
    }
    long long counter=0;
    sort(v.begin(), v.end());
    if(!v.empty()) {
        for(long long i=0, j=v.size()-1; i!=j;){
            if(v[j]+v[i]<=m) {
                counter+=j-i;
                i++;
            }else {
                j--;
            }
        }
    }
    if(counter>=1000000007) {
        cout << counter%(1000000007);
        return 0;
    }
    cout << counter;
}
