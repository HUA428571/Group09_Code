#include <iostream>
#include<stdio.h>
using namespace std;

typedef struct FlightID //���ڱ�ʾ����ţ������ֻ�������������Ϣ��
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
	char AircraftType[4] = { 'X','X' ,'X' };					//�ɻ��ͺţ������롣eg 787��350
	char Class[4] = { 'X','X' ,'X' ,'X' };							//��λ�����ջ����գ�ע���β��\0��
}FlightID;

typedef struct Date
{
	int year;
	int month;
	int day;
}Date;

typedef struct FlightTicket //ÿ�ջ�Ʊ���
{
	int ID;//�������±�(����Ų�Ψһ��
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