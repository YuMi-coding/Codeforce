#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

#define MAXN (5000+10)


struct env{
    int w;
    int h;
    int best_next;
    int depth;
    int order;
    bool operator >(struct env &rhs)
    {
        if(w>rhs.w && h > rhs.h)
            return true;
        else
            return false;
    }
    bool operator < (const struct env & rhs) const
    {
        if(w==rhs.w)
            return h<rhs.h;
        return w<rhs.w;
    }
};

// struct less_than_key
// {
//     inline bool operator () ( struct env& rhs,  struct env & lhs)
//     {
//         return rhs<lhs;
//     }
// };

int main()
{
    // #ifndef USE_ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
// INPUT
    int n,w,h;

    struct env envs[MAXN];
    memset(envs, 0,sizeof(envs));
    int recorded = 0;
    int readed = 0;
    scanf("%d%d%d", &n, &w, &h);
    
    envs[0].h = h;
    envs[0].w = w;
    envs[0].best_next = -1;
    recorded = 1;

    for(int i = 0; i < n; i++)
    {
        int temp_a = 0, temp_b = 0;
        scanf("%d%d",&temp_a,&temp_b);
        readed ++;

        if( w < temp_a && h < temp_b)
        {
            envs[recorded].w = temp_a;
            envs[recorded].h = temp_b;
            envs[recorded].order = readed;
            recorded ++;
        }
    }
// PROCESS
    std::sort(envs+1, envs+recorded);

    for(int i = 1; i < recorded; i++)
    {
        envs[i].depth = 1;
        envs[i].best_next = 0;
        for(int j = 0; j < i; j++)
        {
            if(envs[i]>envs[j] && (envs[j].depth + 1)>envs[i].depth)
            {
                envs[i].depth = envs[j].depth +1;
                envs[i].best_next = j;
            }
        }
    }

    int max = 0;
    int maxPos = -1;
    for(int i = 0; i <recorded; i++)
    {
        if(envs[i].depth>max)
        {
            max = envs[i].depth;
            maxPos = i;
        }
    }

    if(max)
    {
        int outputLine[MAXN];
        int countOutput = 0;
        outputLine[countOutput++] = envs[maxPos].order;

        int nextEnv = envs[maxPos].best_next;
        while(nextEnv != -1)
        {
            outputLine[countOutput++] = envs[nextEnv].order;
            nextEnv = envs[nextEnv].best_next;
        }
        countOutput--;

        printf("%d\n", max);
        for(int i = countOutput-1; i >= 0; i--)
        {
            printf("%d ", outputLine[i]);
        }
    }
    else
    {
        printf("0\n");
    }
    

    return 0;
}