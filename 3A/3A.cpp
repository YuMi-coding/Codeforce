#include <cstdio>
#include <cstring>
#define MAXN 10 
//#define INPUT_REDIRECTION
char cOfs,cOft,ph;
int iOfs,iOft;
char first[MAXN];
char second[MAXN];

void input()
{
    memset(first,0,sizeof(first));
    memset(second,0,sizeof(second));
    //fscanf(stdin,"%c%d%c%c%d",&cOfs,&iOfs,&ph,&cOft,&iOft);
    fscanf(stdin,"%s",first);
    fscanf(stdin,"%s",second);
    cOfs = first[0];
    iOfs = first[1];
    cOft = second[0];
    iOft = second[1];
    //fscanf(first,"%c%d",&cOfs,&iOfs);
    //fscanf(second,"%c%d",&cOft,&iOft);
}

void process()
{
    int diff_v = cOft - cOfs;
    int diff_h = iOft - iOfs;

    int abs_v = diff_v>0?diff_v:-diff_v;
    int abs_h = diff_h>0?diff_h:-diff_h;
    int res_step = abs_v>abs_h?abs_v:abs_h;
    fprintf(stdout,"%d\n",res_step);
    for(int i = 1; i<= res_step;i++)
    {
        if(diff_v>0)
        {
            putchar('R');
            diff_v--;
        }
        else if(diff_v<0)
        {
            putchar('L');
            diff_v++;
        }
        if(diff_h>0)
        {
            putchar('U');
            diff_h--;
        }
        else if(diff_h<0)
        {
            putchar('D');
            diff_h++;
        }
        putchar('\n');
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