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
        long long n, a, b;
        cin >> n >> a >> b;
        // the costs possibles ->
        long long cost1 = n*min(a,b);
        long long cost2 = (n/2)*b + (n - (n/2)*2)*(min(a,b));
        long long cost3 = (n/3)*b + (n- (n/3)*3)*(min(a,b));
        long long cost4 = (n/3)*b + ((n - (n/3)*3)/2)*b + (n - (n/3)*3 - ((n - (n/3)*3)/2)*2)*(min(a,b));
        cout << min(cost1,min(cost2,min(cost3,cost4))) << "\n";
    }
    return 0;
}
