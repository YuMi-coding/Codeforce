#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cmath>

#define USE_ONLINE_JUDGE
#define MAXN (1000000 + 5)
int n;
int input_sauce[MAXN];
int height[MAXN];
int l[MAXN];
int r[MAXN];
int c[MAXN];

bool input(){
    memset(height, 0, sizeof(height));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    if (scanf("%d", &n)== EOF){
        return false;
    }
    int i = 0;
    for(i = 0; i< n; i++)
        scanf("%d", &input_sauce[i]);
    return true;
}

int adjust_input(){
    int max_pos = 0, max_val = -1;
    for (int i = 0; i<n; i++){
        if(input_sauce[i] > max_val){
            max_val = input_sauce[i];
            max_pos = i;
        }
    }
    for(int i = 0; i<n; i++){
        height[i] = input_sauce[(i+max_pos)%n];
        #ifndef USE_ONLINE_JUDGE
            printf("pos = %d, height = %d.\n", i, height[i]);
        #endif
    }
    height[n] = max_val;

    return 0;
}

int main()
{
    #ifndef USE_ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    while(input())
    {
        adjust_input();
        long long ans = 0;
        for(int i = n; i>=0; --i)
        {
            r[i] = i+1;
            while (r[i] < n && height[i] > height[r[i]])
                r[i] = r[r[i]];
            if (r[i] < n && height[i] == height[r[i]]) {
                c[i] = c[r[i]] + 1;
                r[i] = r[r[i]];
            }
        }
        for(int i = 0; i<n ;i++){
            l[i] = i-1;
            while (l[i] > 0 && height[i] > height[l[i]])
                l[i] = l[l[i]];
            if (l[i] > 0 && height[i] == height[l[i]]){
                // c[i] = c[l[i]] + 1;
                l[i] = l[l[i]];
            }
        }
        for(int i = 1; i<n;i++)
        {
            int addition = c[i];
            if (l[i] == 0 && r[i] == n){
                addition = (1+c[i]);
            }
            else{
                addition = (2+c[i]);
            }
            #ifndef USE_ONLINE_JUDGE
                printf("pos = %d , height = %d, left = %d, right = %d, addition = %d.\n", i, height[i], \
                l[i], r[i], addition);
            #endif
            ans += addition;
        }
        printf("%lld\n", ans);
    }
    return 0;
}