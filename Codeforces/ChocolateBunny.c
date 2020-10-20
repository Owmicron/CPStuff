#include <stdio.h>

// end of Template
int ans[10010];
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int n;
    scanf("%d",&n);

    int one = 1;
    for(int i = 2; i <= n; ++i){
        printf("? %d %d\n",one,i);
        //cout << "? " << one << " " << i << endl;
        fflush(stdout);
        int verdict;
        scanf("%d",&verdict);
        fflush(stdout);
        if(verdict == 0){
            one = i;
        }
    }

    for(int i = 1; i <= n; ++i){
        if(i == one) continue;
        printf("? %d %d\n",one,i);
//        cout << "? " << one << " " << i << endl;
        fflush(stdout);
        int verdict;
        scanf("%d",&verdict);
        ans[i] = verdict;
        fflush(stdout);
    }

    ans[one] = 1;

    printf("!");
    for(int i = 1; i <= n; ++i) printf(" %d",ans[i]); printf("\n");
    fflush(stdout);

}
