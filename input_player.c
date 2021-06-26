#include "head.h"
void in_player_information(int number)
{
    PLAYER player[N];
    int i;
    int k = 0;
    int count;
    i = 0;
    count = number;
    for(i = 0;i<number;i++)
    {

    in_student_number:
        printf("输入选手学号:\n");
        k = scanf("%s",player[i].Student_number);
        if(k == 0)
        {
            printf("输入错误，请重新输入!\n");
            fflush(stdin);
            goto in_student_number;
        }
        int student_number = atoi(player[i].Student_number);
        if(student_number<19000000||student_number>19999999)
        {
            printf("输入错误，请重新输入\n");
            fflush(stdin);
            goto in_student_number;
        }
    in_student_college:
        printf("输入选手学院:\n");
        k = scanf("%s",player[i].Student_college);
        if(k == 0)
        {
            printf("输入错误，请重新输入\n");
            fflush(stdin);
            goto in_student_college;
        }
    in_student_name:
        printf("输入选手姓名:\n");
        k = scanf("%s",player[i].name);
        if(k == 0)
        {
            printf("输入错误，请重新输入\n");
            fflush(stdin);
            goto in_student_name;
        }
    in_student_sex:
        printf("输入选手性别(1为男生，0为女生):\n");
        k = scanf("%d",&player[i].sex);
        if(k == 0)
        {
            printf("输入错误，请重新输入\n");
            fflush(stdin);
            goto in_student_sex;
        }
        if(player[i].sex!=0)
        {
            if(player[i].sex!=1)
            {
                printf("输入错误，请重新输入\n");
                fflush(stdin);
                goto in_student_sex;
            }
        }
    in_student_project:
        printf("输入选手项目(跳高、跳远、短跑):\n");
        k = scanf("%s",player[i].project);
        if(k == 0)
        {
            printf("输入错误，请重新输入\n");
            fflush(stdin);
            goto in_student_project;
        }
        if(strcmp(player[i].project,tiaogao))
        {
            if(strcmp(player[i].project,tiaoyuan))
            {
                if(strcmp(player[i].project,duanpao))
                {
                    printf("输入错误，请重新输入\n");
                    fflush(stdin);
                    goto in_student_project;
                }
            }
        }
    in_student_ranking:
        printf("输入选手名次:\n");
        k = scanf("%d",&player[i].Ranking);
        if(k == 0)
        {
            printf("输入错误，请重新输入\n");
            fflush(stdin);
            goto in_student_ranking;
        }
        if(player[i].Ranking<1||player[i].Ranking>5)
        {
            printf("输入错误，请重新输入\n");
            fflush(stdin);
            goto in_student_ranking;
        }
    }
    In_file(player,number);
}
void In_file(PLAYER player[],int number)
{
    FILE *judge_fp;
    if((judge_fp = fopen("sport_data.txt","r"))==NULL)
    {
        printf("文件打开失败，请先创建文件!!!\n");
        exit(0);
    }
    else
    {
        rewind(judge_fp);
        int i,j = 0;
        int c = fgetc(judge_fp);
        if(c == EOF)
        {
            j = 0;
        }
        else
        {
            rewind(judge_fp);
            if(judge_fp)
            {
                while((c = fgetc(judge_fp)) !=EOF)
                {
                    if(c=='\n')
                    {
                        j++;
                    }
                }
            }
        }
        fclose(judge_fp);
        if(j == 0)
        {
            FILE *in_fp;
            if((in_fp = fopen("sport_data.txt","w"))==NULL)
            {
                printf("文件打开失败，请先创建文件!!!\n");
                exit(0);
            }
            for(i = 0;i<number;i++)
            {
                fprintf(in_fp,"%s\t%s\t%s\t%d\t%s\t%d\n",player[i].Student_number,player[i].Student_college,player[i].name,player[i].sex,player[i].project,player[i].Ranking);
            }
            fclose(in_fp);
        }
        else
        {
            out_file(player,j,number);
        }
    }
}
void out_file(PLAYER player[],int number_rows,int number)
{
    FILE *out_fp;
    PLAYER out_player[N];
    int i;
    if((out_fp = fopen("sport_data.txt","r"))==NULL)
    {
        printf("文件打开失败，请先创建文件!!!\n");
        exit(0);
    }
    for(i = 0;i<number_rows;i++)
    {
        fscanf(out_fp,"%s",out_player[i].Student_number);
        fscanf(out_fp,"%s",out_player[i].Student_college);
        fscanf(out_fp,"%s",out_player[i].name);
        fscanf(out_fp,"%d",&out_player[i].sex);
        fscanf(out_fp,"%s",out_player[i].project);
        fscanf(out_fp,"%d",&out_player[i].Ranking);
    }
    for(i = 0;i<number;i++)
    {
        strcpy(out_player[number_rows+i].Student_number,player[i].Student_number);
        strcpy(out_player[number_rows+i].Student_college,player[i].Student_college);
        strcpy(out_player[number_rows+i].name,player[i].name);
        out_player[number_rows+i].sex = player[i].sex;
        strcpy(out_player[number_rows+i].project,player[i].project);
        out_player[number_rows+i].Ranking = player[i].Ranking;
    }
    fclose(out_fp);
    FILE *in_fp;
    if((in_fp = fopen("sport_data.txt","w"))== NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    for(i = 0;i<(number+number_rows);i++)
    {
        fprintf(in_fp,"%s\t%s\t%s\t%d\t%s\t%d\n",out_player[i].Student_number,out_player[i].Student_college,out_player[i].name,out_player[i].sex,out_player[i].project,out_player[i].Ranking);
    }
    fclose(in_fp);
}
void read_file()
{
    FILE *judge_fp;
    PLAYER player[N];
    int i,j;
    j = 0;
    if((judge_fp = fopen("sport_data.txt","r"))==NULL)
    {
        printf("文件打开失败，请先创建文件!!!\n");
        exit(0);
    }
    int c = fgetc(judge_fp);
    if(c == EOF)
    {
        j = 0;
        calculation_college(player,j);
        fclose(judge_fp);
    }
    else
    {
        if(judge_fp)
        {
            while((c = fgetc(judge_fp)) !=EOF)
            {
                if(c=='\n')
                {
                    j++;
                }
            }
        }
        rewind(judge_fp);
        for(i = 0;i<j;i++)
        {
            fscanf(judge_fp,"%s",player[i].Student_number);
            fscanf(judge_fp,"%s",player[i].Student_college);
            fscanf(judge_fp,"%s",player[i].name);
            fscanf(judge_fp,"%d",&player[i].sex);
            fscanf(judge_fp,"%s",player[i].project);
            fscanf(judge_fp,"%d",&player[i].Ranking);
        }
        calculation_college(player,j);
    }
}
int calculation_ranking_score(int ranking)
{
   switch(ranking)
   {
        case 1:
            return 7;
            break;
        case 2:
            return 5;
            break;
        case 3:
            return 3;
            break;
        case 4:
            return 2;
            break;
        case 5:
            return 1;
            break;
   }
}
void sort_score(RANKING ranking_college[],int number)//按照积分高低进行排名
{
    RANKING ranking_college2;
    int i,j;
    i = 0;
    j = 0;
    if(number > 1)
    {
        for(i = 0;i<number-1;i++)
        {

            for(j = 0;j<number-1-i;j++)
            {
                if(ranking_college[j].ranking_project.Total_score < ranking_college[j+1].ranking_project.Total_score)
                {
                    strcpy(ranking_college2.College,ranking_college[j].College);
                    ranking_college2.sex = ranking_college[j].sex;
                    ranking_college2.ranking_project.Total_score = ranking_college[j].ranking_project.Total_score;
                    ranking_college2.ranking_project.woman_Total = ranking_college[j].ranking_project.woman_Total;
                    ranking_college2.ranking_project.man_Total = ranking_college[j].ranking_project.man_Total;
                    ranking_college2.ranking_project.Duanpao_score = ranking_college[j].ranking_project.Duanpao_score;
                    ranking_college2.ranking_project.Tiaogao_score = ranking_college[j].ranking_project.Tiaogao_score;
                    ranking_college2.ranking_project.Tiaoyuan_score = ranking_college[j].ranking_project.Tiaoyuan_score;

                    strcpy(ranking_college[j].College,ranking_college[j+1].College);
                    ranking_college[j].sex = ranking_college[j+1].sex;
                    ranking_college[j].ranking_project.Total_score = ranking_college[j+1].ranking_project.Total_score;
                    ranking_college[j].ranking_project.woman_Total = ranking_college[j+1].ranking_project.woman_Total;
                    ranking_college[j].ranking_project.man_Total   = ranking_college[j+1].ranking_project.man_Total;
                    ranking_college[j].ranking_project.Duanpao_score = ranking_college[j+1].ranking_project.Duanpao_score;
                    ranking_college[j].ranking_project.Tiaogao_score = ranking_college[j+1].ranking_project.Tiaogao_score;
                    ranking_college[j].ranking_project.Tiaoyuan_score = ranking_college[j+1].ranking_project.Tiaoyuan_score;

                    strcpy(ranking_college[j+1].College,ranking_college2.College);
                    ranking_college[j+1].sex = ranking_college2.sex;
                    ranking_college[j+1].ranking_project.Total_score = ranking_college2.ranking_project.Total_score;
                    ranking_college[j+1].ranking_project.woman_Total = ranking_college2.ranking_project.woman_Total;
                    ranking_college[j+1].ranking_project.man_Total = ranking_college2.ranking_project.man_Total;
                    ranking_college[j+1].ranking_project.Duanpao_score = ranking_college2.ranking_project.Duanpao_score;
                    ranking_college[j+1].ranking_project.Tiaogao_score = ranking_college2.ranking_project.Tiaogao_score;
                    ranking_college[j+1].ranking_project.Tiaoyuan_score = ranking_college2.ranking_project.Tiaoyuan_score;
                }
            }
        }
    }

}
void calculation_college_project(RANKING ranking_college[],int number)//计算积分
{
    int i,j,number_college,judge;
    RANKING ranking_score[N];
    number_college = 1;
    judge = 0;
    strcpy(ranking_score[0].College,ranking_college[0].College);
    ranking_score[0].sex = ranking_college[0].sex;
    ranking_score[0].ranking_project.Duanpao_score = 0;
    ranking_score[0].ranking_project.man_Total = 0;
    ranking_score[0].ranking_project.Tiaoyuan_score = 0;
    ranking_score[0].ranking_project.Total_score = 0;
    ranking_score[0].ranking_project.woman_Total = 0;
    ranking_score[0].ranking_project.Tiaogao_score = 0;
    for(i = 0;i<number;i++)
    {

        for(j = 0;j<=i;j++)
        {
            if(!strcmp(ranking_score[j].College,ranking_college[i].College))
            {

                judge = 1;
            }
        }
        if(judge == 0)
        {
            strcpy(ranking_score[number_college].College,ranking_college[i].College);
            ranking_score[number_college].ranking_project.Duanpao_score = 0;
            ranking_score[number_college].ranking_project.man_Total = 0;
            ranking_score[number_college].ranking_project.Tiaoyuan_score = 0;
            ranking_score[number_college].ranking_project.Total_score = 0;
            ranking_score[number_college].ranking_project.woman_Total = 0;
            ranking_score[number_college].ranking_project.Tiaogao_score = 0;
            ranking_score[number_college].sex = ranking_college[i].sex;
            number_college++;
        }
        judge = 0;
    }
    for(j = 0;j<number_college;j++)
    {
        for(i = 0;i<number;i++)
        {
            if(!strcmp(ranking_score[j].College,ranking_college[i].College))
            {
                if(ranking_score[j].sex==ranking_college[i].sex&&ranking_score[j].sex == 1)
                {
                    ranking_score[j].ranking_project.man_Total = ranking_score[j].ranking_project.man_Total+ranking_college[i].ranking_project.Tiaoyuan_score+ranking_college[i].ranking_project.Duanpao_score+ranking_college[i].ranking_project.Tiaogao_score;
                }
                else if(ranking_score[j].sex==ranking_college[i].sex&&ranking_score[j].sex == 0)
                {
                    ranking_score[j].ranking_project.woman_Total = ranking_score[j].ranking_project.woman_Total+ranking_college[i].ranking_project.Tiaoyuan_score+ranking_college[i].ranking_project.Duanpao_score+ranking_college[i].ranking_project.Tiaogao_score;
                }
            }
        }
    }
    for(j = 0;j<number_college;j++)
    {
        for(i = 0;i<number;i++)
        {
            if(!strcmp(ranking_score[j].College,ranking_college[i].College))
            {
                ranking_score[j].ranking_project.Duanpao_score = ranking_score[j].ranking_project.Duanpao_score+ranking_college[i].ranking_project.Duanpao_score;
                ranking_score[j].ranking_project.Tiaoyuan_score = ranking_score[j].ranking_project.Tiaoyuan_score+ranking_college[i].ranking_project.Tiaoyuan_score;
                ranking_score[j].ranking_project.Tiaogao_score = ranking_score[j].ranking_project.Tiaogao_score+ranking_college[i].ranking_project.Tiaogao_score;
            }
        }
    }
    for(i = 0;i<number_college;i++)
    {
        ranking_score[i].ranking_project.Total_score = ranking_score[i].ranking_project.Duanpao_score+ranking_score[i].ranking_project.Tiaogao_score+ranking_score[i].ranking_project.Tiaoyuan_score;
    }
    FILE *in_fp;
    if((in_fp = fopen("score_data.txt","w"))==NULL)
    {
        printf("文件打开失败");
        exit(0);
    }
    sort_score(ranking_score,number_college);
    printf("学院:    \t\t 总分\t 男子团体得分\t 女子团体得分\t 短跑得分\t 跳高得分\t 跳远得分\n");
    for(i = 0;i<number_college;i++)
    {
        printf("%16s\t %d\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",ranking_score[i].College,ranking_score[i].ranking_project.Total_score,ranking_score[i].ranking_project.man_Total,ranking_score[i].ranking_project.woman_Total,ranking_score[i].ranking_project.Duanpao_score,ranking_score[i].ranking_project.Tiaogao_score,ranking_score[i].ranking_project.Tiaoyuan_score);
        fprintf(in_fp,"%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",ranking_score[i].College,ranking_score[i].sex,ranking_score[i].ranking_project.Total_score,ranking_score[i].ranking_project.man_Total,ranking_score[i].ranking_project.woman_Total,ranking_score[i].ranking_project.Duanpao_score,ranking_score[i].ranking_project.Tiaogao_score,ranking_score[i].ranking_project.Tiaoyuan_score);
    }
    fclose(in_fp);
}
void calculation_college(PLAYER player[],int judge_number)//初始化积分数组
{
    int i;
    RANKING ranking_college[N];
    if(judge_number == 0)
    {
        printf("未存在运动员数据\n");
    }
    else
    {
        for(i = 0;i<judge_number;i++)
        {

            strcpy(ranking_college[i].College,player[i].Student_college);
            ranking_college[i].sex = player[i].sex;
            if(!strcmp(tiaogao,player[i].project))
            {
                ranking_college[i].ranking_project.Duanpao_score = 0;
                ranking_college[i].ranking_project.man_Total = 0;
                ranking_college[i].ranking_project.Tiaoyuan_score = 0;
                ranking_college[i].ranking_project.Total_score = 0;
                ranking_college[i].ranking_project.woman_Total = 0;
                ranking_college[i].ranking_project.Tiaogao_score =calculation_ranking_score(player[i].Ranking);
            }
            else if(!strcmp(tiaoyuan,player[i].project))
            {
                ranking_college[i].ranking_project.Duanpao_score = 0;
                ranking_college[i].ranking_project.man_Total = 0;
                ranking_college[i].ranking_project.Tiaogao_score = 0;
                ranking_college[i].ranking_project.Total_score = 0;
                ranking_college[i].ranking_project.woman_Total = 0;
                ranking_college[i].ranking_project.Tiaoyuan_score = calculation_ranking_score(player[i].Ranking);
            }
            else if(!strcmp(duanpao,player[i].project))
            {
                ranking_college[i].ranking_project.Tiaogao_score = 0;
                ranking_college[i].ranking_project.man_Total = 0;
                ranking_college[i].ranking_project.Tiaoyuan_score = 0;
                ranking_college[i].ranking_project.Total_score = 0;
                ranking_college[i].ranking_project.woman_Total = 0;
                ranking_college[i].ranking_project.Duanpao_score = calculation_ranking_score(player[i].Ranking);
            }
        }
        calculation_college_project(ranking_college,judge_number);
    }
}
int open_out_file(char name_file[],RANKING ranking[])//打开score_data文件
{
    FILE *out_fp;
    int i,j,c;
    j = 0;
    if((out_fp = fopen(name_file,"r"))==NULL)
    {
        printf("文件打开错误");
        exit(0);
    }
    else
    {
        c = fgetc(out_fp);
        if(c == EOF)
        {
            j = 0;
            fclose(out_fp);
        }
        else
        {
            rewind(out_fp);
            if(out_fp)
            {
                while((c = fgetc(out_fp)) !=EOF)
                {
                    if(c == '\n')
                    {
                        j++;
                    }
                }
            }

        }
        rewind(out_fp);
        for(i = 0;i<j;i++)
        {
            fscanf(out_fp,"%s",ranking[i].College);
            fscanf(out_fp,"%d",&ranking[i].sex);
            fscanf(out_fp,"%d",&ranking[i].ranking_project.Total_score);
            fscanf(out_fp,"%d",&ranking[i].ranking_project.man_Total);
            fscanf(out_fp,"%d",&ranking[i].ranking_project.woman_Total);
            fscanf(out_fp,"%d",&ranking[i].ranking_project.Duanpao_score);
            fscanf(out_fp,"%d",&ranking[i].ranking_project.Tiaogao_score);
            fscanf(out_fp,"%d",&ranking[i].ranking_project.Tiaoyuan_score);
        }
        fclose(out_fp);
    }
    return j;
}
int open_in_file(char name_file[],PLAYER player[])//将文件里的数据读到数组里
{
    FILE *out_fp;
    int i,j,c;
    j = 0;
    if((out_fp = fopen(name_file,"r"))==NULL)
    {
        printf("文件打开错误");
        exit(0);
    }
    else
    {
        c = fgetc(out_fp);
        if(c == EOF)
        {
            j = 0;
            fclose(out_fp);
        }
        else
        {
            rewind(out_fp);
            if(out_fp)
            {
                while((c = fgetc(out_fp)) !=EOF)
                {
                    if(c == '\n')
                    {
                        j++;
                    }
                }
            }

        }
        rewind(out_fp);
        for(i = 0;i<j;i++)
        {
            fscanf(out_fp,"%s",player[i].Student_number);
            fscanf(out_fp,"%s",player[i].Student_college);
            fscanf(out_fp,"%s",player[i].name);
            fscanf(out_fp,"%d",&player[i].sex);
            fscanf(out_fp,"%s",player[i].project);
            fscanf(out_fp,"%d",&player[i].Ranking);
        }
    }
}
