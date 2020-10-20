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

int n,q;
set <pii> d;
set <pii> :: iterator itr;
int ans[300000];
pair < int , pii > block [300000];
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int s,t,x;
        cin>>s>>t>>x;
        t--;
        block [i] = mp (x , mp (max(0,s-x),max(0,t-x)) );
    }
    sort(block+1,block+1+n);

    for(int i=1;i<=q;i++){
        int st; cin>>st;
        d.insert( mp (st,i) );
    }

    for(int i=1;i<=n;i++){
        int x,s,t;
        x = block[i].fi;
        s = block[i].sf;
        t = block[i].ss;

        itr = d.lower_bound(mp(s,-1));
        while(itr != d.end()){
            pii p = *itr;
            int val,idx;
            val = p.fi;
            idx = p.se;

            if(val<s){itr++;}
            else if(val>t){break;}
            else{
                ans[idx]=x;
                d.erase(itr++);
            }
        }
    }

    for(int i=1;i<=q;i++){
        if(ans[i]==NULL)cout<<-1<<newl;
        else cout<<ans[i]<<newl;
    }



}
