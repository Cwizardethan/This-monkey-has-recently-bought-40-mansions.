#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG true

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n, k, mini = 0, maxi = 1;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            if(i > 0){
                if(arr[i] != arr[i-1]){
                    mini ^= 1;
                    maxi ^= 1;
                }
            }
        }
        maxi++;
        cout<<mini<<' '<<maxi<<endl;
    }
}