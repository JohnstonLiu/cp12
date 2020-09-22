#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    vector<Node> v;
    int num;
    Node(){}
    Node(int n) {
        num=n;
    }

    void add(Node n) {
        v.push_back(n);
    }

    int at(int n) {
        return v.at(n).num;
    }

    int size() {
        return v.size();
    }

};
Node* a=new Node[10000]; //The index correlates to the Node number

int BFS(Node start, Node check) {
    int ret;
    int dest=start.num;
    queue<vector<int>> q;
    vector<int> v;
    v.push_back(start.num);
    q.push(v);
    set<int> s;
    bool flag=0;

    while(1) {
        v=q.front();
        q.pop();
        int len=v.size()-1;
        if(v.at(len)==check.num) {
            flag=true;
            ret=len;
        }
        if(v.at(len)==dest && flag) {
            return ret;
        }
        start=a[v.at(len)];

        //counter++; queue with arrays and delete set
        for(int i=0; i<start.size(); ++i) {
            if(s.count(start.at(i))==0) {
                s.insert(start.at(i));
                vector<int> v2(v.begin(), v.end());
                v2.push_back(start.at(i));
                q.push(v2);
            }
        }
        if(q.empty()){
            return -1;
        }
    }
}

int main() {
    for(int i=1; i<10000; ++i) {
        a[i]=Node(i);
    }
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].add(a[y]);
    }

    while(1) {
        int x, y;
        cin >> x >> y;
        if(x==0 && y==0){
            return 0;
        }
        int answer=BFS(a[x], a[y]);
        if (answer==-1) {
            cout << "No" << endl;
        } else {
            cout << "Yes " << answer-1 << endl;
        }
    }

}