#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;
typedef vector<ll,ll> vll;
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
ll dua[40];
double pangkat (double x , ll p){
    double sum = 1;
    for(int i=1;i<=p;i++){
        sum *= x;
    }
    return sum;
}
int n,k;
double ans;
int main(){
    dua[0] = 1;
    for(int i=1;i<=35;i++){
        dua[i] = 2 * dua[i-1];
    }
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        int idx;
        for(int j=0;j<=35;j++){
            if(dua[j] * i >= k){
                idx = j; break;
            }
        }
        double res;
        res = pangkat (2,idx);
        res = 1/res;

        ans += res;
    }
    ans /= n;
    printf("%.10lf\n",ans);



}
