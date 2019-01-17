#include <cstdio>
#include <cstring>

//#define INPUT_REDIRECTION
#define MAXN 5

char chess[MAXN][MAXN];
int countX;
int count0;

void input()
{
    countX = 0;
    count0 = 0;
    memset(chess,0,sizeof(chess[0][0])*MAXN*MAXN);

    char temp[MAXN];
    for(int i = 1;i<=3;i++)
    {
        fscanf(stdin,"%s",temp);
        chess[i][1] = temp[0];
        chess[i][2] = temp[1];
        chess[i][3] = temp[2];
    }

    for(int i = 1;i<=3;i++)
    {
        for(int j = 1; j<=3;j++)
        {
            if(chess[i][j]=='X')
            {
                countX ++;
            }
            else if(chess[i][j]=='0')
            {
                count0 ++;
            }
        }
    }
}

bool someone_won(char someone)
{
    bool result = false;

    for(int i = 1; i<=3;i++)
        if(chess[i][1]==chess[i][2]&&chess[i][2]==chess[i][3]&&chess[i][3]==someone)
            result = true;
    
    for(int i = 1; i<=3;i++)
        if(chess[1][i]==chess[2][i]&&chess[2][i]==chess[3][i]&&chess[3][i]==someone)
            result = true;
    
    if(chess[1][1]==chess[2][2]&&chess[2][2]==chess[3][3]&&chess[3][3]==someone)
        result = true;
    if(chess[3][1]==chess[2][2]&&chess[2][2]==chess[1][3]&&chess[1][3]==someone)
        result = true;

    return result;
}


void process()
{
    if(count0>countX||(countX-count0)>1)
    {
        fprintf(stdout,"illegal\n");
        return;
    }
    
    bool first_won = false;
    bool second_won = false;

    if(someone_won('X'))
    {
        first_won = true;
    }
    
    if(someone_won('0'))
    {
        second_won = true;
    }

    if(second_won&&first_won)
    {
        fprintf(stdout,"illegal\n");
        return;
    }
    
    if(first_won)
    {
        if(countX==count0||(countX-count0)>1)
        {
            fprintf(stdout,"illegal\n");
            return;
        }
        fprintf(stdout,"the first player won\n");
        return;
    }

    if(second_won)
    {
        if(countX>count0)
        {
            fprintf(stdout,"illegal\n");
            return;
        }
        fprintf(stdout,"the second player won\n");
        return;
    }

    if((countX+count0)==9)
    {
        fprintf(stdout,"draw\n");
        return;
    }

    if(countX>count0)
    {
        fprintf(stdout,"second\n");
        return;
    }
    else
    {
        fprintf(stdout,"first\n");
        return;
    }
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