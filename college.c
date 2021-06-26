#include "head.h"
void conditional_display_college(RANKING ranking[],int number,int number_row)
{
    switch(number)
    {
        case 2:
            Show_score_2(ranking,number_row);
            break;
        case 3:
            Show_score_3(ranking,number_row);
            break;
        case 4:
            Show_score_4(ranking,number_row);
            break;
        case 5:
            Show_score_5(ranking,number_row);
            break;
        case 6:
            Show_score_6(ranking,number_row);
            break;
    }
}
void Show_score_2(RANKING ranking[],int number_row)
{
    int i;
    char max[20];
    int max_score;
    strcpy(max,ranking[0].College);
    max_score = ranking[0].ranking_project.Tiaogao_score;
    for(i = 0;i<number_row;i++)
    {
        if(max_score<ranking[i].ranking_project.Tiaogao_score)
        {
            strcpy(max,ranking[i].College);
            max_score = ranking[i].ranking_project.Tiaogao_score;
        }
    }
    printf("%s成绩最高的学院为：%s\n其成绩为：%d",tiaogao,max,max_score);
}
void Show_score_3(RANKING ranking[],int number_row)
{
    int i;
    char max[20];
    int max_score;
    strcpy(max,ranking[0].College);
    max_score = ranking[0].ranking_project.Tiaoyuan_score;
    for(i = 0;i<number_row;i++)
    {
        if(max_score<ranking[i].ranking_project.Tiaoyuan_score)
        {
            strcpy(max,ranking[i].College);
            max_score = ranking[i].ranking_project.Tiaoyuan_score;
        }
    }
    printf("%s成绩最高的学院为：%s\n其成绩为：%d",tiaoyuan,max,max_score);
}
void Show_score_4(RANKING ranking[],int number_row)
{
    int i;
    char max[20];
    int max_score;
    strcpy(max,ranking[0].College);
    max_score = ranking[0].ranking_project.Duanpao_score;
    for(i = 0;i<number_row;i++)
    {
        if(max_score<ranking[i].ranking_project.Duanpao_score)
        {
            strcpy(max,ranking[i].College);
            max_score = ranking[i].ranking_project.Duanpao_score;
        }
    }
    printf("%s成绩最高的学院为：%s\n其成绩为：%d",duanpao,max,max_score);
}
void Show_score_5(RANKING ranking[],int number_row)
{
    int i;
    char max[20];
    int max_score;
    strcpy(max,ranking[0].College);
    max_score = ranking[0].ranking_project.woman_Total;
    for(i = 0;i<number_row;i++)
    {
        if(max_score<ranking[i].ranking_project.woman_Total)
        {
            strcpy(max,ranking[i].College);
            max_score = ranking[i].ranking_project.woman_Total;
        }
    }
    printf("女子团体成绩最高的学院为：%s\n其成绩为：%d",max,max_score);
}
void Show_score_6(RANKING ranking[],int number_row)
{
    int i;
    char max[20];
    int max_score;
    strcpy(max,ranking[0].College);
    max_score = ranking[0].ranking_project.man_Total;
    for(i = 0;i<number_row;i++)
    {
        if(max_score<ranking[i].ranking_project.man_Total)
        {
            strcpy(max,ranking[i].College);
            max_score = ranking[i].ranking_project.man_Total;
        }
    }
    printf("男子团体成绩最高的学院为：%s\n其成绩为：%d",max,max_score);
}
