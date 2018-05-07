#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
  char str1[1004], str2[1004];
  int i, j, k, demo, t, len1, len2;
  scanf("%d", &t);
  while(t>0)
  {
      t--;demo=0;k=0;
      char str3[1008];
      scanf("%s%s", str1, str2);
      len1=strlen(str1);len2=strlen(str2);
      for(i=len1-1,j=len2-1;i>=0&&j>=0;i--,j--)
      {
          str3[k++]=(str1[i]+str2[j]-2*'0'+demo)%10+'0';
          demo=(str1[i]+str2[j]-2*'0'+demo)/10;
      }
      if(len1>len2)
      {
          for(;i>=0;i--){
          str3[k++]=(demo+str1[i]-'0')%10+'0';
          demo=(demo+str1[i]-'0')/10;}
      }
      else
      {
          for(;j>=0;i--){
          str3[k++]=(demo+str2[i]-'0')%10+'0';
          demo=(demo+str2[i]-'0')/10;}
      }
      if(demo>0)
      {
        str3[k++]=demo+'0';
      }
      for(i=k-1;i>=0;i--)
      {
          printf("%c", str3[i]);
      }
      printf("\n");
   }
  return 0;
}

