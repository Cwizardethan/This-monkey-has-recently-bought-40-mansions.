#include <bits/stdc++.h> 
#include <codecvt>
#include <locale>
using namespace std;

signed main(){
    freopen("message.md", "r", stdin);
    freopen("encrypted_message.md", "w", stdout);
    int n = 10;
    vector<u32string> s(n);
    u32string read_greek = U"αβcδεϝghιjκλϻͷσρϙrsτυνωχγζ";
    u32string upper_greek = U"ABCDΣϜGHIJKLMͶΘPϘRSͲUVWXYZ";
    map<char32_t, char32_t> mp;
    for(int i = 0; i < read_greek.size(); i++){
        mp[(char32_t)(i + 'a')] = read_greek[i];
    }
    for(int i = 0; i < upper_greek.size(); i++){
        mp[(char32_t)(i + 'A')] = upper_greek[i];
    }
    wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
    for(int i = 0; i < n; i++){
        string temp;
        getline(cin, temp);
        s[i] = conv.from_bytes(temp);
    }
    for(int i = 0; i < n; i++){
        for(char32_t &c : s[i]){
            if(mp.find(c) != mp.end()){
                c = mp[c];
            }
        }
        cout<<conv.to_bytes(s[i])<<endl;
    }
}