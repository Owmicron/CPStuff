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

int h,w,d,q;
pii pos[100000];
int start[100000];
vll pre[100000];
ll solve (int l, int r){
    int group = start[l];
    int n1,n2;
    n1 = (l-group)/d + 1;
    n2 = (r-group)/d + 1;
    ll res = pre[group][n2] - pre[group][n1];
    return res;
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>h>>w>>d;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            int a;cin>>a;
            pos[a] = mp(i,j);
        }
    }

    for(int i=1;i<=h*w;i++){
        if(start[i]==0){
            start[i]=i;
            pre[i].pb(0);pre[i].pb(0);

            for(int j=i+d;j<=h*w;j+=d){
                start[j]=i;
                pii pref,now;
                pref = pos[j-d];
                now = pos[j];
                ll sel = abs(pref.fi-now.fi) + abs(pref.se - now.se);
                ll x = pre[i].back();
                x += sel;
                pre[i].pb(x);
            }
        }
    }

    cin>>q;
    for(int cases=1;cases<=q;cases++){
        int l,r;
        cin>>l>>r;
        ll ans = solve(l,r);
        cout<<ans<<newl;
    }

}
