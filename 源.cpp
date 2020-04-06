//B19030334雷尚远[面向旅客的大部分功能]:订票、退票、改签、选座界面及相关限制
//余票查询、航班查询、排序[面向客户]; 旅客订票信誉
#include<iostream>
#include <windows.h>
#include"function.h"
using namespace std;
int j = 0;
#ifndef StructDefine
#define StructDefine
typedef struct FlightID //用于表示航班号，航班号只代表航班基本信息。
{
	char Carrier[4] = { 'X','X','X','X' };						//航空公司，用两个大写字母表示
	char ID[8] = { 'X','X' ,'X' ,'X','X','X' ,'X' ,'X' };								//航班号
	char FlyDay[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X' };							//开航日期，以星期为周期，星期几与数组下标对应，开航为1，不开航为0
	char DepartureAirport[8] = { 'X','X','X' ,'X' ,'X' ,'X' ,'X' ,'X' };				//出发机场，三字码，为标明航站楼等，以字符串形式存储，注意结尾的\0
	char ArrivalAirport[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X' };					//抵达机场，三字码，为标明航站楼等，以字符串形式存储，注意结尾的\0
	int DepartureTime = 2500;					//出发时刻，四字码
	int ArrivalTime = 2500;					//到达时刻，四字码。eg 1230（12时30分）
	int TravelTimeHour = 0;//飞行时间(时)
	int TravelTimeMinute = 0;//飞行时间(分)
	int Price = 0;
	char AircraftType[4] = { 'X','X' ,'X' };					//飞机型号，三字码。eg 787，350
	char Class[4] = { 'X','X' ,'X' ,'X' };							//舱位，两舱或三舱，注意结尾的\0。
}FlightID;

typedef struct FlightTicket //每日机票情况
{
	int Seat[50][10] = { 0 };
	int ActuralDepartureTime = 2500;
	int ActuralArrivalTime = 2500;
	int FirstClassTicketRemain = 0;
	int BusinessClassTicketRemain = 0;
	int EconomyClassTicketRemain = 0;
}FlightTicket;
#endif // !struct
static FlightID ID[999];//默认最多存储999个航线 全局变量所有函数均可访问
static FlightTicket DATA[366][999];//存储一年的航班数据
void PreBooking();
void head();
int DateTransfer(int year, int month, int day);//变化为天数
int WeekDayTransfer(int year, int month, int day);//变化为星期数
int JudgeAircraftSize(FlightID* ID, int n);//判断机型
int order();//系统选项界面
void Booking(FlightTicket* DATA, int n, char Class, char seat[3], int account, int size);
void Refunding(FlightTicket* DATA, int n, char seat[3], int account, char Class);
int Changing();
int Searching(FlightID* ID, FlightTicket* DATA, int daycount);
int main()
{
	int x=0;
	head();
	x=order();
	switch (x)
	{
	case 0: head(); break;
	}
	return 0;
}