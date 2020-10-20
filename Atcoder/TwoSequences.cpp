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

ll dua[30],a[200010],b[200010],ta[200010],tb[200010],bit[30],ans;
int n;
ll src(ll x,ll y){
    ll l=1;
    ll r=n;
    ll lb = -1;
    while(l<=r){
        ll mid = (l+r)/2;
        if(x<=tb[mid]){
            r = mid-1;
            lb = mid;
        }
        else{
            l = mid+1;
        }
    }

    if(lb>0){
        l=1;
        r=n;
        ll rb = -1;
        while(l<=r){
            ll mid = (l+r)/2;
            if(tb[mid]<=y){
                l = mid+1;
                rb = mid;
            }
            else r=mid-1;
        }

        if(rb>0){
            ll res = rb-lb+1;
            //cout<<"rl "<<rb<<" "<<lb<<newl;
            return res;
        }
        else return 0;

    }
    else return 0;
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dua[0]=1;
    for(int i=1;i<=29;i++)dua[i]=2*dua[i-1];

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];

    for(int k=0;k<=29;k++){
        ll two = dua[k];
        for(int i=1;i<=n;i++){
            ta[i]=a[i] % (2*two);
            tb[i]=b[i] % (2*two);
        }
        sort(ta+1,ta+1+n);sort(tb+1,tb+1+n);

//        cout<<"bit "<<k<<newl;
//        cout<<"ta ";for(int i=1;i<=n;i++)cout<<ta[i]<<" ";cout<<newl;
//        cout<<"tb ";for(int i=1;i<=n;i++)cout<<tb[i]<<" ";cout<<newl;

        for(int i=1;i<=n;i++){
            bit[k] += src (two-ta[i],2*two-ta[i]-1);
            bit[k] += src (3*two-ta[i],4*two-ta[i]-1);
//            cout<<ta[i]<<" "<<two-ta[i]<<" "<<2*two-ta[i]-1<<newl;
//            cout<<k<<" "<<bit[k]<<newl;
        }
        bit[k] %= 2;
//        cout<<newl;
    }
    for(int k=0;k<=29;k++){
        ans += bit[k] * dua[k];
    }
    cout<<ans<<newl;
}
