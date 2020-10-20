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

int n,m,q;
int br[60000],bc[60000];
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    for(int cases=1;cases<=q;cases++){
        int n,m;
        cin>>n>>m;
        vpii black,white;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char temp;
                cin>>temp;
                if(temp=='*'){bc[j]++;br[i]++;black.pb(mp(i,j));}
                else{white.pb(mp(i,j));}
            }
        }
        int np = n+m-1;
        int mx = 1e6;
        for(int idx=0;idx<white.size();idx++){
            int i,j;
            i = white[idx].fi;
            j = white[idx].se;
            int need;
            need = np - (br[i] + bc[j]);
            mx = min(mx,need);

//            cout<<need<<newl;
        }
        for(int idx=0;idx<black.size();idx++){
            int i,j;
            i = black[idx].fi;
            j = black[idx].se;
            int need;
            need = np - (br[i] + bc[j] - 1);
            mx = min(mx,need);
            //cout<<need<<newl;
        }
        cout<<mx<<newl;
        for(int i=0;i<=n;i++)br[i]=0;
        for(int i=0;i<=m;i++)bc[i]=0;
        while(!white.empty())white.pob();
        while(!black.empty())black.pob();
    }

}
