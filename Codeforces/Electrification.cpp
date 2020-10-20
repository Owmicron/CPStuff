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

int t,n,k;
int a[300000],lef[300000],righ[300000];
int d[300000];
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    for(int cases=1;cases<=t;cases++){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=2;i<=n;i++){
            d[i-1] = a[i]-a[i-1];
            lef[i-1] = a[i-1];
            righ[i-1] = a[i];
            //cout<<"dist "<<d[i-1]<<" "<<lef[i-1]<<" "<<righ[i-1]<<newl;
        }
        int mx = 0;
        int sum = 0;
        int ans;
        if(k==0)ans=a[1];
        else{
            for(int i=1;i<=k;i++){
                sum+=d[i];
            }
            int ml,mr;
            ml = 1;
            mr = k;

            mx = sum;
            int l,r;
            l = 1;
            r = k;
            while(r<n-1){
                sum-=d[l];
                l++;r++;
                sum+=d[r];
                if(sum<mx){
                    mx = sum;
                    ml = l;
                    mr = r;
                }
            }
            ml = lef[ml];
            mr = righ[mr];
            //cout<<"mlmr "<<ml<<" "<<mr<<newl;
            int x,y;
            x = mx/2;
            y = mx - x;
            //cout<<x<<" "<<y<<newl;
            if(x<=y){ans = (ml + mr)/2;}
            else{ans = (ml + mr)/2 + 1;}
        }
        cout<<ans<<newl;

    }
}
