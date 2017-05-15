#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
//获取{}里的内容
void get_bracket_string(char *pSrc,char **ppStart,char **ppEnd)
{
   char * temp = NULL;

   while('{' != *pSrc)
   {
       pSrc++;
   }
   //得到括号里内容的起始地址
   temp = ++pSrc;

   while('}' != *pSrc)
   {
       pSrc++;
   }

   if ((NULL != ppEnd) && (NULL != ppEnd))
   {
      *ppStart = temp;
      *ppEnd   = --pSrc;
   }
   //返回内容长度
   return;
}
//解析{}里的内容
void parse_bracket_string(char *Buf,char *pStart,char * pEnd)
{
  char temp[255] = {0};
  char *result = NULL;
  int index = 0;
	
  //不会自动补0,但是数组已初始化，所以不需要手工补0  
  strncpy(temp,pStart,pEnd-pStart+1);

  //一个/都没有说明是{上海}
  if(NULL == strstr(temp,"/"))
  {
	Buf[index++] = temp[0];
	Buf[index++] = temp[1];
	Buf[index++] = temp[2];
	Buf[index++] = temp[3];
	Buf[index++] = temp[4];
	Buf[index++] = temp[5];
	return;
  }

  //以/作为分割符
  result=strtok(temp,"/");
  while(NULL != result)
  {
	//由于中文是3个字符保存的，所以需要取3个
	Buf[index++] = result[0];
	Buf[index++] = result[1];
	Buf[index++] = result[2];
	result=strtok(NULL,"/");
  }
  return;
}
 
//显示
void show_answer(char *first,char *second,char *third)
{
	char Temp1[255] = {0};
	char Temp2[255] = {0};
	char *Temp3 = NULL;
	char *Temp4 = NULL;
	for(int i=0 ;i<9;i+=3)
	{
		for(int j = 0;j<6;j+=3)
		{

			memcpy(Temp1,&first[i],sizeof(char)*3);
			memcpy(Temp2,&second[j],sizeof(char)*3);
			
			printf("A%sC%s%s\n",Temp1,Temp2,third);

			memset(Temp1,0,sizeof(Temp1));
			memset(Temp2,0,sizeof(Temp2));

		}

	}
	return;

}

int main()
{
   char  question[] = "A{你/我/}C{去/往}{上海}";
   //分别用于保持第一，第二，第三个括号里的内容
   char  first[255]  = {0};
   char  second[255] = {0};
   char  third[255]  = {0};
   char *pStart = NULL;
   char *pEnd   = NULL;
   int   length = 0;
  
   //获取第一个{}里的内容
   get_bracket_string(question,&pStart,&pEnd);
   //解析第一个{}里的内容
   parse_bracket_string(first,pStart,pEnd);
   
   
   //获取第二个{}里的内容
   get_bracket_string(pEnd,&pStart,&pEnd);
   //解析第二个{}里的内容
   parse_bracket_string(second,pStart,pEnd); 

   //获取第三个{}里的内容
   get_bracket_string(pEnd,&pStart,&pEnd);
   //解析第三个{}里的内容
   parse_bracket_string(third,pStart,pEnd); 

   //显示
   show_answer(first,second,third);
	
   return 0;
}
