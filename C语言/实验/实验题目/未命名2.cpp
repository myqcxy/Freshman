#include "stdlib.h"
#include "graphics.h"
#include "stdio.h"

#define WIDTH 120
#define HEIGHT 120
//��һ����ά���鱣���ͼƬ������ͼƬ���߱�����4�ı���������4�ı���������в��룬������������û�н��в�λ�����ģ���Ҳ�����Լ�ȥ����24λbmpͼƬ�ı����ʽ��Ȼ���֪������ô����
void mian()
{
    FILE *fp;
    unsigned char bmp[16][200];
    unsigned char bmp2[WIDTH][HEIGHT*3];
    int i = 1,size1 = 0,size2 = 0,size0 = 0;
    int j = 0;
    if((fp = fopen("G:\\new\\Boy5.bmp","rb")) == NULL)//��ͼƬ
        exit(0);
    i = 0;
    fseek(fp,54L,0);//BMPͼƬ�����Ǵӵ�54λ��ʼ
//#########����ͼƬ���е�������##########
    while(i < WIDTH*HEIGHT*3)
    {
        *(bmp2[0]+i) = fgetc(fp);
        i++;
    }
    fclose(fp);
    initgraph(700, 700);    // ��ͼ�δ��ڣ��������������֮ǰ����VC�±���ģ�����һ�����ϵĻ�ͼ�⣬��TC�Ĵ�ͼ�ν��溯���������,�ĵ��Ϳ�����
    //####################################���ͼƬ�������Ǵ��ķ�ʽ��ͼ�ν��������    
    for(i = 0;i < (WIDTH-1);)
    {
        for(j =0;j < (HEIGHT-1)*3 ;)
        {
            putpixel(50+(j/3),600-(i/1),RGB((int)bmp2[i][j+2],(int)bmp2[i][j+3],(int)bmp2[i][j+4]));//������ص�
            j+=3;
        }
        i++;
    }
    getchar();
    closegraph();    // �ر�ͼ�δ���
} 

