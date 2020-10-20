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

int q,dem;
vpii ans;
void solve(int b, int w){
    while(!ans.empty())ans.pob();
    bool white = false;
    if(b>w){swap(b,w);white=true;}
    int bat = 3*b+1;
    if(w>bat)cout<<"NO\n";
    else{

        int x,y;
        x=0;y=0;
        for(int i=1;i<=b;i++){
            ans.pb(mp(x,y));x+=2;
        }

        if(w>0){
            x = -1; y = 0;
            for(int i=0;i<=b;i++){
                ans.pb(mp(x,y));x+=2;
                w--;if(w<=0)break;
            }
        }

        if(w>0){
            x = 0; y = 1;
            for(int i=1;i<=b;i++){
                ans.pb(mp(x,y));x+=2;
                w--; if(w<=0)break;
            }
        }

        if(w>0){
            x = 0; y = -1;
            for(int i=1;i<=b;i++){
                ans.pb(mp(x,y));x+=2;
                w--; if(w<=0)break;
            }
        }

        int nx,ny;nx = 10; ny = 10;
        if(!white)nx++;

        cout<<"YES\n";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].fi+nx<<" "<<ans[i].se+ny<<newl;
        }

    }

}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>q;
    for(int cases=1;cases<=q;cases++){
        int tb,tw;
        cin>>tb>>tw;
        solve(tb,tw);
    }

}

