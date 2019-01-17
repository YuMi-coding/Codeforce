#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define MAXN 100010
#define TYPES 5
//#define INPUT_REDIRECTION
struct vehicles{
    int type;
    int capacity;
    int num;
};
struct vehicles ship1[MAXN];
struct vehicles ship2[MAXN];

struct less_than{
    inline bool operator() (const vehicles& a, const vehicles&b)
    {    
        bool res = a.capacity>b.capacity;
        return res;
    }
};

//int used[MAXN];
int n,v;
int one_count;
int two_count;

void input()
{
    //memset(ships,0,sizeof(vehicles[0])*MAXN*TYPES);
    //memset(used,0x7fffffff,sizeof(used));
    one_count = 0;
    two_count = 0;

    fscanf(stdin,"%d%d",&n,&v);
    for(int i = 1;i<=n;i++)
    {
        int type_ = 0;
        int capa_ = 0;
        double ratio_= 0.0;
        fscanf(stdin,"%d%d",&type_,&capa_);
        
        if(type_==1)
        {   
            ship1[one_count].type = type_;
            ship1[one_count].capacity = capa_;
            ship1[one_count].num = i;
            one_count ++;
        }
        else if(type_==2)
        {
            ship2[two_count].type = type_;
            ship2[two_count].capacity = capa_;
            ship2[two_count].num = i;
            two_count ++;
        }    
    }
}

void process()
{
    std::sort(ship1,ship1+one_count,less_than());
    std::sort(ship2,ship2+two_count,less_than());

    int max_1[MAXN];
    int max_2[MAXN];
    int count_1 = 0, count_2 = 0;
    for(int i = 0; i<n;i++)
    {
        if(ship1[i].type!=1)
            break;
        count_1 += ship1[i].capacity;
        max_1[i+1] = count_1;
    }

    for(int i = 0; i<n;i++)
    {
        if(ship2[i].type!=2)
            break;
        count_2 += ship2[i].capacity;
        max_2[i+1] = count_2;
    }

    int max = 0;
    int max_i = 0;
    int max_j = 0;

    for(int i = 0;i<=one_count;i++)// i is the count of ship1
    {
        int j = (v - i)/2;
        if(j<0)
            break;
        int this_max = 0;
        if(j>two_count)
            j = two_count;
            
        this_max = max_1[i] + max_2[j];
        if(this_max>max)
        {
            max = this_max;
            max_i = i;
            max_j = j;
        }
    }

    fprintf(stdout,"%d\n",max);
    for(int i = 0;i<max_i;i++)
    {
        fprintf(stdout,"%d ",ship1[i].num);
    }
    for(int i = 0;i<max_j;i++)
    {
        fprintf(stdout,"%d ",ship2[i].num);
    }

    fprintf(stdout,"\n");
    
}

int main()
{
#ifdef INPUT_REDIRECTION
	freopen("in.in","r",stdin);
#endif
    input();
    process();
    return 0;
}