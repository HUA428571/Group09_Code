#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct The_users   //typedef ���Զ���ṹ�����
{
    char id[21]; //�˺� 
    char pwd[20]; //���� 
    char name[15];//����Ϊ�ַ��� 
    char sex; //�Ա�Ϊ�����ַ�
    long phone; //�绰����Ϊ������ 
}users;
