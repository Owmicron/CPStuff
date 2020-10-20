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

ll prel[200010],prer[200010],ans;
int n,a[200010];
pll cutl[200010],cutr[200010];
void srcl (int x){
    ll N = prel[x];
    int l = 1;
    int r = x-1;
    while(l<=r){
        int mid = (l+r)/2;
        ll ki,ka,ab;
        ki = prel[mid]; ka = N - prel[mid];
        ab = abs(ka-ki);
        ll lef,righ;
        lef = abs ( prel [mid-1] - (N - prel[mid-1]) );
        righ = abs ( prel [mid+1] - (N - prel[mid+1]) );
        if(ab <= lef && ab <= righ){
            cutl[x] = mp (ki,ka);
            break;
        }
        else if(ab <= lef){l=mid+1;}
        else if(ab <= righ){r=mid-1;}
    }
}
void srcr (int x){
    ll N = prer[x];
    int l = x+1;
    int r = n;
    while(l<=r){
        int mid = (l+r)/2;
        ll ki,ka,ab;
        ki = prer[mid]; ka = N - prer[mid];
        ab = abs(ka-ki);
        ll lef,righ;
        lef = abs( prer[mid-1] - (N - prer[mid-1]));
        righ = abs( prer[mid+1] - (N - prer[mid+1]));
        if(ab<=lef && ab<= righ){
            cutr[x] = mp(ki,ka);
            break;
        }
        else if(ab<=lef){l=mid+1;}
        else if(ab<=righ){r=mid-1;}
    }
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        prel[i] = prel[i-1] + a[i];
    }
    for(int i=n+1;i>=1;i--){
        prer[i] = prel[n]-prel[i-1];
    }
    for(int i=2;i<=n-2;i++){
        srcl(i);
    }
    for(int i=n-1;i>=3;i--){
        srcr(i);
    }
    ans = LONG_LONG_MAX;
    for(int i=2;i<=n-2;i++){
        ll val[5];
        val[1] = cutl[i].fi;
        val[2] = cutl[i].se;
        val[3] = cutr[i+1].fi;
        val[4] = cutr[i+1].se;
        sort(val+1,val+1+4);
        ll mn,mx;
        mn = val[1];
        mx = val[4];
        ans = min(ans,abs(mn-mx));
    }
    cout<<ans<<newl;

}
