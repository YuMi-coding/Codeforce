#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cmath>

#define USE_ONLINE_JUDGE
#define MAXN (5)
int input_sauce[MAXN];
int arr[MAXN];
bool input(){
    memset(input_sauce, 0, sizeof(input_sauce));
    for(int i = 0; i < 4; i++){
        if (scanf("%d", &input_sauce[i])== EOF){
            return false;
        }
    }
    return true;
}


int main()
{
    #ifndef USE_ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    while(input())
    {
        int ans = 0; // 1="TRIANGLE", 2="SEGMENT", 0="IMPOSSIBLE"
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < 4; i++)
        {
            int copied = 0, j = 0;
            while(copied < 3){
                if(j == i){
                    j++;
                    continue;
                }
                arr[copied] = input_sauce[j];
                j++;
                copied ++;
                // #ifndef USE_ONLINE_JUDGE
                //     printf("j=%d, copied=%d.\n", j, copied);
                // #endif
            }

            #ifndef USE_ONLINE_JUDGE
                for(int j = 0; j<3; j++)
                {
                    printf("%d ", arr[j]);
                }
                printf("\n");
            #endif 

            std::sort(arr, arr+3);
            if(arr[0] + arr[1] > arr[2])
            {
                ans = 1;
                break;
            }
            else if (arr[0] + arr[1] == arr[2])
            {
                ans = 2;
            }
        }
        switch (ans)
        {
        case 1:
            printf("TRIANGLE\n");
            break;
        case 2:
            printf("SEGMENT\n");
            break;
        default:
            printf("IMPOSSIBLE\n");
            break;
        }
    }
    return 0;
}