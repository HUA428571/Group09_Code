#include <iostream>
#include<stdio.h>
using namespace std;

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