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

int t,n,a[300010],s[300010],b[300010];
vi p[300010];
vpii con[300010];
void reset (){
    for(int i=1;i<=n;i++){
        if(!p[a[i]].empty()){
            p[a[i]].pob();
        }
        if(!con[a[i]].empty()){
            con[a[i]].pob();
        }
    }

}
bool inrange(int l, int r, int x){
    if(l<=x && x<=r)return true;
    else return false;
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    for(int cases=1;cases<=t;cases++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            p[a[i]].pb(i);
            s[i] = a[i];
        }
        sort(s+1,s+1+n);

        bool valid = true;
        for(int i=n;i>=1;i--){
            int r = i;
            int l = p[s[i]].back();
            p[s[i]].pob();
            if(l>r)swap(l,r);
            con[s[i]].pb(mp(l,r));
        }

        for(int i=1;i<=n;i++){
            cin>>b[i];
        }

        for(int i=1;i<=n;i++){
            int now = i;
            if(!con[b[i]].empty()){

                int l = con[b[i]].back().fi;
                int r = con[b[i]].back().se;
                con[b[i]].pob();
                cout<<l<<" "<<r<<" "<<now<<newl;
                if(inrange(l,r,now)){continue;}
                else{valid=false;break;}
            }
            else{valid=false;break;}
        }
        if(valid)cout<<"YES\n";
        else{cout<<"NO\n";}
        reset();


    }

}