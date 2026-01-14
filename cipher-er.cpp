#include <bits/stdc++.h>
#define DEBUG true
using namespace std;
#define int long long
bool use_num = false;
unordered_map<char, char> encrypter;
map<int, int> decipher;
vector<string> modes = {"empty space", "abcdefghijklmnopqrstuvwxyz", "qwertyuiopasdfghjklzxcvbnm", "azertyuiopqsdfghjklmwxcvbn", \
    "pyfgcrlaoeuidhtnsqjkxbmwvz", "qwfpgjluyarstdhneiozxcvbkm", "etaoinshrdlcumwfgypbvkjxqz", \
    " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~", \
    "custom", "random only abcs", "random all typeable"};
vector<string> upmodes = {"empty space", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "QWERTYUIOPASDFGHJKLZXCVBNM", "AZERTYUIOPQSDFGHJKLMWXCVBN", \
    "PYFGCRLAOEUIDHTNSQJKXBMWVZ", "QWFPGLUYARSTDHNEIOZXCVBKM", "ETAOINSHRDLUMWFGYPBVKJXQZ", \
    " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~", \
    "custom", "random only abcs", "random all typeable"};
void uppercase(int n){ //for custom5 -> upcustom5
    for(char c : modes[n]){
        upmodes[n] += toupper(c);
    }
}
void ceasar_cipher(){ //cipher 1
    int mode, shift;
    cin>>mode>>shift; //e.g. 1 2 {text} is alphabet with right shift 2
    decipher[2] = mode;
    decipher[3] = -shift;
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
    for(int i = 0; i < 26; i++){
        if(old_mode == modes.size() - 3){ //custom
            cin>>modes[old_mode];
            uppercase(old_mode);
        }
        if(new_mode == modes.size() - 3){ //custom
            cin>>modes[new_mode];
            uppercase(new_mode);
        }
        encrypter[modes[old_mode][i]] = modes[new_mode][(i + shift + 26) % 26]; //conversion to ascii might be buggy or customs
        encrypter[upmodes[old_mode][i]] = upmodes[new_mode][(i + shift + 26) % 26];
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
    string random = modes[2];
    shuffle(random.begin(), random.end(), std::mt19937(std::random_device()()));
    modes[modes.size() - 2] = random;
    uppercase(modes.size() - 2);
    random = modes[modes.size() - 4];
    shuffle(random.begin(), random.end(), std::mt19937(std::random_device()()));
    modes[modes.size() - 1] = random;
    upmodes[modes.size() - 1] = random;
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
    cout<<"Decipher parameters (modes 9 and 10 will most likely not return original value):"<<endl;
    for(auto [key, value] : decipher){
        cout<<value<<" ";
    }
}