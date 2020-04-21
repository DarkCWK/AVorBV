#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long a = 177451812, b = 100618342136696320;
char table[59] = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";

// 170001
void abv() // av转bv
{
loop:;
    long long av = 0, table1[10] = {6, 2, 4, 8, 5, 9, 3, 7, 1, 0};
    char Lbv[11] = {0}, bv[11] = {0};

    printf("\n请输入av号[1-137217728] or 输入0返回\nav");
    scanf("%lld", &av); //输入av号

    switch (getchar()) //判断输入流下一个字符
    {
    case '\n': //为 \n 代表全数字
        if (av > 0 && av < 137217728) //判断数字是否在计算范围
        {
            av = (av ^ a) + b;
            for (int i = 0; i < 10; i++) //获取打乱的bv
            {
                Lbv[i] = table[av / (long long)pow(58, i) % 58]; //获取table里第av/pow(58,i)%58位字符放入Lbv第i个字符
            }
            Lbv[10] = '\0'; //放入结尾符
            for (int i = 0; i < 10; i++) //顺序打乱的bv
            {
                bv[i] = Lbv[table1[i]]; //将Lbv中第table1中第i的数的字符放入bv中第i个字符
            }
            bv[10] = '\0';
            printf("BV%s\n", bv); //输出BV
        }
        else if (av == 0)
        {
            goto quit; //退出abv
        }
        else
        {
            printf("输入超出算法可计算范围\n");
        }
        goto loop; //返回abv开头循环
    default: //否则为非纯数字
        printf("输入非纯数字\n");
        while (getchar() != '\n') //清空输入流
            ;
        goto loop;
    }
quit:;
}

// 17x411w7KC
void bav() // bv转av
{
loop:;
    char bv[11] = {0}, Lbv[11] = {0};
    long long table1[11] = {9, 8, 1, 6, 2, 4, 0, 7, 3, 5}, av = 0;

    printf("\n请输入BV号[10位英文数字混合] or 输入0返回\nBV");
    scanf("%s", bv);

    switch (strlen(bv)) //判断bv的长度
    {
    case 10: //为10位字符串
        for (int i = 0; i < 10; i++) //打乱bv
        {
            Lbv[i] = bv[table1[i]];
        }
        for (int i = 0; i < 10; i++)
        {
            if (strchr(table, Lbv[i]) != NULL) //判断是否找到字符
            {
                av = (58 - strlen(strchr(table, Lbv[i]))) * (long long)pow(58, i) + av;
                //获取LBv每个字母在table的指针位置并获取其长度用59减去获得其位置转换成十进制并累加
            }
            else
            {
                goto error;
            }
        }
        av = (av - b) ^ a;
        printf("av%lld\n", av);
        goto loop;
    default: //不为十位数
        if (strcmp(bv, "0"))
        {
        error:;
            printf("非法输入\n");
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
    printf("算法来自知乎@mcfx,程序作者Github@DarkCWK\n");
    printf("感谢Bilibili@Dian_Jiao的视频av98869161 or BV1N741127Tj\n");
    printf("选中文字后Crtl+C即可复制，鼠标右键即可粘贴\n");
    while (1) //循环
    {
        int a;
        printf("\n1.av转bv\n2.bv转av\n3.退出\n(1/2/3)?");
        scanf("%d", &a);
        switch (a) //判断a的值
        {
        case 1: //为1执行以下
            abv(); // av转bv
            break;
        case 2: //为2执行以下
            bav(); // bv转av
            break;
        case 3: //为3执行以下
            goto quit; //退出
            break;
        default: //为其他执行以下
            printf("输入错误\n");
            break;
        }
    }
quit:;
    printf("\n");
    system("pause"); //按任意键继续...
    return 0;
}