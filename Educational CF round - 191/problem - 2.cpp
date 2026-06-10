#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 2){
            cout << 2 << " " << 1 << " " << 1 << " " << 2 << " " << 2 << " " << 1 << " " << 2 << " " << 1 << "\n";
            continue;
        }
        vector<int> v;
        v.push_back(n);
        v.push_back(1);
        v.push_back(1);
        v.push_back(2);
        v.push_back(1);
        int x = (4*n - 5)/4;
        int p = 2;
        for(int i = 0; i<x; i++){
            v.push_back(p);
            v.push_back(p);
            v.push_back(p+1);
            v.push_back(p-1);
            p++;
        }
        v.push_back(n);
        v.push_back(n);
        v.push_back(n-1);
        for(int i = 0; i<(4*n); i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    }
}
