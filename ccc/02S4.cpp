#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> K >> N;
    int a[N+1];
    vector<string> names;
    for(int i=0; i<N; ++i) {
        string temp;
        cin >> temp;
        names.push_back(temp);
        cin >> a[i];
    }
    int R=N%K;
    int k[20]={};
    int r[100]={};

    int m=0;
    for(int i=0; i<=N; ++i) {
        if(i!=0 && i%K==0) {
            k[i-K]=m;
            m=0;
        }
        m=max(m, a[i]);
    }
    m=0;
    for(int i=R; i<=N; ++i) {
        if(i-R!=0 && (i-R)%K==0) {
            k[i-K]=m;
            m=0;
        }
        m=max(m, a[i]);
    }
    m=0;
    int counter=1;
    for(int i=0; i<=N; ++i, ++counter) {
        if(i!=0 && counter==R+1) {
            r[i-R]=m;
            counter=1;
            m=0;
            i+=(K-R);
        }
        m=max(m, a[i]);
    }
    int format=0;
    int sum=0;
    sum+=r[0];
    for(int i=R; i<N; i+=K) {
        sum+=k[i];
    }
    int current=sum;
    for(int i=0; i+K<N-1; i+=K) {
        current-=r[i];
        current+=k[i];
        current-=k[i+R];
        current+=r[i+K];
        if(current<sum) {
            sum=current;
            format=i+K;
        }
    }
    int final=0;
    for(int i=0; i<N-R; i+=K) {
        final+=k[i];
    }
    final+=r[N-R];
    if(sum>final) {
        sum=final;
        format=N-R;
    }

    string outlier="";
    for(int i=format; i<format+R; ++i) {
        outlier+=names[i]+" ";
        names[i]="";
    }
    for(int i=0; i<names.size(); ++i) {
        if(names[i]=="") {
            names.erase(names.begin()+i);
            i--;
        }
    }
    outlier+="\n";
    names.push_back("");
    cout << "Total Time: " << sum << "\n";
    string output="";

    for(int i=0; i<names.size(); i++) {
        if(i!=0 && i%K==0){
            output+="\n";
        }
        if(i==format) {
            output+=outlier;
        }
        if(!names[i].empty()) {
            output+=names[i]+" ";
        }
    }
    if(output[output.size()-1]=='\n') {
        output=output.substr(0, output.size()-2);
    }
    cout << output;
}
