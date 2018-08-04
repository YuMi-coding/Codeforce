#include <cstdio>
#include <cstring>
#include <string>
//#define DEBUG
int N = 0;
char line[20];

void initiate()
{
	memset(line,0,sizeof(line));
}

bool isRXCY(char* line)
{
	if(line[0]!='R')//Not begin with 'R'
		return false;

	//Begin with 'R', check whether followed by numbers
	int check_pos = 1;// check number of R
	while(line[check_pos]<='9' && line[check_pos]>='0')
		check_pos ++;
	if(check_pos==1)// No numbers contained
		return false;

	//Numbers following 'R', check whether there is 'C'
	if(line[check_pos]!='C')
		return false;
	else return true;
}

bool convertFromRXCY(char * line)
{
	char num[10];
	int num_pos = 0;
	memset(num,0,sizeof(num));
	
	int check_pos = 1;// skip 'R'
	while(line[check_pos]<='9' && line[check_pos]>='0')
	{
		num[num_pos++] = line[check_pos];// Direct copy from X
		check_pos ++;
	}
#ifdef DEBUG
	printf("R=%s\n", num);
#endif
	check_pos ++;// skip 'C'
	int column_num = 0;
	while(line[check_pos]<='9' && line[check_pos]>='0')
	{
		column_num *=10;
		column_num += line[check_pos]-'0';
		check_pos ++;
	}
#ifdef DEBUG
	printf("C=%d\n", column_num);
#endif
	char column[10];
	int column_pos = 0;
	memset(column,0,sizeof(column));
	while(column_num>26)
	{
		column_num -= 1;
		column[column_pos] = column_num%26 + 'A';
		column_num /= 26;//REVERTED ORDER of column
		column_pos ++;
	}
	column_num -= 1;
	column[column_pos] = column_num%26  + 'A';
#ifdef DEBUG
	printf("%s\n",column);
#endif
	for(int i = strlen(column); i>=0;i--)
	{
		if(column[i]>='A'&&column[i]<='Z')
			fprintf(stdout,"%c",column[i]);
	}

	fprintf(stdout, "%s\n", num);

	return true;
}

bool convertFromBC23(char* line)
{
	int check_pos = 0;
	int R = 0;
	int C = 0;

	while(line[check_pos]<='Z' && line[check_pos]>='A')
	{
		C *= 26;
		C += (line[check_pos]-'A'+1);
		check_pos ++;
	}

	while(line[check_pos]<='9' && line[check_pos]>='0')
	{
		R *= 10;
		R += (line[check_pos]-'0');
		check_pos ++;
	}

	fprintf(stdout, "R%dC%d\n", R,C);

	return true;
}

int main()
{
	fscanf(stdin,"%d",&N);
	while(N--)
	{
		initiate();
		fscanf(stdin,"%s",line);
		if(isRXCY(line))// In RXCY type
		{
#ifdef DEBUG
			printf("is RXCY\n");
#endif
			convertFromRXCY(line);
		}
		else// In BC23 type
		{
#ifdef DEBUG
			printf("is not RXCY\n");
#endif
			convertFromBC23(line);
		}
	}
	return 0;
}