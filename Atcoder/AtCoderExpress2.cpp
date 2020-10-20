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

int n,m,q;
pii city[300000];
vector <int> adj[600];
int binsearch (int start, int pi, int qi){
    if(start < pi || start > qi) return 0;
    else{
        int l=0;
        int r=(int) adj[start].size()-1;
        int idx=-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(adj[start][mid]<=qi){
                idx = mid;
                l = mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return idx + 1;
    }
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
        int l,r; cin>>l>>r;
        city[i]=mp(l,r);
    }
    sort(city+1,city+1+m);

//    cout<<newl;
//    for(int i=1;i<=m;i++){
//        cout<<city[i].fi<<" "<<city[i].se<<newl;
//    }
//    cout<<newl;

    for(int i=1;i<=m;i++){
        adj[city[i].fi].pb(city[i].se);
    }

    for(int i=1;i<=q;i++){
        int sum = 0;
        int pi,qi;
        cin>>pi>>qi;
        for(int j=1;j<=n;j++){
            if(j<pi)continue;
            else if(j>qi)break;
            else{
                sum += binsearch(j,pi,qi);
                //cout<<j<<" "<<binsearch(j,pi,qi)<<newl;
            }
        }
        cout<<sum<<newl;
    }
}
