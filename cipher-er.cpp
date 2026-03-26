#include <bits/stdc++.h>
#define DEBUG false
using namespace std;
#define int long long
#define unordered_map map //remove after debugging
//�
//fix mode 8
bool use_num = false;
unordered_map<char, char> encrypter;
map<int, int> decipher;
pair<string, string> original;
vector<string> modes = {"empty space", "abcdefghijklmnopqrstuvwxyz", "qwertyuiopasdfghjklzxcvbnm", "azertyuiopqsdfghjklmwxcvbn", \
    "pyfgcrlaoeuidhtnsqjkxbmwvz", "qwfpgjluyarstdhneiozxcvbkm", "etaoinshrdlcumwfgypbvkjxqz", \
    " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~", \
    "custom", "random only abcs", "random all typeable"};
vector<string> upmodes = {"empty space", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "QWERTYUIOPASDFGHJKLZXCVBNM", "AZERTYUIOPQSDFGHJKLMWXCVBN", \
    "PYFGCRLAOEUIDHTNSQJKXBMWVZ", "QWFPGLUYARSTDHNEIOZXCVBKM", "ETAOINSHRDLUMWFGYPBVKJXQZ", \
    " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~", \
    "custom", "random only abcs", "random all typeable"};
void uppercase(int n){ //for custom5 -> upcustom5
    upmodes[n] = "";
    for(char c : modes[n]){
        upmodes[n] += toupper(c);
    }
}
void ceasar_cipher(){ //cipher 1
    int mode, shift;
    cin>>mode>>shift; //e.g. 1 2 {text} is alphabet with right shift 2
    decipher[2] = mode;
    decipher[3] = -shift;
    if(decipher[2] == modes.size() - 2){
        decipher[2] = 8;
        modes[modes.size() - 2] = modes[2];
        shuffle(modes[modes.size() - 2].begin(), modes[modes.size() - 2].end(), std::mt19937(std::random_device()()));
        uppercase(modes.size() - 2);
        original.first = modes[modes.size() - 2];
    }
    if(decipher[2] == modes.size() - 1){
        decipher[2] = 8;
        modes[modes.size() - 1] = modes[modes.size() - 4];
        shuffle(modes[modes.size() - 1].begin(), modes[modes.size() - 1].end(), std::mt19937(std::random_device()()));
        upmodes[modes.size() - 1] = modes[modes.size() - 1];
    }
    for(int i = 0; i < 26; i++){
        if(mode < modes.size() - 3 or mode == modes.size() - 2){ //various keyboards + random keyboard + alphabet
            encrypter[modes[mode][i]] = modes[mode][(i + shift + 26) % 26];
            encrypter[upmodes[mode][i]] = upmodes[mode][(i + shift + 26) % 26];
        }
        else if(mode == modes.size() - 4 or mode == modes.size() - 1){ //typeable ascii + random typeable ascii
            encrypter[modes[mode][i]] = modes[mode][(i + shift + modes[mode].size()) % modes[mode].size()];
        }
        else if(mode == modes.size() - 3){ //custom
            cin>>modes[mode];
            encrypter[modes[mode][i]] = modes[mode][(i + shift + modes[mode].size()) % modes[mode].size()];
            uppercase(mode);
            original.first = modes[mode];
            encrypter[upmodes[mode][i]] = upmodes[mode][(i + shift + upmodes[mode].size()) % upmodes[mode].size()];
        }
        else{
            string random = modes[modes.size() - 4];
            shuffle(random.begin(), random.end(), std::mt19937(std::random_device()()));
            modes[mode] = random;
            for(int j = 0; j < random.size(); j++){
                encrypter[random[j]] = random[(j + shift + random.size()) % random.size()];
            }
        }
    }
}
void substitution_cipher(){//cipher 2
    int old_mode, new_mode, shift;
    cin>>old_mode>>new_mode>>shift; //e.g. 1 1 2 -2 {text} is convert alphabet to keyboard with left shift 2
    decipher[3] = old_mode;
    decipher[2] = new_mode;
    decipher[4] = -shift;
    string s, s1, S, S1;
    if(decipher[3] == modes.size() - 2){
        decipher[3] = 8;
        modes[modes.size() - 2] = modes[2];
        shuffle(modes[modes.size() - 2].begin(), modes[modes.size() - 2].end(), std::mt19937(std::random_device()()));
        uppercase(modes.size() - 2);
        original.second = modes[modes.size() - 2];
        s = original.second;
        uppercase(modes.size() - 2);
        S = upmodes[modes.size() - 2];
    }
    if(decipher[3] == modes.size() - 1){
        decipher[3] = 8;
        modes[modes.size() - 1] = modes[modes.size() - 4];
        shuffle(modes[modes.size() - 1].begin(), modes[modes.size() - 1].end(), std::mt19937(std::random_device()()));
        upmodes[modes.size() - 1] = modes[modes.size() - 1];
        original.second = modes[modes.size() - 1];
        s = original.second;
        S = s;
    }
    if(decipher[2] == modes.size() - 2){
        decipher[2] = 8;
        modes[modes.size() - 2] = modes[2];
        shuffle(modes[modes.size() - 2].begin(), modes[modes.size() - 2].end(), std::mt19937(std::random_device()()));
        uppercase(modes.size() - 2);
        original.first = modes[modes.size() - 2];
        s1 = original.first;
        uppercase(modes.size() - 2);
        S1 = upmodes[modes.size() - 2];
    }
    if(decipher[2] == modes.size() - 1){
        decipher[2] = 8;
        modes[modes.size() - 1] = modes[modes.size() - 4];
        shuffle(modes[modes.size() - 1].begin(), modes[modes.size() - 1].end(), std::mt19937(std::random_device()()));
        upmodes[modes.size() - 1] = modes[modes.size() - 1];
        original.first = modes[modes.size() - 1];
        s1 = original.first;
        S1 = s;
    }
    if(old_mode == modes.size() - 3){ //custom
        cin>>s;
        original.second = s;
        uppercase(old_mode);
    }
    if(new_mode == modes.size() - 3){ //custom
        cin>>s1;
        original.first = s1;
        uppercase(new_mode);
    }
    for(int i = 0; i < 26; i++){
        encrypter[s[i]] = s1[(i + shift + s1.size()) % s1.size()]; //conversion to ascii might be buggy or customs
        encrypter[S[i]] = S1[(i + shift + s.size()) % s.size()];
    }
}

