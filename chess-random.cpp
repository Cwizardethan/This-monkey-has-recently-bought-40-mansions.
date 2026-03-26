#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
bool DEBUG = true;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int safe = 1e10;
vector<pair<int, string>> idtopiece = {{0, "Placeholder"}, {1, "A-Pawn"}, {2, "B-Pawn"}, {3, "C-Pawn"}, {4, "D-Pawn"}, \
{5, "E-Pawn"}, {6, "F-Pawn"}, {7, "G-Pawn"}, {8, "H-Pawn"}, \
{9, "A-Rook"}, {10, "B-Knight"}, {11, "C-Bishop"}, {12, "D-Queen"}, \
{13, "E-King"}, {14, "F-Bishop"}, {15, "G-Knight"}, {16, "H-Rook"}};

struct chess{
    int moveable;
    int direction;
};
/*
id: 
1 -> a pawn | 2 -> b pawn | 3 -> c pawn
4 -> d pawn | 5 -> e pawn | 6 -> f pawn | 7 -> g pawn | 8 -> h pawn
9 -> A Rook | 10 - B Knight | 11 - C Bishop | 12 - D Queen
13 - E King | 14 -> F Bishop | 15 - G Knight | 16 H Rook
moveable: 
-2 -> not on board | 0 -> immoveable | 1 -> moveable
*/
signed main(){
    if(!DEBUG){
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    }
    else{
        (void)freopen("test.in", "r", stdin);
        (void)freopen("test.out", "w", stdout); 
    }
    random_device rd; //seed source
    mt19937 gen(rd()); //Mersenne Twister RNG
    uniform_int_distribution<> piece_dist(1, 16);
    vector<chess> arr(17);
    string piece;
    int direction, move;
    for(int i = 0; i < 16; i++){
        int id, move, dir;
        cin>>id>>move>>dir;
        arr[id] = {move, dir};
    }
    vector<int> candidates;
    for(int i = 1; i <= 16; i++){
        if(arr[i].moveable == 1 and arr[i].direction > 0){
            candidates.push_back(i);
        }
    }
    if(candidates.empty()){
        cout<<"No moveable pieces."<<endl;
        return 0;
    }
    uniform_int_distribution<> pick(0, candidates.size() - 1);
    int idpiece = candidates[pick(gen)];
    //cout<<"while loop is fine"<<endl;
    piece = idtopiece[idpiece].second;
    uniform_int_distribution<> dir_dist(1, arr[idpiece].direction);
    direction = dir_dist(gen);
    uniform_int_distribution<> move_dist(0, 419); //range [0, 419]
    move = move_dist(gen);
    cout<<"Move the "<<piece<<" "<<move<<" steps in direction "<<direction<<".\n";
}
/*
1 1 1
2 -2 1
3 -2 1 
4 1 2
5 0 1
6 1 1
7 -2 1
8 -2 1
9 1 1
10 1 2
11 1 1
12 -2 1
13 1 1
14 1 1
15 1 3
16 1 2
*/