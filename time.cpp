#include <time.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()
{
	//字符指针初始化
	//char* Now_time = (char*)malloc(30)
	//char* Now_date = (char*)malloc(30)
	//char* buffer = (char*)malloc(30)
	//数据初始化
	char Now_time[30];
	char Now_date[30];
	char buffer[64]; 
	_strdate(Now_date); //获取当前日期
	_strtime(Now_time); //获取当前时间
	strcat(Now_date," "); //日期后面加空格
	strcat(Now_date,Now_time); //合并日期和时间
	//输出格式化
    sprintf(buffer,"Current Date is %s and Time is %s",Now_date,Now_time);
	cout<<Now_date<<endl;
    cout<<buffer<<endl;
	//getch();
	return 0 ;
}
