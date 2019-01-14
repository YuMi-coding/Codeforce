#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>

#define MAXN 1010
#define LENGTH_NAME 35

#define DEBUG
//#define INPUT_REDIRECTION

std::map<std::string,int> name_table;
char input_name[MAXN][LENGTH_NAME];
int input_score[MAXN];
int N = 0;
int exist_player = 0;


void initialize()
{
	//memset(score,0,sizeof(score));
	fscanf(stdin,"%d",&N);
	exist_player = 0;
}


int main()
{
#ifdef INPUT_REDIRECTION
	freopen("in.in","r",stdin);
#endif
	initialize();
	for(int i = 1; i <= N; i++)
	{
		fscanf(stdin,"%s%d",&input_name[i],&input_score[i]);
		name_table[input_name[i]] += input_score[i];
	}

	int max_val = 0;
	for(int i = 1; i<= N; i++)
	{
		if(name_table[input_name[i]]>max_val)
			max_val = name_table[input_name[i]];
	}

	std::map<std::string,int> temp;
	for(int i=1; i<=N;i++)
	{
		temp[input_name[i]] += input_score[i];
		if(temp[input_name[i]]>=max_val && name_table[input_name[i]]>= max_val)
		{
			fprintf(stdout,"%s",input_name[i]);
			break;
		}
	}
	return 0;
}