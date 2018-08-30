#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>

#define MAXN 1000
#define LENGTH_NAME 35
#define HASH 12281

#define DEBUG
#define INPUT_REDIRECTION

std::map<std::string,int> name_table;
char input_name[MAXN][LENGTH_NAME];
int input_score[MAXN];
int N = 0;
int exist_player = 0;

int hash(char *input)
{
	int length = strlen(input);

}

void initialize()
{
	memset(score,0,sizeof(score));
	fscanf(stdin,"%d",&N);
	exist_player = 0;
}

void process()
{
	char max_name[LENGTH_NAME] = {0};
	int max_value = -1;
	for(int iter = 0; iter<N;iter++)
	{
		int temp_score = 0;
		char temp_name[LENGTH_NAME] ={0};

		fscanf(stdin,"%s",&temp_name);
		memcpy(input_name[iter],temp_name,sizeof(temp_name));
		fscanf(stdin,"%d",&temp_score);
		input_score[iter] = temp_score;

#ifdef DEBUG
		fprintf(stdout, "Read:%s,%d\n",temp_name,temp_score);
#endif
		//std::map<std::string,int> iterator i = name_table.find(temp_name);
		if(name_table.find(temp_name)==name_table.end())
		{
			if(!exist_player) // Do not have players yet
			{
#ifdef DEBUG
		fprintf(stdout, "NO exist player\n" );
#endif
				exist_player ++;
				memcpy(max_name,temp_name,sizeof(temp_name));
				max_value = temp_score;

				name_table.insert(std::pair<std::string,int>(temp_name,temp_score));
			}
			else
			{
#ifdef DEBUG
		fprintf(stdout,"No this player exist\n");
#endif
				if(temp_score > max_value)
				{
					memcpy(max_name,temp_name,sizeof(max_name));
					max_value = temp_score;
				} 
				name_table.insert(std::pair<std::string,int>(temp_name,temp_score));
			}
		}
		else
		{
#ifdef DEBUG
		fprintf(stdout, "Existing player, modifying\n");
#endif
			int current_value = name_table[temp_name];
			current_value += temp_score;
			if(current_value > max_value)
			{
				memcpy(max_name,temp_name,sizeof(max_name));
				max_value = current_value;
			} 
			name_table[temp_name] = current_value;
		}
		
	}
#ifdef DEBUG
	std::map<std::string,int>::const_iterator it;
	for(it = name_table.begin();it != name_table.end();++it)
		fprintf(stdout, "%s:%d\n",it->first,it->second);
#endif
	std::map<std::string,int>::const_iterator it;
	for(it = name_table.begin();it != name_table.end();++it)
		fprintf(stdout, "%s:%d\n",it->first,it->second);
}

int main()
{
#ifdef INPUT_REDIRECTION
	freopen("in.in","r",stdin);
#endif
	initialize();
	process();
	return 0;
}