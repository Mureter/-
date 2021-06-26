#include <stdio.h>
int main()
{
	FILE *fp;
	if((fp = fopen("score_data.txt","r"))==NULL)
	{
		printf("´ò¿ªÊ§°Ü");
	}
}
