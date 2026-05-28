#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
// the idea here is that every number has a path for eg -> 7->8->4->2->1->2->1.. && 11->12->6->3->4->2->1..
// we can notice that 2 and 1 are the common path that every number has. so we can take them as the target for every path to finish.
// note that 2 can be obtained by 1 operation in 1 and similarly 1 can be obtained by 1 operation in 2.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> v(n);
        set<long long> s;
        map<long long,long long> m;
        map<long long, long long> cnt;
        for(int i = 0; i<n; i++){
            cin >> v[i];
        }
        // sorted the array
        sort(v.begin(),v.end());
        // we will first look at the path of the smallest element as for every other number in the array they have to be in its path and consider only the elements in its path as the target elements for other elements.
        // we will store those elements in the path of the first elements in a set.
        // two maps -> one (m)for storing total operations required for that number in each element of the array and one (cnt) for keeping the track of that number if it is common for all the elements or not, it is common if its count == n.
        long long temp = v[0];
        //  1 & 2 are the common ones ->
        s.insert(1);
        s.insert(2);
        long long ops = 0;
        bool flag = true;
        // for smallest element->
        // first checking if the element is 1 or 2->
        if(temp == 2){
            m[1]++;
            m[2] = 0;
            cnt[2]++;
            cnt[1]++;
            flag = false;
        }
        if(temp == 1){
            m[2]++;
            m[1] = 0;
            cnt[1]++;
            cnt[2]++;
            flag = false;
        }
        // if the element is not itself 1 or 2 then looping till its 2 and counting the operations required-> 
        while(temp != 2 && flag){
            s.insert(temp);
            m[temp] = ops;
            cnt[temp]++;
            if(temp %2 == 0){
                temp /= 2;
                ops++;
            }else{
                temp += 1;
                ops++;
            }
        }
        if(flag){
            m[2] = ops;
            cnt[2]++;
            m[1] = ops+1;
            cnt[1]++;
        }
        // for other elements -> 
        for(int i = 1; i<n; i++){
            long long ops1 = 0;
            long long temp1 = v[i];
            // always checking for element if its 1 or 2 seperately ->
            if(temp1 == 1){
                m[2]++;
                cnt[2]++;
                cnt[1]++;
                continue;
            }
            if(temp1 == 2){
                m[1]++;
                cnt[1]++;
                cnt[2]++;
                continue;
            }
            // looping until the element is 2 because then 1 can be obtained by one more operation ->
            while(temp1 != 2){
                if(s.find(temp1) != s.end()){
                    m[temp1] += ops1;
                    cnt[temp1]++;
                }
                if(temp1%2 == 0){
                    temp1 /= 2;
                    ops1++;
                }else{
                    temp1 += 1;
                    ops1++;
                }
            }
            m[2] += ops1;
            cnt[2]++;
            m[1] += ops1 +1;
            cnt[1]++;
        }
        long long ans = INT_MAX;
        for(auto x : m){
            if(cnt[x.first] != n){
                continue;
            }
            ans = min(ans, x.second);
        }
        cout << ans << "\n";
    }
    return 0;
}
