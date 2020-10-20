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
//void IO(){
//	#ifndef ONLINE_JUDGE
//	    freopen("input.txt", "r", stdin);
//	    freopen("output.txt", "w", stdout);
//	#endif
//}
// end of Template
ll dua[30],sl[30][100100],sr[30][100100],lv[100100],rv[100100],bl[100100],br[100100];
ll n,c,mx;
pll sushi [101000];

ll maxr (int l, int r){
    int range = r-l+1;
    int llv = log(range)/log(2);
    ll mn = max (sr[llv][l],sr[llv][r-dua[llv]+1]);
    return mn;
}
ll maxl (int l, int r){
    int range = r-l+1;
    int llv = log(range)/log(2);
    ll mn = max (sl[llv][l],sl[llv][r-dua[llv]+1]);
    return mn;
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dua[0]=1;
    for(int i=1;i<=28;i++)dua[i]=dua[i-1]*2;
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        ll x,v;
        cin>>x>>v;
        sushi[i] = mp(x,v);
    }
    sort(sushi+1,sushi+1+n);

    for(int i=1;i<=n;i++){
        rv[i] = rv[i-1] + sushi[i].se;
        ll dist = sushi[i].fi;
        br[i] = rv[i] - dist;
        mx = max(mx,br[i]);
    }

    for(int i=1;i<=n;i++){
        sr[0][i] = br[i];
    }
    for(int i=1;i<=log(n)/log(2);i++){
        for(int j=1;j<=n;j++){
            if(j+dua[i]-1<=n){
                sr[i][j] = max (sr[i-1][j] , sr[i-1][j+dua[i-1]]);
            }
            else break;
        }
    }
    for(int i=n;i>=1;i--){
        lv[i] = lv[i+1] + sushi[i].se;
        ll dist = c - sushi[i].fi;
        bl[i] = lv[i] - dist;
        mx = max(mx,bl[i]);
    }

    for(int i=n;i>=1;i--){
        sl[0][i] = bl[i];
    }
    for(int i=1;i<=log(n)/log(2);i++){
        for(int j=1;j<=n;j++){
            if(j+dua[i]-1<=n){
                sl[i][j] = max (sl[i-1][j] , sl[i-1][j+dua[i-1]]);
            }
            else break;
        }
    }

    for(int i=1;i<n;i++){
        ll dist = sushi[i].fi;
        ll alt = br[i] - dist;
        ll m = maxl (i+1,n);
        alt += m;
        mx = max(mx,alt);
    }
    for(int i=n;i>1;i--){
        ll dist = c - sushi[i].fi;
        ll alt = bl[i] - dist;
        ll m = maxr (1,i-1);
        alt += m;
        mx = max(mx,alt);
    }
    cout<<mx<<newl;
}
