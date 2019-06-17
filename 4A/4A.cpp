#include <cstdio>
#include <cstring>
#define USE_ONLINE_JUDGE
int w;
int main()
{
    #ifndef USE_ONLINE_JUDGE
        freopen("input.txt","rt",stdin);
        freopen("output.txt","wt",stdout);
    #endif
    scanf("%d", &w);
    if((w-2)>0 && (w-2)%2 ==0)
        printf("YES\n");
    else
        printf("NO\n");    

    return 0;
}