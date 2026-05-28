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

        // total -> total number of cards
        // cnt_not_1s -> total cards belonging to values with frequency >= 2
        // cnt1 -> number of values having frequency exactly 1
        long long total = 0, cnt_not_1s = 0, cnt1 = 0;

        // flag remains true if every frequency is 1
        bool flag = true;

        vector<long long> v(n);

        for(int i = 0; i<n; i++){
            cin >> v[i];

            total += v[i];

            // frequencies >= 2 are always useful
            if(v[i] >= 2){
                flag = false;
                cnt_not_1s += v[i];
            }
            else{
                cnt1++;
            }
        }

        // impossible to make a valid circle
        // either total cards < 3
        // or every frequency is 1
        if(total < 3 || flag){
            cout << 0 << "\n";
            continue;
        }

        // only one distinct value exists
        // all cards can be used
        if(n == 1){
            cout << v[0] << "\n";
            continue;
        }

        // special case:
        // only one value has frequency >= 2
        // because array is sorted
        if(v[n-2] == 1){

            // maximum number of single-frequency values
            // we can insert safely
            long long maxm_ones = v[n-1]/2;

            if(cnt1 >= maxm_ones){
                cout << v[n-1] + maxm_ones << "\n";
            }
            else{
                cout << v[n-1] + cnt1 << "\n";
            }

            continue;
        }

        // start answer with all frequencies >= 2
        long long ans = cnt_not_1s;

        // try inserting values having frequency 1
        for(int i = n-1; i>=0; i--){

            if(v[i] != 1){

                // a group of size x can absorb
                // at most (x/2)-1 single elements
                if(cnt1 >= (v[i]/2)-1){

                    ans += (v[i]/2)-1;
                    cnt1 -= (v[i]/2)-1;
                }
                else{

                    // use remaining single elements
                    ans += cnt1;
                    cnt1 = 0;
                }
            }
            else{
                break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
