#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int num[5],A,B,C;
int main(){
    for(int i=1;i<=4;i++)cin>>num[i];
    sort(num+1,num+1+4);
    A = (num[1]-num[2]+num[3])/2;
    B = (num[1]+num[2])-num[4];
    C = num[4] - (A+B);
    printf("%d %d %d\n",A,B,C);
}
