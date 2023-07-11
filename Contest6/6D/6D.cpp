#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

#define USE_ONLINE_JUDGE
#define MAXN (20 + 5)
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

int health[MAXN];
std::vector<int> v_tmp, v_opt;
int n, a, b;
int min_shoots = 0x3fffffff;

int input(){
    v_tmp.clear();
    v_opt.clear();
    min_shoots = 0x3fffffff;
    memset(health, 0, sizeof(health));
    if(scanf("%d%d%d",&n, &a, &b) == EOF){
        return 0;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &health[i+1]); // Align the positions to question marking
    }
    return 1;
}

void dfs(int pos, int shoots){// Trying to shoot n times in this problem
    if(shoots >= min_shoots)
        return;
    if(pos == n){
        if(health[n] < 0){
            v_opt = v_tmp;
            min_shoots = v_opt.size();
        }
        return;
    }
    int killLeft = health[pos-1]/b + 1;
    int killRight = health[pos+1]/b + 1;
    int killThis = health[pos]/a + 1;
    int max_shoot = max(killLeft, max(killRight, killThis));
    
    int min_shoot = max(killLeft, 0);
    if(health[pos-1] <0 )
        min_shoot = 0;
    // printf("@%d, maxshoot=%d, minshoot=%d\n", pos, max_shoot,min_shoot);

    for(int i = min_shoot; i <= max_shoot; i++){
        health[pos-1] -= i*b;
        health[pos] -= i*a;
        health[pos+1] -= i*b;
        for(int s = 1; s <= i; s++)
            v_tmp.push_back(pos);

        dfs(pos+1, shoots+i);

        for(int s = 1; s <= i; s++)
            v_tmp.pop_back();
        health[pos-1] += i*b;
        health[pos] += i*a;
        health[pos+1] += i*b;
    }

}

int main()
{
    #ifndef USE_ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    while(input())
    {
        dfs(2,0);

        // Print out solution
        printf("%ld\n", v_opt.size());
        for(int i = 0; i< v_opt.size(); i++)
        {
            printf("%d ", v_opt[i]);
        }
        printf("\n");
    }
    return 0;
}