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

ll h[3010][3010];
ll g[9000010];
ll sparse[3010][13][3010];
ll n,m,a,b,x,y,z;
ll dua[30];
ll minir (int row, int l, int r){
    ll range = r-l+1;
    // assign level to the closest 2^x which is <= range
    ll lv = log(range)/log(2);
    ll mn = min (sparse[row][lv][l],sparse[row][lv][r-dua[lv]+1]);
    return mn;
}
ll minirange (int r1, int c1, int r2, int c2){
    ll mn = INT_MAX;
    for(int i=1;i<=r1;i++){
        mn = min(mn,minir(i,c1,c2));

    }
    return mn;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dua[0]=1;
    for(int i=1;i<=28;i++)dua[i]=dua[i-1]*2;

    cin>>n>>m>>a>>b;
    cin>>g[0]>>x>>y>>z;
    for(int i=1;i<=n*m;i++){
        ll temp = ((g[i-1]*x)+ y)% z;
        g[i] = temp;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            h[i][j] = g[(i-1)*m + (j-1)];
            cout<<h[i][j]<<" ";
        }cout<<newl;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sparse[i][0][j] = 0;
        }
    }

    for(int row = 1; row<=n; row++){
        // this is a min sparse
        for(int i=1;i<=log(m)/log(2);i++){
            // i is table level (lv)
            for(int j=1;j<=m;j++){
                // j is table index (idx)
                if(j+dua[i]-1<=m){
                    sparse[row][i][j] = min (sparse[row][i-1][j] , sparse[row][i-1][j+dua[i-1]]);
                }
                else break;
            }
        }
    }
    ll ans = INT_MAX;
    for(int i=a;i<=n;i++){
        ll lr = i-a+1;
        ll rr = i;
        for(int j=b;j<=m;j++){
            ll lc = j-b+1;
            ll rc = j;
            ans = min(ans,minirange(lr,lc,rr,rc));
        }
    }
    cout<<ans<<newl;

}

