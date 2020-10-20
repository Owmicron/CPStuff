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
typedef unsigned long long ull;
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

int n,q;
ull d[200000],s[200000],pre[200000];
vector<ull> ans;
int lb (ull x){
    int l=0;
    int r=n-1;
    int res = 0;
    bool found =false;
    while(l<=r){
        int mid = (l+r)/2;
        if(d[mid]<=x){
            found = true;
            res = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    if(!found)res = 0;
    return res;
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    sort(s+1,s+1+n);
    for(int i=1;i<n;i++){
        d[i] = s[i+1]-s[i];
    }

    sort(d+1,d+n);

    for(int i=1;i<n;i++)pre[i]=d[i]+pre[i-1];
    cin>>q;
    for(int i=1;i<=q;i++){
        ull l,r,dif;
        cin>>l>>r;
        dif = r-l+1;
        ull a,b;
        a = lb(dif);
        b = (n-1)-a+1;

        ull res;
        res = pre[a] + dif*b;
        ans.pb(res);
    }
    cout<<ans[0];
    for(int i=1;i<ans.size();i++)cout<<" "<<ans[i];cout<<newl;

}

