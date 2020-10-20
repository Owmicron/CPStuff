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
int n;
stack <char> s;
ll dua[40],sum_odd[40],sum_even[40];
pll points[1020];
ll m;
bool valid,iseven;
ll two (ll x){
    if(!iseven)return dua[x];
    else{
        if(x<=1)return 1;
        else return dua[x-1];
    }
}
ll getsum (ll x){
    if(x<=0)return 0;
    else if(iseven)return sum_even[x];
    else return sum_odd[x];
}
ll manhattan ( pll z ){
    return abs(z.fi) + abs(z.se);
}
ll construct (ll z){
    ll x,y,idx,d;
    x = points[z].first;
    y = points[z].second;
    idx = m;
    while(idx>0){
        idx --;
        d=two(idx);
        //cout<<"awal "<<x<<" "<<y<<endl;
        ll tempx,tempy,temp;

        //tryleft
        tempx = x-d;tempy = y;
        temp = manhattan (mp(tempx,tempy));

        //cout<<"left "<<tempx<<" "<<tempy<<endl;
        if(temp<=getsum(idx)){
            s.push('R');x=tempx;y=tempy;
            continue;
        }

        //tryright
        tempx = x+d;tempy = y;
        temp = manhattan(mp(tempx,tempy));
        //cout<<"right "<<tempx<<" "<<tempy<<endl;
        if(temp<=getsum(idx)){
            s.push('L');x=tempx;y=tempy;
            continue;
        }

        //tryup
        tempx = x;tempy = y+d;
        temp = manhattan(mp(tempx,tempy));
        //cout<<"up "<<tempx<<" "<<tempy<<endl;
        if(temp<=getsum(idx)){
            s.push('D');x=tempx;y=tempy;
            continue;
        }

        //trydown
        tempx = x;tempy = y-d;
        temp = manhattan(mp(tempx,tempy));
        //cout<<"down "<<tempx<<" "<<tempy<<endl;
        if(temp<=getsum(idx)){
            s.push('U');x=tempx;y=tempy;
            continue;
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>points[i].fi>>points[i].se;
    }
    valid = true;
    for(int i=2;i<=n;i++){
        if(manhattan(points[i])%2 != manhattan(points[i-1])%2){valid=false;break;}
    }
    if(!valid)cout<<-1<<endl;
    else{
        if(manhattan(points[1])%2 == 1){iseven=false;}
        else{iseven=true;}
        dua[0] = 1;
        for(int i=1;i<=37;i++)dua[i]=dua[i-1]*2;
        for(int i=1;i<=37;i++){
            sum_odd[i]=dua[i]-1;
            sum_even[i]=sum_odd[i-1]+1;
        }
        ll mx = -1;
        for(int i=1;i<=n;i++)mx = max(mx,manhattan(points[i]));
        for(int i=1;i<=35;i++){
            if(getsum(i)>=mx){m=i;break;}
        }
        if(iseven){m=max(m,(ll)2);}
        cout<<m<<endl;
        for(int i=0;i<m;i++){
            if(i>0)cout<<" ";
            cout<<two(i);
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            construct(i);
            while(!s.empty()){
                cout<<s.top();s.pop();
            }cout<<endl;
        }

    }


}
