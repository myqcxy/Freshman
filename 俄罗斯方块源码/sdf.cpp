#include <graphics.h>      // ������Ҫ�������ͼ�ο�
#include <conio.h>
void main()
{
    initgraph(640, 480);   // ����� TC ��������
    circle(200, 200, 1); // ��Բ��Բ��(200, 200)���뾶 100
    getch();               // �����������
    closegraph();          // �ر�ͼ�ν���
}