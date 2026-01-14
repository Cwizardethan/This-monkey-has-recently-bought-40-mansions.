#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG true
struct quantum{
    int x;
    int y;
    int z;
};
vector<bool> visited;
vector<quantum> qus;
vector<vector<pair<int, int>>> adj;
vector<pair<int, int>> val;
bool good = true;
const int inf = 0x3f3f3f3f3f3f3f3f;
bool cmp(quantum a, quantum b){
    return a.y < b.y;
}

void dfs(int u){
    visited[u] = true;
    for(auto [v, c]: adj[u]){
        if(v == u){
            if(c % 2 != 0 or (val[u].second < c / 2 or val[u].first > c / 2)){
                good = false;
                return;
            }
            val[u].first = c / 2;
            val[u].second = c / 2;
        }
        int l = c - val[u].second;
        int r = c - val[u].first;
        int lo = max(val[v].first, l);
        int hi = min(val[v].second, r);
        if(lo > hi){
            good = false;
            return;
        }
        if(!visited[v]){
            val[v].first = lo;
            val[v].second = hi;
            dfs(v);
        }
        else{
            if(val[v].first > hi or val[v].second < lo){
                good = false;
                return;
            }
        }
        //dfs(v);
    }
}

signed main(){
    if(!DEBUG){
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    }
    else{
        (void)freopen("test.in", "r", stdin);
        (void)freopen("test.out", "w", stdout); 
    }
    int t;
    cin>>t;
    while(t--){
        good = true;
        int n, m;
        cin>>n>>m;
        adj.assign(n, {});
        val.assign(n, {-inf, inf});
        visited.assign(n, false);
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i].first;
            val[i].first = arr[i].first;
        }
        for(int i = 0; i < n; i++){
            cin>>arr[i].second;
            val[i].second = arr[i].second;
        }
        //vector<quantum> qus(m);
        qus.resize(m);
        for(int i = 0; i < m; i++){
            cin>>qus[i].x>>qus[i].y>>qus[i].z;
            qus[i].x--; 
            qus[i].y--;
            adj[qus[i].x].push_back({qus[i].y, qus[i].z});
            adj[qus[i].y].push_back({qus[i].x, qus[i].z});
        }
        dfs(0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i] and good){
                dfs(i);
            }
        }
        
        //for(auto [a, b]: val){
            //cout<<a<<' '<<b<<endl;
        //}
        
        if(good){
            for(int i = 0; i < n; i++){
                if((val[i].first <= arr[i].first and val[i].second >= arr[i].first) or (val[i].first <= arr[i].second and val[i].second >= arr[i].second)){
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
}