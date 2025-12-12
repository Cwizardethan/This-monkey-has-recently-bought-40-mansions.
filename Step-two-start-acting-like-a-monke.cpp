#include <bits/stdc++.h>
#define DEBUG true
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;
int n, maxi = -1;
//?
vector<vector<int>> adj;
// vector<bool> visited;
vector<int> dp;
void dfs(int a, int pa){
    if(adj[a].size() == 1 and pa != -1){
        dp[a] = 1;
        return;
    }//leaf
    int cnt = 0;
    for(auto child : adj[a]){
        if(child == pa){
            dp[a] = 1;
            continue;
        }
        dp[a]++;
        dfs(child, a);
    }
}
signed main(){
    if(!DEBUG){
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    }
    else{
        (void)freopen("test.in", "r", stdin);
        (void)freopen("test.out", "w", stdout); 
    }//whats gplant
    cin>>n;
    adj.resize(n+1);    dp.resize(n+1, 0);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    for(auto ad : dp){
        maxi = max(maxi, ad);
    }
    cout<<maxi+1<<endl;//ms

}
    