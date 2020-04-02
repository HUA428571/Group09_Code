#include"用户信息表.h"
void registers();
void Input_login();
void reback();
void main()
{
	/*创建储存用户账号密码的文件*/
	void Create_File();
	{
		FILE* fp;
		if ((fp = fopen("users.dat", "rb")) == NULL)                 /*如果此文件不存在*/
		{
			if ((fp = fopen("users.dat", "wb+")) == NULL)
			{
				printf("无法建立文件！\n");
				exit(0);

			}
		}
	}
	printf("选择功能:\n1:注册账号\t2:登陆账号\n");
	int Choose1;
	int Choose2;
	scanf("%d", &Choose1);
	if (Choose1 == 1)
	{
		registers();
		printf("是否登录？(1/0)\n");
		scanf("%d", &Choose2);
		if (Choose2 == 1)
			Input_login();
		else
			return;
	}
	if (Choose1==2)
		Input_login();
	return;
}
/*注册账号*/
void registers()  //按结构体的大小，一次写入或者读入1个结构体大小
{
	users a, b;//结构体 The_users 重命名定义
	FILE* fp;
	char temp[20];
	int count = 0;
	printf("欢迎来到注册界面！\n");
	Sleep(1000);
	fp = fopen("users.dat", "rb");

	fread(&b, sizeof(struct The_users), 1, fp); //读入一个结构体字符块 到b
	printf("请输入账号\n");
	scanf("%s", &a.id);
	while (1)
	{
		if (strcmp(a.id, b.id)) /*如果两串不相等*/
		{
			if (!feof(fp))    /*如果未到文件尾*/


			{
				fread(&b, sizeof(struct The_users), 1, fp);
			}
			else
				break;
		}
		else

		{
			printf("此用户名已存在！请重新注册！\n");
			Sleep(1000);
			fclose(fp);
			return;
		}
	}
	printf("请输入姓名：\n");
	scanf("%s", &a.name);
	printf("请输入性别(f(女)/m(男))：\n");
	scanf(" %c", &a.sex);
	do {
		if (a.sex != 'f' && a.sex != 'm') {
			printf("性别输入错误！请重新输入！\n");
			scanf("%c", &a.sex);
		}
	} while (a.sex != 'f' && a.sex != 'm');
	getchar();
	printf("请输入电话号码：\n");
	scanf("%ld", &a.phone);
	printf("请输入密码\n");
	scanf(" %s", &a.pwd);
	printf("请确认密码\n");
	scanf(" %s", &temp);
	int flag = 0;
	do {

		if (!strcmp(a.pwd, temp))
		{
			fp = fopen("users.dat", "ab");
			fwrite(&a, sizeof(struct The_users), 1, fp);
			printf("账号注册成功，请登录！\n");
			flag = 1;
			Sleep(500);
			fclose(fp);
		}
		else {
			printf("两次密码不匹配！请重新输入！\n");
			scanf("%s", &a.pwd);
			printf("请确认密码\n");
			scanf("%s", &temp);
		}
	} while (flag == 0);
}
/*登录系统*/
void  Input_login()
{
	users a, b;//定义结构体The_users别名

	FILE* fp;
	printf("欢迎来到登录界面！\n");
	Sleep(1000);
	fp = fopen("users.dat", "r");

	fread(&b, sizeof(struct The_users), 1, fp); //读入一个结构体字符块 写入b
	printf("请输入账号\n");
	scanf("%s", &a.id);

	while (1)
	{
		if (strcmp(a.id, b.id) == 0)         //如果有此用户名
		{
			break;
		}

		else
		{
			if (!feof(fp))  //如果文件没有读完                            

			{
				fread(&b, sizeof(struct The_users), 1, fp);
			}

			else
			{
				printf("重新输入账号\n");
				scanf("%s", &a.id);
				if (strcmp(a.id, b.id) == 0)         //如果有此用户名
				{
					break;
				}
				else
				{
					if (!feof(fp))  //如果文件没有读完                            

					{
						fread(&b, sizeof(struct The_users), 1, fp);
					}
					else
						printf("错误输入两次，请推出程序再启动。");
					return;
				}

			}
		}
	}
	printf("请输入密码\n");
	scanf("%s", &a.pwd);
	do {

		if (strcmp(a.pwd, b.pwd) == 0)            /*如果密码匹配*/

		{
			fclose(fp);
			printf("登录成功,欢迎使用!");
			Sleep(500);
			return;
		}
		else
		{
			printf("密码不正确!请重新输入密码\n");
			scanf("%s", &a.pwd);
		}
	} while (strcmp(a.pwd, b.pwd) == 0);

}
