#include <bits/stdc++.h>
#define DEBUG true
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;
double memory = 0; //debug usage (don't delete)
const int safe = 2e9 + 1;

signed main() {
    if(DEBUG){
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    else{
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
    int n, k;
    cin>>n>>k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        cin>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int l = 0, r = safe;
    while(l < r){
        int mid = l + (r - l) / 2;
        int cnt = k;
        for(int i = 0; i < n; i++){
            int x = a[i] * mid;
            cnt -= max(0ll, x - b[i]);
            memory += sizeof(x);
        }
        if(cnt <= 0){
            r = mid;
        }
        else{
            l = mid + 1;
        }
        memory += sizeof(mid) + sizeof(cnt);
    }
    cout<<l<<endl;
    /*---debug section---*/
    memory += sizeof(n) + sizeof(k) + sizeof(a) + sizeof(b) + sizeof(l) + sizeof(r);
    if(DEBUG){
        cout<<"Runtime: "<<((double)clock() / CLOCKS_PER_SEC) * 1000<<" ms"<<endl;
        cout<<"Memory: "<<memory / (memory > 1024 ? 1024 : 1)<<(memory > 1024 ? " KB" : " Bytes")<<endl;
    }
}