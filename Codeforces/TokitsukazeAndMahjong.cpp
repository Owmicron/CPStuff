#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
typedef map <str,int> mapsi;
typedef map <str,int> :: iterator mapsitr;
typedef map <int , int> mint;
typedef map <ll , ll> mll;
typedef set <int> si;
typedef set <ll> sll;
typedef si :: iterator sitr;
typedef si :: reverse_iterator rsitr;
typedef sll :: iterator sltr;
typedef sll :: reverse_iterator rsltr;
#define mset multiset

typedef mset <int> msi;
typedef mset <ll> msll;
typedef msi :: iterator msitr;
typedef msi :: reverse_iterator msritr;
typedef msll :: iterator msltr;
typedef msll :: reverse_iterator mslritr;

#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
#define newl '\n'

char to_upper (char x){
    if( 97 <= int(x) && int(x) <= 126)return char(x-32);
    else if( 65 <= int(x) && int(x) <= 90)return x;
}
char to_lower (char x){
    if( 97 <= int(x) && int(x) <= 126)return x;
    else if( 65 <= int(x) && int(x) <= 90)return char(x+32);
}
int numerize (char x){
    if(48 <= int(x) && int(x) <= 57)return int(x-'0');
    else if( 97 <= int(x) && int(x) <= 126)return int(x-96);
    else if( 65 <= int(x) && int(x) <= 90)return int(x-64);
}
// end of Template

pair <char , int> card[10];
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=1;i<=3;i++){
        str s;
        cin>>s;
        int d = numerize(s[0]);
        card[i] = mp (s[1],d);
    }
    sort(card+1,card+1+3);

    if(card[1] == card[2] && card[2] == card[3])cout<<0<<newl;
    else if(card[1] == card[2] || card[2] == card[3])cout<<1<<newl;
    else{
        bool seqa,seqb;
        seqa = false;
        seqb = false;
        if(card[1].fi == card[2].fi && card[2].se == 1+card[1].se){seqa=true;}
        if(card[2].fi == card[3].fi && card[3].se == 1+card[2].se){seqb=true;}

        if(seqa && seqb){cout<<0<<newl;}
        else if(seqa || seqb){cout<<1<<newl;}
        else{
            if(card[1].fi == card[2].fi && card[2].se == 2 + card[1].se){cout<<1<<newl;}
            else if(card[2].fi == card[3].fi && card[3].se == 2 + card[2].se){cout<<1<<newl;}
            else{cout<<2<<newl;}
        }

    }


}
