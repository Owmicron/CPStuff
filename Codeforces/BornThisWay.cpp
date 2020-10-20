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

ll n,m,ta,tb,k;
ll a[300000],b[300000];
vector <ll> ans;
ll use (int x){
    ll arr = a[x+1];
    ll sisa = k - x;

    int l = 0;
    int r = m;

    int lw = -1;
    while(l<=r){
        int mid = (l+r)/2;
        if(b[mid]>=arr){
            lw = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    if(lw==-1)return LONG_LONG_MAX;
    else{
        lw += sisa;
        if(lw>m){return LONG_LONG_MAX;}
        else return b[lw]+tb;
    }
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>ta>>tb>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=ta;
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }

    if((k>=n) || (k>=m))cout<<-1<<newl;
    else{
        for(int i=0;i<=k;i++){
            ans.pb(use(i));
        }
        sort(ans.begin(),ans.end());
        ll mx = ans[ans.size()-1];
        if(mx==LONG_LONG_MAX){mx=-1;}
        cout<<mx<<newl;
    }

}
