#include <bits/stdc++.h>
#define DEBUG true
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;
int t, n, cnt = 0;
vector<int> ifelboard;
int sieve(){
    vector<int> primes;
    vector<bool> prime(n + 1, true);
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i <= n; i++){
        ifelboard[cnt]++;
        if(prime[i]){
            primes.push_back(i);
            for(int j = i * i; j <= n; j += i){
                prime[j] = false;
                ifelboard[cnt]++;
            }
        }
    }
    return primes.size();
}

signed main() {
    if(!DEBUG){
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    }
    else{
        (void)freopen("test.in", "r", stdin);
        (void)freopen("test.out", "w", stdout); 
    }
    cin>>t;
    ifelboard.resize(t, 0);
    while(t--){
        //primes.clear();
        cin>>n;
        //sieve();
        cout<<sieve()<<endl;
        cnt++;
    }
    for(int i = 0; i < cnt; i++){
        cout<<ifelboard[i]<<' ';
    }
    cout<<endl;
}