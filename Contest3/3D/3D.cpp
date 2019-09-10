#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define USE_ONLINE_JUDGE
#define MAXN (50000+10)

char inputLine[MAXN];
short level[MAXN];
int leftCost[MAXN];
int rightCost[MAXN];
int countUnknown;
int countLine;
bool canDo;

struct bracket{
    int diff;
    int position;
    bool operator < (const bracket& r) const{
        return diff > r.diff;
    }
};

std::priority_queue<bracket,std::vector<bracket>,std::less<bracket> > priorityQ;

void initialize()
{
    #ifndef USE_ONLINE_JUDGE
        freopen("input.txt","rt",stdin);
        freopen("output.txt","wt",stdout);
    #endif

    canDo = true;
    memset(inputLine,0,sizeof(inputLine));
    memset(level,0,sizeof(level));

    return;
}

void readInput()
{
    // char
    char c = 0;
    scanf("%s",inputLine);
    countLine = strlen(inputLine);


    // int
    int leftCount = 0;
    int rightCount = 0;
    long long totalCost = 0;
    for(int i = 0; i < countLine; i ++)
    {
        if(inputLine[i] == '(') 
            leftCount ++;
        else if(inputLine[i] == ')')
            rightCount ++;
        else
        {
            int leftCost = 0;
            int rightCost = 0;
            scanf("%d%d", &leftCost, &rightCost);
            totalCost += rightCost;
            inputLine[i] = ')';
            rightCount ++;
            struct bracket temp;
            temp.position = i;
            temp.diff = leftCost - rightCost;
            priorityQ.push(temp);
        }

        if(leftCount<rightCount)
        {
            if(priorityQ.empty())
            {
                canDo = false;
                //printf("error in pos:%d\n", i);
            }
            else
            {
                totalCost += priorityQ.top().diff;
                inputLine[priorityQ.top().position] = '(';
                priorityQ.pop();
                rightCount --;
                leftCount ++;
            }
        }
    }

    if(!canDo || leftCount!= rightCount)
        printf("-1\n");
    else
    {
        printf("%I64d\n",totalCost);
        printf("%s",inputLine);
        printf("\n");
    }

    return;
}

int main()
{
    initialize();
    readInput();

    return 0;
}