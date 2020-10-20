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
ll lcm (ll num1 , ll num2){return (ll) (num1/gcd(num1,num2))*num2;}


// end of Template

int n,m,k,a[200010],b[200010];
ll s;
vi ans;
vpii d,p,v;
vi f(int x){
    int mdo = 1e7;
    int mpo = 1e7;
    int dayd, dayp;
    for(int i=1;i<=x;i++){
        if(a[i]<mdo){
            mdo = a[i];
            dayd = i;
        }
    }
    for(int i=1;i<=x;i++){
        if(b[i]<mpo){
            mpo = b[i];
            dayp = i;
        }
    }

    ll sum = 0;
    int td = 0; int tp = 0;
    for(int i=0;i<k;i++){
        if(v[i].se>0){
            sum += (ll) mdo * v[i].fi;
            td++;
        }
        else{
            sum += (ll) mpo * v[i].fi;
            tp++;
        }
    }
    vi res;
    if(sum<=s){
        res.pb(1);
        res.pb(td);
        res.pb(tp);
        res.pb(dayd);
        res.pb(dayp);
    }
    else{
        int l = 1;
        int r = k;
        int can = 0;
        while(r<v.size()){
            if(v[r].se>0){
                sum += (ll) mdo * v[r].fi;
                td++;
            }
            else{
                sum += (ll) mpo * v[r].fi;
                tp++;
            }

            if(v[l-1].se>0){
                sum -= (ll) mdo * v[l-1].fi;
                td--;
            }
            else{
                sum -= (ll) mpo * v[l-1].fi;
                tp--;
            }
            if(sum<=s){can=1;break;}
            l++; r++;
        }
        res.pb(can);
        res.pb(td);
        res.pb(tp);
        res.pb(dayd);
        res.pb(dayp);
    }
    return res;
}
void bins(){
    int l=1;
    int r=n;
    while(l<=r){
        int mid = (l+r)/2;
        vi temp = f(mid);
        if(temp[0]==1){
            ans = temp;
            ans[0] = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    cin>>n>>m>>k>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=m;i++){
        int t,c; cin>>t>>c;
        if(t==1){d.pb (mp(c,i));}
        else{p.pb(mp(c,-i));}
    }
    sort(d.begin(),d.end());
    sort(p.begin(),p.end());
    for(int i = min((int)d.size()-1 , k-1); i>=0;i--)v.pb(d[i]);
    for(int i = 0; i <= min((int)p.size()-1 , k-1);i++)v.pb(p[i]);
    bins();

    if(ans.empty())cout<<-1<<newl;
    else{
        cout<<ans[0]<<newl;
        int dd,dp,td,tp;
        dd = ans[3];
        dp = ans[4];
        td = ans[1];
        tp = ans[2];
        for(int i=0;i<td;i++){
            cout<<abs(d[i].se)<<" "<<dd<<newl;
        }
        for(int i=0;i<tp;i++){
            cout<<abs(p[i].se)<<" "<<dp<<newl;
        }
    }
}
