#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
// idea is to just print the elements in reverse order from 2n than obviously the elements wont be equal to each other or to the sum of its adjacents.
// *by observation*

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i<n; i++){
            cout << 2*n - i << " ";
        }
        cout << "\n";
    }
    return 0;

}
