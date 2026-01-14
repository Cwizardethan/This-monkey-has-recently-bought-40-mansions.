#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 0x3f3f3f3f3f3f3f3f;
int n;
vector<int> x, y, p;
vector<vector<int>> adj;
vector<bool> visited;
void dfs(int node){
    visited[node] = true;
    for(auto child : adj[node]){
        if(!visited[child]){
            dfs(child);
        }
    }
}
signed main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin>>n;
    x.resize(n);
    y.resize(n);
    p.resize(n);
    adj.resize(n);
    for(int i = 0; i < n; i++){
        cin>>x[i]>>y[i]>>p[i];
        for(int j = 0; j < i; j++){
            if(i != j){
                int dist = abs(x[i] - x[j]) * abs(x[i] - x[j]) + abs(y[i] - y[j]) * abs(y[i] - y[j]);
                if(dist <= p[i] * p[i]){
                    adj[i].push_back(j);
                }
                if(dist <= p[j] * p[j]){
                    adj[j].push_back(i);
                }
            }   
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        visited.assign(n, false);
        dfs(i);
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(visited[j]){
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout<<ans<<endl;

}//do you want some cheese?