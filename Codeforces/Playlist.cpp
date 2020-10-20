#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,k,fb[1000020];
pair<int,int> song[400000];
bool insum[400000];
ll sumb[1000020];
ll maxsum,p;
priority_queue< pair<int,int> > q;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        int t,b;
        scanf("%d %d",&t,&b);
        song[i]=make_pair(b,t);
    }
    sort(song+1,song+1+n);
    for(int i=1;i<=n;i++){
        q.push (make_pair(song[i].second,i));
    }
    for(int i=1;i<=k;i++){
        maxsum += q.top().first;
        insum[q.top().second]=true;
        q.pop();
    }
    for(int i=1;i<=n;i++){
        p = max (p,song[i].first * maxsum);
        if(song[i].first!=song[i+1].first){
            int b = song[i].first;
            int f = 0;
            for(int j=i;j>=1;j--){
                if(song[j].first!=b){break;}
                else{
                    if(insum[j]){f++;maxsum-=song[j].second;insum[j]=false;}
                }
            }
            while (!q.empty() && f>0){
                if(q.top().second > i ){
                    maxsum += q.top().first;
                    insum[q.top().second]=true;
                    f--;
                }
                q.pop();
            }
        }
    }
    printf("%lld\n",p);
}
