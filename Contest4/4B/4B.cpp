#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define USE_ONLINE_JUDGE
struct day{
    int minTime;
    int maxTime;
};

struct day days[40];
int allo[40];
int d,sumTime,alloTime;
int max,min;
bool canDo;

bool DFS(int max_, int min_, int allocated, int sum)
{
    if(allocated>=d)
    {
        // printf("%d\n",sum);
        if(sum == sumTime)
            return true;
        else
            return false;
    }

    if((sumTime-sum)<min_ || (sumTime-sum)>max_)
    {
        // printf("%d %d %d\n",sumTime-sum,max_,min_);
        return false;
    }

    for(int i = days[allocated].minTime; i<=days[allocated].maxTime; i++)
    {
        allo[allocated] = i;

        if(DFS(max_ - days[allocated].maxTime, min_ - days[allocated].minTime, allocated + 1, sum + i))
            return true;
    }

    return false;
}

int main()
{
    #ifndef USE_ONLINE_JUDGE
        freopen("input.txt","rt",stdin);
        freopen("output.txt","wt",stdout);
    #endif

    alloTime = 0;
    max = 0;
    min = 0;
    canDo = true;
    memset(allo,0,sizeof(allo));

    scanf("%d%d",&d,&sumTime);
    for(int i = 0; i<d;i++)
    {
        int maxTime = 0;
        int minTime = 0;
        scanf("%d%d", &minTime, &maxTime);


        days[i].maxTime = maxTime;
        days[i].minTime = minTime;

        max += maxTime;
        min += minTime;
    }

    // printf("%d %d\n", max, min);
    canDo = DFS(max,min,0,0);

    if(!canDo)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for(int i = 0;i<d;i++)
        {
            printf("%d", allo[i]);
            if(i<(d-1))
                printf(" ");
        }
    }

    return 0;
}
