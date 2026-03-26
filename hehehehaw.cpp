#include <bits/stdc++.h>
#define DEBUG true
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;
int n, a, b, k;

signed main(){
    if(!DEBUG){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    else{
        (void)freopen("test.in", "r", stdin);
        (void)freopen("test.out", "w", stdout);
    }
    cin>>n>>a>>b>>k;
    vector<int> arr(n), cnt(n);
    for(int i = 0; i < n; ++i){
        cin>>arr[i];
        cnt[i] = arr[i] % (a + b);
        if(cnt[i] == 0){
            cnt[i] = max(0LL, (long long)ceil((double)(a + b) / a) - 1);
        }
        else{
            cnt[i] = max(0LL, (long long)ceil((double)cnt[i] / a) - 1);
        }
    }
    sort(cnt.begin(), cnt.end());
    int ans = 0, cnt1 = 0;
    for(int i = 0; i < n; i++){
        if(cnt1 + cnt[i] <= k){
            ans++;
            cnt1 += cnt[i];
        }
        else{
            break;
        }
    }
    cout<<ans<<endl;
}