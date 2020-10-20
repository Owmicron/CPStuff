#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,ans,jenis,e;
int x[100010];
bool used[100010];
int use[100010];
void reset(){
    for(int i=1;i<=jenis;i++){
        use[i]=0;
    }
}
void eliminate(int start){
    reset();
    for(int i=start-1;i>=1;i--){
        if(used[i]){continue;}
        if(use[x[i]]>0){continue;}
        else{use[x[i]]++;used[i]=true;e++;}
    }
    reset();
    for(int i=start;i<=n;i++){
        if(used[i])continue;
        if(use[x[i]]>0){continue;}
        else{use[x[i]]++;used[i]=true;e++;}
    }
}
vector<int> rad;
pair < pair<int,int>,int> p[100010];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int tempt,tempv;
        scanf("%d %d",&tempt,&tempv);
        p[i] = make_pair( make_pair(tempt,tempv),i);
    }
    sort(p+1,p+1+n);
    jenis=1;
    x[p[1].second]=jenis;
    for(int i=2;i<=n;i++){
        if(p[i].first != p[i-1].first)jenis++;
        x[p[i].second]=jenis;
    }
    bool found=true;
    while(found){
        found=false;
        reset();
        for(int i=1;i<=n;i++){
            if(!used[i]){
                use[x[i]]++;
                if(use[x[i]]==2){
                    eliminate(i);
                    ans++;
                    found=true;break;
                }
            }
        }
    }
    if(e<n){ans++;}
    cout<<ans<<endl;

}
