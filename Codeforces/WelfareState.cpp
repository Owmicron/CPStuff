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
bool isect (int l1, int r1, int l2, int r2){
    pii p1,p2;
    p1 = mp(l1,r1); p2 = mp(l2,r2);
    if(p1>p2)swap(p1,p2);
    if(p2.fi <= p1.se)return true;
    else return false;
}
ll fexp (ll num1, ll num2, ll MOD){
    if(num2==0)return 1;
    else if(num2==1)return num1;
    else{
        ll temp = fexp (num1,num2/2,MOD); ll res = ((temp%MOD) * (temp%MOD))%MOD;
        if(num2%2==1) res = ((res%MOD)*(num1%MOD))%MOD; return res;
    }
}
ll invmod (ll num, ll MOD){return fexp (num,MOD-2,MOD);}
ll gcd (ll num1, ll num2){
    if(num1 < num2) swap(num1,num2); ll num3 = num1 % num2 ;
    while(num3 > 0){ num1 = num2; num2 = num3; num3 = num1 % num2;}
    return num2;
}
ll lcm (ll num1 , ll num2){return (num1/gcd(num1,num2))*num2;}

// end of Template

int n,a[200010],v[200010],q,sparse[30][200010],dua[30];
vpii qu[200010];
int maxi (int l, int r){
    int range = r-l+1;
    // assign level to the closest 2^x which is <= range
    int lv = log(range)/log(2);
    int mn = max (sparse[lv][l],sparse[lv][r-dua[lv]+1]);
    return mn;
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        int typ;
        cin>>typ;
        if(typ==1){
            int p,x;
            cin>>p>>x;
            if(!qu[p].empty())qu[p].pob();
            qu[p].pb(mp(i,x));
            v[i] = 0;
        }
        else{
            int x; cin>>x;
            v[i] = x;
        }
    }
    dua[0]=1;
    for(int i=1;i<=28;i++)dua[i]=dua[i-1]*2;
    for(int i=1;i<=q;i++){
        sparse[0][i]=v[i];
    }
    // this is a max sparse
    for(int i=1;i<=log(q)/log(2);i++){
        // i is table level (lv)
        for(int j=1;j<=q;j++){
            // j is table index (idx)
            if(j+dua[i]-1<=q){
                sparse[i][j] = max (sparse[i-1][j] , sparse[i-1][j+dua[i-1]]);
            }
            else break;
        }
    }
    for(int i=1;i<=n;i++){
        //cout<<i<<newl;
        if(qu[i].empty()){
            int mx = maxi(1,q);
            a[i] = max(mx,a[i]);
        }
        else{
            int l = qu[i][0].fi + 1;
            a[i] = qu[i][0].se;
            if(l<=q){
                int mx = maxi(l,q);
                a[i] = max(a[i],mx);
            }
        }
        cout<<a[i]<<" ";
    }

}
