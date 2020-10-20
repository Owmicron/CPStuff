#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n;
int num[200000][2];
bool inp[200000];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++){
        int temp;
        scanf("%d",&temp);
        if(!inp[temp]){
            inp[temp]=true;
            num[temp][0]=i;
        }
        else{
            num[temp][1]=i;
        }
    }

    int ps=num[1][0];
    int pd=num[1][1];
    ll d = num[1][0]-1 + num[1][1]-1;
    for(int i=2;i<=n;i++){
        if((abs(ps-num[i][0]) + abs(pd-num[i][1])) <= (abs(ps-num[i][1]) + abs(pd-num[i][0]))){
            d += abs(ps-num[i][0])+abs(pd-num[i][1]);
            ps=num[i][0];
            pd=num[i][1];
        }
        else{
            d += abs(ps-num[i][1])+abs(pd-num[i][0]);
            ps=num[i][1];
            pd=num[i][0];
        }
    }
    printf("%lld\n",d);
}

