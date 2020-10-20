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
int n,ans;
double t,a,mn;
int main(){
    mn = 100000000;
    cin>>n;
    cin>>t>>a;
    for(int i=1;i<=n;i++){
        double x;
        cin>>x;
        double temp;
        temp = t - x*0.006;
        if(abs(temp-a)<=mn){
            mn = abs(temp-a);
            ans = i;
        }
    }
    cout<<ans<<endl;


}
