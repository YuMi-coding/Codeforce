#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cmath>

#define USE_ONLINE_JUDGE
#define MAXN (100 + 5)
char map[MAXN][MAXN];
int n,m;
int count[255];
char dummy;
char pres;

int input(){
    memset(map, 0, MAXN*MAXN);
    memset(count, 0, sizeof(count));
    if(scanf("%d%d%c%c%c",&n, &m, &dummy, &pres, &dummy) == EOF){
        return 0;
    }
    #ifndef USE_ONLINE_JUDGE
        printf("%d %d %c\n", n, m, pres);
    #endif
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%c", &map[i][j]);
            #ifndef USE_ONLINE_JUDGE
                printf("%c ", map[i][j]);
            #endif
        }
        scanf("%c", &dummy);
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
        int ans = 0;
        for(int i =0; i<n;i++){
            for(int j=0; j<m;j++){
                if(map[i][j] == pres){
                    #ifndef USE_ONLINE_JUDGE
                        printf("Hit present desk at %d %d.\n", i, j);
                    #endif
                    if(i>0){
                        if(map[i-1][j] != '.' && map[i-1][j] != pres){
                            count[int(map[i-1][j])] ++;
                            #ifndef USE_ONLINE_JUDGE
                                printf("i=%d, j=%d,up element hit %c\n", i, j, map[i-1][j]);
                            #endif
                        }
                    }
                    if(j>0){
                        if(map[i][j-1] != '.' && map[i][j-1] != pres){
                            count[int(map[i][j-1])] ++;
                            #ifndef USE_ONLINE_JUDGE
                                printf("i=%d, j=%d,left element hit %c\n", i, j, map[i][j-1]);
                            #endif
                        }
                    }
                    if(i<(n-1)){
                        if(map[i+1][j] != '.' && map[i+1][j] != pres){
                            count[int(map[i+1][j])] ++;
                            #ifndef USE_ONLINE_JUDGE
                                printf("i=%d, j=%d,down element hit %c\n", i, j, map[i+1][j]);
                            #endif
                        }
                    }
                    if(j< (m-1)){
                        if(map[i][j+1] != '.' && map[i][j+1] != pres){
                            count[int(map[i][j+1])] ++;
                            #ifndef USE_ONLINE_JUDGE
                                printf("i=%d, j=%d,right element hit %c\n", i, j, map[i][j+1]);
                            #endif
                        }
                    }
                }
            }
        }

        for(int i = 0; i<255; i++){
            if(count[i] > 0)
                ans ++;
        }
        printf("%d\n", ans);
    }
    return 0;
}