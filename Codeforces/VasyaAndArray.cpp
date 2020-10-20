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

int pre1[2000],pre2[2000],b1[2000],b2[2000],n,m;
ll a[2000];
vpii one,zero;
bool valid;
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int t,l,r;
        cin>>t>>l>>r;
        if(t==1){
            pre1[l]++;
            pre1[r]--;
        }
        else if(t==0){
            zero.pb(mp(l,r));
        }
    }
    for(int i=1;i<=n;i++){
        b1[i] = b1[i-1] + pre1[i];
    }

    valid = true;

    for(int i=0;i<zero.size();i++){
        int l = zero[i].fi;
        int r = zero[i].se;

        bool found = false;
        for(int j=l;j<r;j++){
            if(b1[j]==0){b2[j]++;found=true;break;}
        }
        if(!found){valid=false;break;}
    }
    if(!valid)cout<<"NO\n";
    else{
        cout<<"YES\n";
        ll num = 0;
        for(int i=1;i<=n;i++){
            if(b2[i]<=0){
                num++;a[i]=num;
            }
        }
        num = 100000;
        for(int i=1;i<=n;i++){
            if(b2[i]>0){
                a[i]=num; num--;
            }
        }
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";

    }

}
