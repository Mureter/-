#include "head.h"
void Show_0()//������
{
    int flag = 1;
    while(flag)
    {
        int input;
        int k = 0;
        printf("*************************************************************\n");
        printf("****����ѡ��\n");
        printf("****[1] ¼���˶�Ա��Ϣ��ɼ�      [2] ��ʾ��ѧԺ�ܷ�����\n");
        printf("****[3] ��ѧԺ������Ϣ            [4] ���˶�Ա�ɼ�����\n");
        printf("****[0] �˳�ϵͳ\n");
    in_input:
        k = scanf("%d",&input);
        if(k == 0)
        {
            printf("�Ƿ����룬����������:\n");
            fflush(stdin);
            goto in_input;
        }
        if(input<0||input>4)
        {
            printf("�Ƿ����룬����������:\n");
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
    printf("*******************************ллʹ�ã�**********************\n");
}
void Show_1()//¼��ɼ�����
{
    int number;
    printf("�����ж��ٸ�ѡ�֣�\n");
    scanf("%d",&number);
    in_player_information(number);
    printf("¼�����\n");
}
void Show_2()//���������洢����
{
    read_file();
}
void Show_3()//���������ѧԺ
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
        printf("û�г�ʼ�ļ���");
        exit(0);
    }
    else
    {
        while(flag)
        {
            system("cls");
            printf("****��ѧԺ������Ϣ*********************************************************************************\n");
            printf("****[1] �����ܷ��������                   [2]  �������ߵ���÷���ߵ�ѧԺ\n");
            printf("****[3] ������Զ����÷���ߵ�ѧԺ         [4]  ���Ҷ���(100��)����÷���ߵ�ѧԺ\n");
            printf("****[5] ����Ů������÷���ߵ�ѧԺ         [6]  ������������÷���ߵ�ѧԺ\n");
            printf("****[0] �˳���ǰҳ��\n");
        in_input:
            k = scanf("%d",&input);
            if(k == 0)
            {
                printf("�����������������!\n");
                fflush(stdin);
                goto in_input;
            }
            if(input<0||input>6)
            {
                printf("�Ƿ����룬����������:\n");
                fflush(stdin);
                goto in_input;
            }
            switch(input)
            {
                case 1:
                    for(i = 0;i<number_row;i++)
                    {
                        printf("������%d\tѧԺ��%18s\t�ܳɼ��� %d\t���������ܷ� %d\t  Ů�������ܷ� %d\t�����ܷ֣� %d\t�����ܷ֣� %d\t��Զ�ܷ֣� %d\n",(i+1),ranking[i].College,ranking[i].ranking_project.Total_score,ranking[i].ranking_project.man_Total,ranking[i].ranking_project.woman_Total,ranking[i].ranking_project.Duanpao_score,ranking[i].ranking_project.Tiaogao_score,ranking[i].ranking_project.Tiaoyuan_score);
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
void Show_4()//�������������
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
        printf("û�г�ʼ�ļ���");
        exit(0);
    }
    else
    {
        while(flag)
        {
            system("cls");
            printf("****���˶�Ա�ɼ�����*********************************************************************************\n\n");
            printf("****[1] ������в�����Ա��Ϣ                 [2] ����˻��ֹ���                    ******************\n");
            printf("****[3] ������������������                                                         ******************\n");
            printf("****[4] ������Զ����������                   [5]  ���Ҷ���(100��)�����鵥������    ******************\n");
            printf("****[6] ��������Ů���������                                                       ******************\n");
            printf("****[7] ������ԶŮ���������                 [8]  ���Ҷ���(100��)Ů���鵥�������  ******************\n");
            printf("****[9] ���ո��˻�����������˶�Ա��Ϣ                                             ******************\n");
            printf("****[0] �˳���ǰҳ��                                                               ******************\n\n");
            printf("****���˶�Ա�ɼ�����*********************************************************************************\n");
        in_input:
            k = scanf("%d",&input);
            if(k == 0)
            {
                printf("�����������������!\n");
                fflush(stdin);
                goto in_input;
            }
            if(input<0||input>9)
            {
                printf("�Ƿ����룬����������:\n");
                fflush(stdin);
                goto in_input;
            }
            switch(input)
            {
                case 1:
                    for(i = 0;i<number_row;i++)
                    {
                        printf("%d\tѧ�ţ�%s\tѧԺ��%18s\t������%s\t   �Ա�%d\t��Ŀ��%s\t���Σ�%d\n",i,player[i].Student_number,player[i].Student_college,player[i].name,player[i].sex,player[i].project,player[i].Ranking);
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
