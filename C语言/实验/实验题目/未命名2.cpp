#include "stdlib.h"
#include "graphics.h"
#include "stdio.h"

#define WIDTH 120
#define HEIGHT 120
//用一个二维数组保存的图片，这里图片长高必须是4的倍数，不是4的倍数必须进行补齐，但是这里面是没有进行补位操作的，你也可以自己去看看24位bmp图片的编码格式，然后就知道该怎么用了
void mian()
{
    FILE *fp;
    unsigned char bmp[16][200];
    unsigned char bmp2[WIDTH][HEIGHT*3];
    int i = 1,size1 = 0,size2 = 0,size0 = 0;
    int j = 0;
    if((fp = fopen("G:\\new\\Boy5.bmp","rb")) == NULL)//打开图片
        exit(0);
    i = 0;
    fseek(fp,54L,0);//BMP图片阵列是从第54位开始
//#########读入图片阵列到数组中##########
    while(i < WIDTH*HEIGHT*3)
    {
        *(bmp2[0]+i) = fgetc(fp);
        i++;
    }
    fclose(fp);
    initgraph(700, 700);    // 打开图形窗口，这里这个函数我之前是在VC下编译的，用了一个网上的绘图库，与TC的打开图形界面函数有所差别,改掉就可以了
    //####################################输出图片，这里是打点的方式在图形界面输出，    
    for(i = 0;i < (WIDTH-1);)
    {
        for(j =0;j < (HEIGHT-1)*3 ;)
        {
            putpixel(50+(j/3),600-(i/1),RGB((int)bmp2[i][j+2],(int)bmp2[i][j+3],(int)bmp2[i][j+4]));//输出像素点
            j+=3;
        }
        i++;
    }
    getchar();
    closegraph();    // 关闭图形窗口
} 

