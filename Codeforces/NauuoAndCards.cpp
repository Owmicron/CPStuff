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

int a[300000];
int p[300000],use,ans,n;
int one;
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        a[temp]=1;
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
        a[p[i]]=i+1;
        if(p[i]==1)one=i;
    }
    bool good = true;
    for(int i=one+1;i<=n;i++){
        if(p[i]==p[i-1]+1){}
        else{good=false;}
    }

    if(good){
        int st = p[n]+1;
        use = 0;
        //cout<<st<<newl;
        for(int i = st;i<=n;i++){
            //cout<<i<<" "<<a[i]<<" "<<use<<newl;
            use++;
            if(a[i]<=use){}
            else{good=false;break;}
        }
    }

    if(good){ans=use;}
    else{
        use = a[1];
        for(int i = 2; i<=n;i++){
            use ++;
            if(a[i]<=use){}
            else use=a[i];
        }
        ans = use;
    }
    cout<<ans<<newl;




}
