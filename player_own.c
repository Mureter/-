#include "head.h"
void conditional_display_player(PLAYER player[],int number,int number_row)//���и��������Ϣ���ܵ���
{
        switch(number)
        {
            case 2:
                Show_player_own(player,number_row);
                break;
            case 3:
                Show_player(player,number_row,1,tiaogao);
                break;
            case 4:
                Show_player(player,number_row,1,tiaoyuan);
                break;
            case 5:
                Show_player(player,number_row,1,duanpao);
                break;
            case 6:
                Show_player(player,number_row,0,tiaogao);
                break;
            case 7:
                Show_player(player,number_row,0,tiaoyuan);
                break;
            case 8:
                Show_player(player,number_row,0,duanpao);
                break;
            case 9:
                Show_player_score(player,number_row);
                break;

        }
}
void Show_player_own(PLAYER player[],int number_row)//��ʾѡ�е��˶�Ա����ϸ��Ϣ
{
    int i,k;
    PLAYER player_name[N];
    int number_name,flag;
    int number_chose;
    number_chose = 0;
    number_name = 0;
    flag = 0;
    strcpy(player_name[0].name,player[0].name);
    for(i = 0;i<=number_row-1;i++)
    {
        for(k = 0;k<i;k++)
        {
            if(!strcmp(player_name[k].name,player[i].name))
            {
                flag = 1;
            }
        }
        if(flag != 1&&i>0)
        {
            number_name++;
            strcpy(player_name[number_name].name,player[i].name);
        }
    }
    number_chose = Show_own_chose((number_name+1),player_name)-1;
    printf("%s  �Ļ��ֹ���Ϊ��\n",player_name[number_chose].name);
    printf("�Ա�(1Ϊ��/0ΪŮ)\t  ѧԺ\t\t��Ŀ\t����\t����\n");
    for(i = 0;i<number_row;i++)
    {
        if(!strcmp(player_name[number_chose].name,player[i].name))
        {
            int score = calculation_ranking_score(player[i].Ranking);
            printf("%d\t%22s\t\t%s\t%d\t%d\n",player[i].sex,player[i].Student_college,player[i].project,player[i].Ranking,score);
        }
    }
}
int Show_own_chose(int number_name,PLAYER player_name[])//ѡ��鿴�Ǹ��˵Ļ���
{
    int i,k;
    int input;
    printf("ѡ���ѯ��������\n");
    for(i = 0;i<number_name;i++)
    {
        printf("\t%d��%s\n",(i+1),player_name[i].name);
    }
in_put_name:
    k = scanf("%d",&input);
    if(k == 0)
    {
        printf("�Ƿ�����,����������!\n");
        fflush(stdin);
        goto in_put_name;
    }
    if(input<1||input>number_name)
    {
        printf("�Ƿ�����,����������!\n");
        fflush(stdin);
        goto in_put_name;
    }
    return input;
}
void Show_player_score(PLAYER player[],int number_row)//��ʾ���˻���������Ϣ
{
    int i,k;
    int sum_score;
    PLAYER player_name[N];
    int number_name,flag;
    int number_chose;
    int t_control_i;
    int t_control = 4;
    number_chose = 0;
    number_name = 0;
    sum_score = 0;
    flag = 0;
    strcpy(player_name[0].name,player[0].name);
    printf("���˻���������\n����\t\t\t��Ŀ/����/�������\t\t����\n");
    for(i = 0;i<=number_row-1;i++)
    {
        for(k = 0;k<i;k++)
        {
            if(!strcmp(player_name[k].name,player[i].name))
            {
                flag = 1;
            }
        }
        if(flag != 1&&i>0)
        {
            number_name++;
            strcpy(player_name[number_name].name,player[i].name);
        }
    }
    for(i = 0;i<(number_name+1);i++)
    {
        for(k = 0;k<number_row;k++)
        {
            if(!strcmp(player_name[i].name,player[k].name))
            {
                sum_score = sum_score+calculation_ranking_score(player[i].Ranking);
            }
        }
        player_name[i].sex = sum_score;
        sum_score = 0;
    }
    for(i = 0;i<number_name;i++)
    {
        for(k = 0;k<(number_name-i);k++)
        {
            if(player_name[k].sex<player_name[k+1].sex)
            {
                int tep = 0;
                char name[20];
                strcpy(name,player_name[k].name);
                tep = player_name[k].sex;
                strcpy(player_name[k].name,player_name[k+1].name);
                player_name[k].sex = player_name[k+1].sex;
                strcpy(player_name[k+1].name,name);
                player_name[k+1].sex = tep;
            }
        }
    }
    printf("number_name ��%d\n",number_name);
    for(i = 0;i<(number_name+1);i++)
    {
        printf("%s\t\t\t",player_name[i].name);
        for(k = 0;k<number_row;k++)
        {
            if(!strcmp(player_name[i].name,player[k].name))
            {
                int score =calculation_ranking_score(player[k].Ranking);
                t_control--;
                printf("%s/%d/%d ",player[k].project,player[k].Ranking,score);
            }
        }
        for(t_control_i = 0;t_control_i<t_control;t_control_i++)
        {
            printf("\t");
        }
        printf("%d\n",player_name[i].sex);
        t_control = 4;
    }
}
void Show_player(PLAYER player[],int number_row,int sex,char project_sport[])//��ʾ�����ø��˵�һ������
{
    int i,j,k;
    char name[20];
    int ranking[5];
    for(i = 0;i<5;i++)
    {
        ranking[i]= 0;
    }
    j = 0;
    int count = 5;
    for(i = 0;i<number_row;i++)
    {

        if(player[i].sex == sex)
        {

            if(!strcmp(player[i].project,project_sport))
            {
                ranking[j] = i;
                j++;
            }
        }
    }
    if(j>=1)
    {
        for(i = 0;i<j-1;i++)
        {
            for(k = 0;k<j-i-1;k++)
            {
                if(player[ranking[k]].Ranking > player[ranking[k+1]].Ranking)
                {
                    int tep = 0;
                    tep = ranking[k+1];
                    ranking[k+1] = ranking[k];
                    ranking[k] = tep;
                }
            }
        }
        if(sex == 0)
        {
            for(i = 0;i<j;i++)
            {
                printf("Ů����%s�� %d�� Ϊ %s\n",project_sport,player[ranking[i]].Ranking,player[ranking[i]].name);
            }
        }
        else if(sex == 1)
        {
            for(i = 0;i<j;i++)
            {
                printf("������%s�� %d�� Ϊ %s\n",project_sport,player[ranking[i]].Ranking,player[ranking[i]].name);
            }
        }
        printf("ȱ��%d����Ա��Ϣ\n",(5-j));
    }
    else if(j == 0)
    {
        if(sex == 0)
        {
            printf("δ¼��Ů��%s�����Ϣ\n",project_sport);
        }
        else if(sex == 1)
        {
            printf("δ¼������%s�����Ϣ\n",project_sport);
        }
    }
}
