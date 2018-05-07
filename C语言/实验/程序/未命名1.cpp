#include<stdio.h>  
  
int main()  
{  
    char c;  
    int sum=0,count=1;  
    while(1)  
    {         
        scanf("%c",&c);  
        if(c == '\n')  
            break;  
        sum += (int)c-48;  
    }  
    int m = sum;    
    while(m/10>0)           //求是几位数     
    {    
        count++;    
        m /= 10;     
    }    
    int array[count];  
    int i,k;  
    for(i=count-1;i>=0;i--)   
    {  
        k = sum%10;  
        array[i] = k;  
        sum /= 10;  
    }  
    for(i=0;i<count;i++)  
    {  
        if(i!=0)  
            printf(" ");   
        switch(array[i])  
        {  
            case 0:  
                printf("ling");  
                break;  
            case 1:  
                printf("yi");  
                break;  
            case 2:  
                printf("er");  
                break;  
            case 3:  
                printf("san");  
                break;  
            case 4:  
                printf("si");  
                break;  
            case 5:  
                printf("wu");  
                break;  
            case 6:  
                printf("liu");  
                break;  
            case 7:  
                printf("qi");  
                break;  
            case 8:  
                printf("ba");  
                break;  
            case 9:  
                printf("jiu");  
                break;            
        }  
    }  
        return 0;  
 }  
