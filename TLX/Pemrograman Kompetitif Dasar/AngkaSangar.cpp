#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,batas;
ll a,b,z;
vector < pair < ll,ll > > c;
int main(){
    c.push_back(make_pair(1,10));
    c.push_back(make_pair(5,10));
    batas = 10;
    for(int j=1;j<=9;j++){
        for(int i=1;i<=9;i++){
            ll t; t = batas * i + c.back().first;
            if ((t * t)% (batas*10) == t){c.push_back(make_pair(t,batas*10));break;}
        }
        batas*=10;
    }

    c.push_back(make_pair(6,10));
    batas = 10;
    for(int j=1;j<=9;j++){
        for(int i=1;i<=9;i++){
            ll t; t = batas * i + c.back().first;
            if ((t * t)% (batas*10) == t){c.push_back(make_pair(t,batas*10));break;}
        }
        batas*=10;
    }

    scanf("%lld", &n);
    bool ans=false;
    for(int i=0;i<c.size();i++){
        //printf("%lld %lld\n",c.at(i).first,c.at(i).second);
        ll t;
        t = n*(c.at(i).second) + c.at(i).first;
        //cout<<t<<endl;
        for(int j=1;j<=sqrt(n);j++){
            ll x;
            x = j*(c.at(i).second) + c.at(i).first;
            ll y;
            //cout<<x<<endl;
            if(t%x==0){
                y = t/x;
                if((y%c.at(i).second) == (c.at(i).first)){
                    ans = true;
                    a = (y - c.at(i).first)/c.at(i).second;
                    b = (x - c.at(i).first)/c.at(i).second;
                    z = i;
                    break;
                }
            }
        }
        if(ans)break;
    }

    if((a==0)||(b==0)){ans=false;}
    if(ans){
        printf("YA\n");
        printf("%lld %lld %lld\n",a,b,c.at(z).first);
    }
    else{
        printf("TIDAK\n");
    }

}
