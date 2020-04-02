#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct The_users   //typedef 可以定义结构体别名
{
    char id[21]; //账号 
    char pwd[20]; //密码 
    char name[15];//姓名为字符串 
    char sex; //性别为单个字符
    long phone; //电话号码为长整型 
}users;
