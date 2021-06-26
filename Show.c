#include "head.h"
void Show_0()//主界面
{
    int flag = 1;
    while(flag)
    {
        int input;
        int k = 0;
        printf("*************************************************************\n");
        printf("****功能选择：\n");
        printf("****[1] 录入运动员信息与成绩      [2] 显示各学院总分排名\n");
        printf("****[3] 按学院查找信息            [4] 按运动员成绩查找\n");
        printf("****[0] 退出系统\n");
    in_input:
        k = scanf("%d",&input);
        if(k == 0)
        {
            printf("非法输入，请重新输入:\n");
            fflush(stdin);
            goto in_input;
        }
        if(input<0||input>4)
        {
            printf("非法输入，请重新输入:\n");
            fflush(stdin);
            goto in_input;
        }
        switch(input)
        {
            case 1:
                Show_1();
                system("pause");
                break;
            case 2:
                Show_2();
                system("pause");
                break;
            case 3:
                Show_3();
                break;
            case 4:
                Show_4();
                break;
            case 0:
                flag = 0;
                break;
        }
        system("cls");
    }
    printf("*******************************谢谢使用！**********************\n");
}
void Show_1()//录入成绩功能
{
    int number;
    printf("输入有多少个选手：\n");
    scanf("%d",&number);
    in_player_information(number);
    printf("录入完成\n");
}
void Show_2()//进行排名存储功能
{
    read_file();
}
void Show_3()//按条件输出学院
{
    RANKING ranking[N];
    char name_file[20];
    int k,number_row,i;
    int input;
    int flag = 1;
    strcpy(name_file,"score_data.txt");
    number_row = 0;
    number_row = open_out_file(name_file,ranking);
    if(number_row == 0)
    {
        printf("没有初始文件！");
        exit(0);
    }
    else
    {
        while(flag)
        {
            system("cls");
            printf("****按学院查找信息*********************************************************************************\n");
            printf("****[1] 按照总分输出排名                   [2]  查找跳高单项得分最高的学院\n");
            printf("****[3] 查找跳远单项得分最高的学院         [4]  查找短跑(100米)单项得分最高的学院\n");
            printf("****[5] 查找女子团体得分最高的学院         [6]  查找男子团体得分最高的学院\n");
            printf("****[0] 退出当前页面\n");
        in_input:
            k = scanf("%d",&input);
            if(k == 0)
            {
                printf("输入错误，请重新输入!\n");
                fflush(stdin);
                goto in_input;
            }
            if(input<0||input>6)
            {
                printf("非法输入，请重新输入:\n");
                fflush(stdin);
                goto in_input;
            }
            switch(input)
            {
                case 1:
                    for(i = 0;i<number_row;i++)
                    {
                        printf("排名第%d\t学院：%18s\t总成绩： %d\t男子团体总分 %d\t  女子团体总分 %d\t短跑总分： %d\t跳高总分： %d\t跳远总分： %d\n",(i+1),ranking[i].College,ranking[i].ranking_project.Total_score,ranking[i].ranking_project.man_Total,ranking[i].ranking_project.woman_Total,ranking[i].ranking_project.Duanpao_score,ranking[i].ranking_project.Tiaogao_score,ranking[i].ranking_project.Tiaoyuan_score);
                    }
                    system("pause");
                    break;
                case 2:
                    conditional_display_college(ranking,input,number_row);
                    system("pause");
                    break;
                case 3:
                    conditional_display_college(ranking,input,number_row);
                    system("pause");
                    break;
                case 4:
                    conditional_display_college(ranking,input,number_row);
                    system("pause");
                    break;
                case 5:
                    conditional_display_college(ranking,input,number_row);
                    system("pause");
                    break;
                case 6:
                    conditional_display_college(ranking,input,number_row);
                    system("pause");
                    break;
                case 0:
                    flag = 0;
                    break;
            }
        }
    }

}
void Show_4()//按条件输出个人
{
    PLAYER player[N];
    char name_file[20];
    int k,number_row,i;
    int input;
    int flag = 1;
    strcpy(name_file,"sport_data.txt");
    number_row = 0;
    number_row = open_in_file(name_file,player);
    if(number_row == 0)
    {
        printf("没有初始文件！");
        exit(0);
    }
    else
    {
        while(flag)
        {
            system("cls");
            printf("****按运动员成绩查找*********************************************************************************\n\n");
            printf("****[1] 输出所有参赛人员信息                 [2] 查个人积分构成                    ******************\n");
            printf("****[3] 查找跳高男子组排名                                                         ******************\n");
            printf("****[4] 查找跳远男子组排名                   [5]  查找短跑(100米)男子组单项排名    ******************\n");
            printf("****[6] 查找跳高女子组第排名                                                       ******************\n");
            printf("****[7] 查找跳远女子组第排名                 [8]  查找短跑(100米)女子组单项第排名  ******************\n");
            printf("****[9] 按照个人积分排名输出运动员信息                                             ******************\n");
            printf("****[0] 退出当前页面                                                               ******************\n\n");
            printf("****按运动员成绩查找*********************************************************************************\n");
        in_input:
            k = scanf("%d",&input);
            if(k == 0)
            {
                printf("输入错误，请重新输入!\n");
                fflush(stdin);
                goto in_input;
            }
            if(input<0||input>9)
            {
                printf("非法输入，请重新输入:\n");
                fflush(stdin);
                goto in_input;
            }
            switch(input)
            {
                case 1:
                    for(i = 0;i<number_row;i++)
                    {
                        printf("%d\t学号：%s\t学院：%18s\t姓名：%s\t   性别：%d\t项目：%s\t名次：%d\n",i,player[i].Student_number,player[i].Student_college,player[i].name,player[i].sex,player[i].project,player[i].Ranking);
                    }
                    system("pause");
                    break;
                case 2:
                    conditional_display_player(player,input,number_row);
                    system("pause");
                    break;
                case 3:
                    conditional_display_player(player,input,number_row);
                    system("pause");
                    break;
                case 4:
                    conditional_display_player(player,input,number_row);
                    system("pause");
                    break;
                case 5:
                    conditional_display_player(player,input,number_row);
                    system("pause");
                    break;
                case 6:
                    conditional_display_player(player,input,number_row);
                    system("pause");
                    break;
                case 7:
                    conditional_display_player(player,input,number_row);
                    system("pause");
                break;
                case 8:
                    conditional_display_player(player,input,number_row);
                    system("pause");
                    break;
                case 9:
                    conditional_display_player(player,input,number_row);
                    system("pause");
                    break;
                case 0:
                    flag = 0;
                    break;

            }
        }

    }
}
