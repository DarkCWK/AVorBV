#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long a = 177451812, b = 100618342136696320;
char table[59] = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";

// 170001
void abv() // avתbv
{
loop:;
    long long av = 0, table1[10] = {6, 2, 4, 8, 5, 9, 3, 7, 1, 0};
    char Lbv[11] = {0}, bv[11] = {0};

    printf("\n������av��[1-137217728] or ����0����\nav");
    scanf("%lld", &av); //����av��

    switch (getchar()) //�ж���������һ���ַ�
    {
    case '\n': //Ϊ \n ����ȫ����
        if (av > 0 && av < 137217728) //�ж������Ƿ��ڼ��㷶Χ
        {
            av = (av ^ a) + b;
            for (int i = 0; i < 10; i++) //��ȡ���ҵ�bv
            {
                Lbv[i] = table[av / (long long)pow(58, i) % 58]; //��ȡtable���av/pow(58,i)%58λ�ַ�����Lbv��i���ַ�
            }
            Lbv[10] = '\0'; //�����β��
            for (int i = 0; i < 10; i++) //˳����ҵ�bv
            {
                bv[i] = Lbv[table1[i]]; //��Lbv�е�table1�е�i�������ַ�����bv�е�i���ַ�
            }
            bv[10] = '\0';
            printf("BV%s\n", bv); //���BV
        }
        else if (av == 0)
        {
            goto quit; //�˳�abv
        }
        else
        {
            printf("���볬���㷨�ɼ��㷶Χ\n");
        }
        goto loop; //����abv��ͷѭ��
    default: //����Ϊ�Ǵ�����
        printf("����Ǵ�����\n");
        while (getchar() != '\n') //���������
            ;
        goto loop;
    }
quit:;
}

// 17x411w7KC
void bav() // bvתav
{
loop:;
    char bv[11] = {0}, Lbv[11] = {0};
    long long table1[11] = {9, 8, 1, 6, 2, 4, 0, 7, 3, 5}, av = 0;

    printf("\n������BV��[10λӢ�����ֻ��] or ����0����\nBV");
    scanf("%s", bv);

    switch (strlen(bv)) //�ж�bv�ĳ���
    {
    case 10: //Ϊ10λ�ַ���
        for (int i = 0; i < 10; i++) //����bv
        {
            Lbv[i] = bv[table1[i]];
        }
        for (int i = 0; i < 10; i++)
        {
            if (strchr(table, Lbv[i]) != NULL) //�ж��Ƿ��ҵ��ַ�
            {
                av = (58 - strlen(strchr(table, Lbv[i]))) * (long long)pow(58, i) + av;
                //��ȡLBvÿ����ĸ��table��ָ��λ�ò���ȡ�䳤����59��ȥ�����λ��ת����ʮ���Ʋ��ۼ�
            }
            else
            {
                goto error;
            }
        }
        av = (av - b) ^ a;
        printf("av%lld\n", av);
        goto loop;
    default: //��Ϊʮλ��
        if (strcmp(bv, "0"))
        {
        error:;
            printf("�Ƿ�����\n");
            goto loop;
        }
        else
        {
            goto quit;
        }
    }
quit:;
}

int main()
{
    printf("�㷨����֪��@mcfx,��������Github@DarkCWK\n");
    printf("��лBilibili@Dian_Jiao����Ƶav98869161 or BV1N741127Tj\n");
    printf("ѡ�����ֺ�Crtl+C���ɸ��ƣ�����Ҽ�����ճ��\n");
    while (1) //ѭ��
    {
        int a;
        printf("\n1.avתbv\n2.bvתav\n3.�˳�\n(1/2/3)?");
        scanf("%d", &a);
        switch (a) //�ж�a��ֵ
        {
        case 1: //Ϊ1ִ������
            abv(); // avתbv
            break;
        case 2: //Ϊ2ִ������
            bav(); // bvתav
            break;
        case 3: //Ϊ3ִ������
            goto quit; //�˳�
            break;
        default: //Ϊ����ִ������
            printf("�������\n");
            break;
        }
    }
quit:;
    printf("\n");
    system("pause"); //�����������...
    return 0;
}