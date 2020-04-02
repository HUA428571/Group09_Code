#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
//原结构体，出发和到达时间均为字符数组
//typedef struct FlightID //用于表示航班号，航班号只代表航班基本信息。
//{
//    char Carrier[4] = {'X','X','X','X' };						//航空公司，用两个大写字母表示
//    char ID[8] = { 'X','X' ,'X' ,'X','X','X' ,'X' ,'X' };								//航班号
//    char FlyDay[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X' };							//开航日期，以星期为周期，星期几与数组下标对应，开航为1，不开航为0
//    char DepartureAirport[8] = { 'X','X','X' ,'X' ,'X' ,'X' ,'X' ,'X' };				//出发机场，三字码，为标明航站楼等，以字符串形式存储，注意结尾的\0
//    char ArrivalAirport[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X' };					//抵达机场，三字码，为标明航站楼等，以字符串形式存储，注意结尾的\0
//    char DepartureTime[4] = { 'X' ,'X' ,'X' ,'X' };					//出发时刻，四字码
//    char ArrivalTime[4] = { 'X' ,'X' ,'X' ,'X' };					//到达时刻，四字码。eg 1230（12时30分）
//    char AircraftType[4] = { 'X','X' ,'X' };					//飞机型号，三字码。eg 787，350
//    char Class[4] = { 'X','X' ,'X' ,'X' };							//舱位，两舱或三舱，注意结尾的\0。
//}FlightID;
//系统年份默认为2020年
//
#ifdef NOTE
#define NOTE
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
    char AircraftType[4] = { 'X','X' ,'X' };					//飞机型号，三字码。eg 787，350
    char Class[4] = { 'X','X' ,'X' ,'X' };							//舱位，两舱或三舱，注意结尾的\0。
}FlightID;

typedef struct Date
{
    int year;
    int month;
    int day;
}Date;

typedef struct FlightTicket //每日机票情况
{
    int ID;//填数组下标(航班号不唯一）
    Date day;
    int FirstClassTicketRemain = 0;
    int BusinessClassTicketRemain = 0;
    int EconomyClassTicketRemain = 0;
    int FirstClassTicketPrice = -100;
    int BusinessClassTicketPrice = -100;
    int EconomyClassTicketPrice = -100;
    int ActuralDepartureTime = 2500;
    int ActuralArrivalTime = 2500;
}FlightTicket;

extern FlightID ID[999];

extern FlightTicket DATA[366][999];

#endif // NOTE

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
    int FirstClassTicketRemain = 0;
    int BusinessClassTicketRemain = 0;
    int EconomyClassTicketRemain = 0;
    int ActuralDepartureTime = 2500;
    int ActuralArrivalTime = 2500;
}FlightTicket; 
#endif // !struct


int WeekDayTransfer(int, int, int);//使用蔡勒公式转换日期与星期
int DateTransfer(int, int, int);//返回日期对应天数
int JudgeAircraftSize(FlightID*, int);//判断飞机是小飞机还是大飞机，小飞机返回1，大飞机返回2
int ImportFlightDatabase(FlightID*);
void PrintFlightTitle();//打印标题栏
void PrintFlight(FlightID*, int, int);
int SearchFlightID(FlightID*, char*, int, int*, int&);//查找航班号，返回查找到航班个数
int SearchFlightDepartureAirport(FlightID*, char*, int, int*, int&);//查找航起飞地，返回查找到航班个数
int SearchFlightArrivalAirport(FlightID*, char*, int, int*, int&);//查找航起飞地，返回查找到航班个数
int PrintSearch(FlightID*, int, int*, int&);//展示查询的结果
int NewFlight(FlightID*, int&);//创建新航线
int SortByDepartureTime(FlightID*, int, int*);//按照起飞时间排序
int SaveFlightDatabase(FlightID*, int);






