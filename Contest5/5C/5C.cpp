#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

#define MAXN (1000000 + 50)
char line[MAXN];
int distance[MAXN];
int closing[MAXN];
std::stack<int> brkStk;

int initialize()
{
    memset(distance, 0, sizeof(distance));
    memset(closing, 0, sizeof(closing));
    return 0;
}

int main()
{
    // #ifndef USE_ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif

    memset(line,0, sizeof(line));
    while (std::cin.getline(line,MAXN))
    {
        initialize();
        int lineLength = strlen(line);
        // printf("%d\n",lineLength);
        for(int i = 0; i<lineLength; i++)
        {
            if(line[i] == '(')
                brkStk.push(i);
            else
            {
                if(brkStk.empty())
                {
                    distance[i] = -1;
                    closing[i] = -1;
                }
                else
                {
                    distance[i] = brkStk.top();
                    brkStk.pop();
                    closing[i] = distance[i];
                    if(distance[i]>=1 && line[distance[i]-1] ==')' && closing[distance[i]-1] != -1)
                        closing[i] = closing[distance[i]-1];
                }
            }
        }

        int ans = 0, count = 1;
        for(int i = 0; i<lineLength; i++)
        {
            if(line[i] == ')' && closing[i] != -1)
            {
                if((i-closing[i] + 1)> ans)
                {
                    ans = i - closing[i] + 1;
                    count = 1;
                }
                else if((i - closing[i] + 1) == ans)
                    count ++;
            }
        }
        printf("%d %d\n", ans, count);
        
        memset(line,0, sizeof(line));
    }

    return 0;
}