#include <stdio.h>
#include <stdlib.h>
#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#define N 30
#define tiaogao "Ã¯∏ﬂ"
#define tiaoyuan "Ã¯‘∂"
#define duanpao "∂Ã≈‹"
typedef struct player
{
    char Student_number[10];
    char Student_college[20];
    char name[10];
    int sex;
    char project[20];
    int Ranking;
}PLAYER;
typedef struct Project
{
    int Total_score;
    int man_Total;
    int woman_Total;
    int Tiaogao_score;
    int Tiaoyuan_score;
    int Duanpao_score;
}PROJECT;
typedef struct Ranking_college
{
    char College[20];
    int sex;
    PROJECT ranking_project;
}RANKING;
void in_player_information(int number);
void In_file(PLAYER player[],int number);
void out_file(PLAYER player[],int number_rows,int number);
void calculation_college(PLAYER player[],int judge_number);
void calculation_college_project(RANKING ranking_college[],int number);
void sort_score(RANKING ranking_college[],int number);
int calculation_ranking_score(int ranking);
int open_out_file(char name_file[],RANKING ranking[]);
int open_in_file(char name_file[],PLAYER player[]);
void conditional_display_college(RANKING ranking[],int number,int number_row);
void conditional_display_player(PLAYER player[],int number,int number_row);
void read_file();
void Show_score_2(RANKING ranking[],int number_row);
void Show_score_3(RANKING ranking[],int number_row);
void Show_score_4(RANKING ranking[],int number_row);
void Show_score_5(RANKING ranking[],int number_row);
void Show_score_6(RANKING ranking[],int number_row);
void Show_player(PLAYER player[],int number_row,int sex,char project_sport[]);
void Show_player_own(PLAYER player[],int number_row);
int Show_own_chose(int number_name,PLAYER player_name[]);
void Show_player_score(PLAYER player[],int number_row);
void Show_0();
void Show_1();
void Show_2();
void Show_3();
void Show_4();


#endif // HEAD_H_INCLUDED
