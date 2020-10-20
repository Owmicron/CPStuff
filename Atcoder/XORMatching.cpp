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
ll m,k,dua[30];
deque <ll> q;
int main(){
//    for(int i=1;i<=30;i++){
//        int sum = 0;
//        for(int j=1;j<=i;j++){
//            sum = sum xor j;
//        }
//        if(i==sum-1){cout<<i<<endl;}
//    }
    dua[0] = 1;
    for(int i = 1;i <= 25;i++){
        dua[i] = 2 * dua[i-1];
    }
    cin>>m>>k;
    if(k==0){
        for(int i=0; i < dua[m]; i++){
            cout<<i<<" "<<i;
            if(i==dua[m]-1){cout<<endl;}
            else{cout<<" ";}
        }
    }
    else if(m==1){cout<<-1<<endl;}
    else{
        if(k > dua[m]-1){cout<<-1<<endl;}
        else{
            q.push_front(k);
            for(int i=0;i<dua[m];i++){
                if(i==k)continue;
                q.push_back(i);
                q.push_front(i);
            }
            cout<<k;
            while(!q.empty()){
                cout<<" "<<q.front();
                q.pop_front();
            }
            cout<<endl;
        }
    }

}

