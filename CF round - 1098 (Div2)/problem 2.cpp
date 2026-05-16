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
        long long n, x1, x2, k;
        cin >> n >> x1 >> x2 >> k;
        // since they are in circular manner so by intuition it will take only one second if n == 2 or 3.
        if(n<=3){
            cout << 1 << "\n";
            continue;
        }
        // clockwise distance between them-
        long long dist = abs(x1 - x2);
        // min distance between them among clockwise and anti - clockwise -
        long long d = min(dist, n - dist);
        // obviously remelia will take the longest distance between them to escape so rami will take the shortest gap
        // after that their distance will be constant as initial min dist i.e d till k steps are over
        // then rami will go the constant min initial dist gap between them to cover their distance and catch remelia.
        long long ans = d+k;
        cout << ans << "\n";

    }
    return 0;
    
}
