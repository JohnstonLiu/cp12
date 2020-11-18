#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, Q;
    cin >> M >> Q;

    int nums[Q];
    string names[Q];

    for(int i=0; i<Q; ++i) {
        //if this doesn't work try out the brute force method
        //if its divisible you already know M
        cin >> names[i];
        cin >> nums[i];
    }
    int minSum=INT_MAX;
    for(int i=-1; i<M-1; ++i) {
        int section=0;
        int totalSum=0;
        for(int j=i+1; j<Q; j+=M) {
            for(int k=j; k<min(j+M, Q); ++k) {
                section=max(section, nums[k]);
            }
            totalSum+=section;
            section=0;
        }

        int skippedSum=0;
        for(int j=0; j<=i; ++j) {
            skippedSum=max(skippedSum, nums[j]);
        }
        minSum=min(minSum, totalSum+skippedSum);
    }

    cout << "Total Time: " << minSum << "\n";
}