signed main(){//random modes do not work
    if(!DEBUG){
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    }
    else{
        (void)freopen("message.md", "r", stdin);
        (void)freopen("encrypted_message.md", "w", stdout); 
    }
    int cipher_type;
    cin>>cipher_type;
    if(cipher_type == 1){
        ceasar_cipher();
    }
    else if(cipher_type == 2){
        substitution_cipher();
    }
    decipher[1] = cipher_type;
    //randomization
        /*
        for(int i = 0; i < symbols.size(); i++){
            encrypter[symbols[i]] = symbols[(i + shift + symbols.size()) % symbols.size()];
        }
        */
    string text;
    cin.ignore();
    getline(cin, text);
    string result = "";
    for(char c : text){
        if(encrypter.find(c) != encrypter.end()){
            result += encrypter[c];
        }
        else{
            result += c;
        }
    }
    cout<<result<<endl;
    cout<<"Decipher parameters (modes 9 and 10 can be reversed by entering their values into mode 8):"<<endl;
    bool need_custom = false, need_custom1 = false;
    for(auto [key, value] : decipher){
        cout<<value<<" ";
        if(key == 2 and value == 8){
            need_custom = true;
        }
        if(key == 3 and value == 8){
            need_custom1 = true;
        }
    }
    cout<<endl;
    if(need_custom){
        cout<<original.first<<endl;
    }
    if(need_custom1){
        cout<<original.second<<endl;
    }
    
    cout<<"Debugging: "<<endl;
    for(auto [key, val] : encrypter){
        cout<<key<<" -> "<<val<<endl;
    }
    cout<<"Modes"<<endl;
    for(int i = 0; i < modes.size(); i++){
        cout<<"Mode "<<i<<" -> "<<modes[i]<<endl;
    }
    
}



