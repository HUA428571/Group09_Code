//B19030334����Զ[�����ÿ͵Ĵ󲿷ֹ���]:��Ʊ����Ʊ����ǩ��ѡ�����漰�������
//��Ʊ��ѯ�������ѯ������[����ͻ�]; �ÿͶ�Ʊ����
#include<iostream>
#include <windows.h>
#include"function.h"
using namespace std;
int j = 0;
#ifndef StructDefine
#define StructDefine
typedef struct FlightID //���ڱ�ʾ����ţ������ֻ�����������Ϣ��
{
	char Carrier[4] = { 'X','X','X','X' };						//���չ�˾����������д��ĸ��ʾ
	char ID[8] = { 'X','X' ,'X' ,'X','X','X' ,'X' ,'X' };								//�����
	char FlyDay[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X' };							//�������ڣ�������Ϊ���ڣ����ڼ��������±��Ӧ������Ϊ1��������Ϊ0
	char DepartureAirport[8] = { 'X','X','X' ,'X' ,'X' ,'X' ,'X' ,'X' };				//���������������룬Ϊ������վ¥�ȣ����ַ�����ʽ�洢��ע���β��\0
	char ArrivalAirport[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X' };					//�ִ�����������룬Ϊ������վ¥�ȣ����ַ�����ʽ�洢��ע���β��\0
	int DepartureTime = 2500;					//����ʱ�̣�������
	int ArrivalTime = 2500;					//����ʱ�̣������롣eg 1230��12ʱ30�֣�
	int TravelTimeHour = 0;//����ʱ��(ʱ)
	int TravelTimeMinute = 0;//����ʱ��(��)
	int Price = 0;
	char AircraftType[4] = { 'X','X' ,'X' };					//�ɻ��ͺţ������롣eg 787��350
	char Class[4] = { 'X','X' ,'X' ,'X' };							//��λ�����ջ����գ�ע���β��\0��
}FlightID;

typedef struct FlightTicket //ÿ�ջ�Ʊ���
{
	int Seat[50][10] = { 0 };
	int ActuralDepartureTime = 2500;
	int ActuralArrivalTime = 2500;
	int FirstClassTicketRemain = 0;
	int BusinessClassTicketRemain = 0;
	int EconomyClassTicketRemain = 0;
}FlightTicket;
#endif // !struct
static FlightID ID[999];//Ĭ�����洢999������ ȫ�ֱ������к������ɷ���
static FlightTicket DATA[366][999];//�洢һ��ĺ�������
void PreBooking();
void head();
int DateTransfer(int year, int month, int day);//�仯Ϊ����
int WeekDayTransfer(int year, int month, int day);//�仯Ϊ������
int JudgeAircraftSize(FlightID* ID, int n);//�жϻ���
int order();//ϵͳѡ�����
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