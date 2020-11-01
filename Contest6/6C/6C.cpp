#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cmath>

#define USE_ONLINE_JUDGE
#define MAXN (100000 + 5)
int t[MAXN];
int n;

int input(){
    memset(t, 0, sizeof(t));
    if(scanf("%d",&n) == EOF){
        return 0;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &t[i]);
    }
    return 1;
}

int main()
{
    #ifndef USE_ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    while(input())
    {
        int a = -1, b = n;
        int remain_a = 0, remain_b = 0;
        while((b-a)>1){
            if(remain_a==0){
                a ++;
                remain_a = t[a];
            }
            if(remain_b==0 && (b-a) > 1){
                b --;
                remain_b = t[b];
            }
            if(remain_b > remain_a){
                remain_b = remain_b - remain_a;
                remain_a = 0;
            }
            else{
                remain_a = remain_a - remain_b;
                remain_b = 0;
            }
            #ifndef USE_ONLINE_JUDGE
                printf("a=%d, b=%d, remain_a=%d, remain_b=%d.\n", a, b, remain_a, remain_b);
            #endif
        }
        printf("%d %d\n", a+1,n-b);
    }
    return 0;
}