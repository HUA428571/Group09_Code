#include<iostream>
#include<stdio.h>
#include"struct.h"
using namespace std;

int WeekDayTransfer(int year, int month, int day)//使用蔡勒公式转换日期与星期
{
	int week = 0;
	int century = year / 100;//注意这边实际上是年份的前两位，不是世纪数
	year = year % 100;//年份的后两位
	if (month == 1 || month == 2)//月份的范围为3-14，所以1月2月变成了13月14月
	{
		month += 12;
		year--;
	}
	week = year + year / 4 + century / 4 - 2 * century + (26 * (month + 1)) / 10 + day - 1;
	week = week % 7;
	return (week >= 0) ? week : (7 + week);
}

int DateTransfer(int year, int month ,int day)//返回日期对应天数
{
	int daycount=0;
	if (year % 4 == 0 && year % 100 != 0)
		daycount++;
	switch (month)
	{
	case 12:
		daycount += 30;
	case 11:
		daycount += 31;
	case 10:
		daycount += 30;
	case 9:
		daycount += 31;
	case 8:
		daycount += 31;
	case 7:
		daycount += 30;
	case 6:
		daycount += 31;
	case 5:
		daycount += 30;
	case 4:
		daycount += 31;
	case 3:
		daycount += 28;
	case 2:
		daycount += 31;
		daycount += day;
	break;
	}
	return daycount;
}

int ImportFlightDatabase(FlightID* ID)//用于在开头询问是否要引入现有航线数据库,函数返回读取航班个数
{
	char choice;
	do {
		cout << "导入默认航班号数据？" << endl;
		cin >> choice;
	} while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
	if (choice == 'y' || choice == 'Y')
	{
		FILE* fp;
		if ((fp = fopen(".\\Default_FlightID_Database_2.txt", "r")) == NULL)
		{
			printf("Fail to open file!\n");
			return 0;
		}
		int FlightIDcount = 0;
		char c;
		while (!feof(fp))
		{
			int i = 1;
			while ((c = fgetc(fp)) != ',')//读取班期
			{
				ID[FlightIDcount].FlyDay[i] = c;
				i++;
			}
			i = 0;
			while ((c = fgetc(fp)) != ',')//读取出发机场
			{
				ID[FlightIDcount].DepartureAirport[i] = c;
				i++;
			}
			ID[FlightIDcount].DepartureAirport[i] = '\0';//字符串结尾
			fscanf_s(fp, "%d", &ID[FlightIDcount].DepartureTime);//读取出发时间
			fgetc(fp);
			fscanf_s(fp, "%d", &ID[FlightIDcount].ArrivalTime);//读取到达时间
			i = 0;
			fgetc(fp);
			while ((c = fgetc(fp)) != ',')//读取到达机场
			{
				ID[FlightIDcount].ArrivalAirport[i] = c;
				i++;
			}
			ID[FlightIDcount].ArrivalAirport[i] = '\0';//字符串结尾
			i = 0;
			while (i < 2)//读取航空公司
			{
				c = fgetc(fp);
				ID[FlightIDcount].Carrier[i] = c;
				i++;
			}
			ID[FlightIDcount].Carrier[i] = '\0';//字符串结尾
			i = 0;
			while ((c = fgetc(fp)) != ',')//读取航班号
			{
				ID[FlightIDcount].ID[i] = c;
				i++;
			}
			ID[FlightIDcount].ID[i] = '\0';//字符串结尾
			i = 0;
			while ((c = fgetc(fp)) != ',')//读取机型
			{
				ID[FlightIDcount].AircraftType[i] = c;
				i++;
			}
			ID[FlightIDcount].AircraftType[i] = '\0';//字符串结尾
			i = 0;
			while (((c = fgetc(fp)) != ','))//读取舱位
			{
				ID[FlightIDcount].Class[i] = c;
				i++;
			}
			ID[FlightIDcount].Class[i] = '\0';//字符串结尾
			fscanf_s(fp, "%d", &ID[FlightIDcount].TravelTimeHour);//读取飞行时间
			c=fgetc(fp);//读取冒号
			fscanf_s(fp, "%2d", &ID[FlightIDcount].TravelTimeMinute);
			FlightIDcount++;
			if ((c = fgetc(fp)) == EOF)break;
		}
		fclose(fp);
		cout << "成功导入" << FlightIDcount << "个航线数据！" << endl;
		return FlightIDcount;
	}
	if (choice == 'n' || choice == 'N')
	{
		return 0;
	}
}

void PrintFlightTitle()//打印标题栏
{
	printf("编号\t航班号\t\t起飞时间\t起飞机场\t到达机场\t到达时间\t飞行时间\t执飞机型\n");
	return;
}

void PrintFlight(FlightID* ID, int n,int i)//传入数组，编号
{
	printf("%d\t%s%s\t\t%04d\t\t%s\t\t%s\t\t%04d\t\t%d小时%02d分钟\t%s\n",i,ID[n].Carrier,ID[n].ID, ID[n].DepartureTime, ID[n].DepartureAirport, ID[n].ArrivalAirport, ID[n].ArrivalTime, ID[n].TravelTimeHour, ID[n].TravelTimeMinute, ID[n].AircraftType);
	return;
}

void PrintFlightTicket()
{
	;
}

int SearchFlightID(int search)//查找航班号，返回查询到个数
{
	return 0;
}
