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
typedef set <int> si;
typedef set <int> :: iterator sitr;
typedef set <ll> :: iterator sltr;
#define mset multiset
typedef mset <int> msi;
typedef mset <ll> msll;
typedef mset <int> :: iterator msitr;
typedef mset <ll> :: iterator msltr;
#define mp make_pair
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
#define newline '\n'
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
void IO(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
// end of Template
ll n,a[200100],BIT[200100],s[200100];
ll getsum (int idx){
    int sum = 0;
    idx++;
    while(idx>0){
        sum += BIT[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
void update (int idx, int val){
    idx ++ ;
    while(idx<=200005){
        BIT[idx]+=val;
        idx += idx & (-idx);
    }
}
bool check (int x){
    int pre[200000];
    pre[0]=0;
    si sr;
    sitr it;

    for(int i=1;i<=n;i++){
        int temp;
        if(a[i]<x){temp=-1;}
        else{temp=1;}
        pre[i]=pre[i-1]+temp;
    }


    for(int i=0;i<=200004;i++)BIT[i]=0;

    ll num=0;
    for(int i=0;i<=n;i++){
        int temp = pre[i] + 100000;
        num += getsum(temp);
        update(temp,1);
    }

    ll half = (ll) (n*(n+1))/4;

    if(num>=half)return true;
    else return false;

}
int main(){
    IO();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];s[i]=a[i];
    }
    sort(s+1,s+1+n);
    int l=1;
    int r=n;
    ll ans;
    while(l<=r){
        int mid = (l+r)/2;
        if(check (s[mid])){ans=s[mid];l=mid+1;}
        else{r=mid-1;}
    }
    cout<<ans<<newline;
}