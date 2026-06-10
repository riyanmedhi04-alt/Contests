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
    cin  >> t;
    while(t--){
        int n, x, y, z;
        cin >> n >> x >> y >> z;
        int ans1, ans2;
        if(n%(x+y) == 0){
            ans1 = n/(x+y);
        }else{
            ans1 = n/(x+y) +1;
        }
        int rem = n - z*x;
        int p = x+(10*y);
        if(rem%p == 0){
            ans2 = z + rem/p;
        }else{
            ans2 = z+ rem/p +1;
        }
        cout << min(ans1,ans2) << "\n";
    }
    return 0;

}
