#include <bits/stdc++.h>
#define int long long
#define endl '\n'
bool DEBUG = true;
using namespace std;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int safe = 1e10;

signed main(){
    if(!DEBUG){
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    }
    else{
        (void)freopen("message.md", "r", stdin);
        (void)freopen("encrypted_message.md", "w", stdout); 
    }
    wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
    for(int i = 0; i <= 1114111; i++){
        cout<<conv.to_bytes(i);
        //if(i % 100 == 0) cout<<endl;
    }
}