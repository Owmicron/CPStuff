#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,start,fin,d[600000],s[600000],x;
vector <pair <int,int> > p;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d",&temp);
        p.push_back(make_pair(temp,i));
    }
    sort(p.begin(),p.end());
    int f=1;
    start = p[0].second;
    p.push_back(make_pair(-1,-1));
    for(int i=1;i<p.size();i++){
        if(p[i-1].first == p[i].first){f++;fin=p[i].second;}
        else{
            if(f>1){
                d[start*2-1]++;d[fin*2]--;
            }
            f=1;
            start = p[i].second;
        }
    }

    for(int i=1;i<=2*n-1;i++){
        s[i]=s[i-1];
        s[i]+=d[i];
    }
    for(int i=3;i<2*n;i++){
        if(i%2==0){
            if(s[i-1]>0 && s[i+1]>0 && s[i]==0)x++;
        }
        else{
            if(s[i]==0 || s[i-2]==0)x++;
        }
    }
    ll ans = 1;
    ll md = 998244353;
    for(int i=1;i<=x;i++){
        ans = ((ans % md) * (2 % md))%md;
    }
    printf("%lld\n",ans);

}
