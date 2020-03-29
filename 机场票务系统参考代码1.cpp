//#include <iostream>
//#include<cstring>		//包含字符串函数处理头文件
//#include<process.h>		//包含access函数的头文件
//#include<io.h>
//#include<cstdlib>
//#include<windows.h>
//#include<conio.h>
//#include<fstream>
//#define N 9999			//定义最多的航班数
//#define PRINT s[i].num<<"\t\t"<<s[i].start<<"\t\t"<<s[i].over<<"\t\t星期"<<s[i].time<<"\t\t"<<s[i].count<<endl   //宏定义输出格式
//using namespace std;
//
//
//struct air         	//定义结构体数组
//{
//	int num;				//定义航班号
//	char start[20];		    //航班起始站
//	char over[20];			//终点站
//	char time[10];			//飞行时间
//	int count;				//机票数量
//}s[N];
//
//int i, a, m = 0;				//定义全局变量
//char ii[10];
//
//void add();		//函数声明增加航班信息函数
//void print(); 		//显示航班信息
//bool search();		//查找航班信息
//void dingpiao();	//订票业务
//void tuipiao();		//退票
//void Read();		//读取文件
//void save();		//保存文件
//void output();		//输出格式
//void paixu();		//航班排序
//void chushihua();	//系统初始化
//void build();		//建立数据文件
//void paixu1();		//按航班号从小到大排序
//void paixu2();		//从大到小
//int head();		//进入订票系统
//
//int main()		//主函数
//{
//	int j;
//	system("color b0");
//	chushihua();		//系统初始化判断是否存在原始数据文件
//	system("cls");
//	head();	//打印出系统主界面
//	system("cls");
//	do
//	{
//		cout << "================================================================================ ";
//		cout << "\n\t\t\t\t1.增加航班信息\n\t\t"
//			"\t\t2.浏览航班信息\n\t\t"
//			"\t\t3.查找航班信息(按航班号)\n\t\t"
//			"\t\t4.航班排序(按航班号)\n\t\t"
//			"\t\t5.订票业务\n\t\t"
//			"\t\t6.退票业务\n\t\t"
//			"\t\t0.退出\n";
//		cout << "================================================================================ ";
//		cout << "\n请在0-6中选择以回车键结束： ";
//		cin >> j;
//		switch (j)
//		{
//		case 1: add();	system("cls");		//调用增加航班函数
//			break;
//		case 2:print();	system("cls");//调用显示模块
//			break;
//		case 3:search(); system("cls");	//调用查找模块
//			break;
//		case 4:paixu(); system("cls");	//调用排序函数
//			break;
//		case 5:dingpiao(); system("cls");	//调用订票模块
//			break;
//		case 6:tuipiao(); system("cls");	//调用退票模块
//			break;
//		case 0:				//退出系统
//			save(); system("cls");
//			cout << "\n\n\n\t\t\t\t\n\n\t谢谢使用，再见！ ";
//			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
//			break;
//		}
//	} while (j != 0);		//判断是否调用其他函数
//
//}
//
//
//
//void chushihua()		//定义系统初始化函数
//{
//	if (_access("hangban.dat", 0))
//	{
//		build();
//	}
//	else
//		Read();
//}
//
//void build()		//定义建立数据文件函数
//{
//	FILE* fp;		//定义文件指针
//	if ((fp = fopen("hangban.dat", "wb")) == NULL)		//打开文件并判定是否出错
//	{
//		cout << "创建文件失败! ";		//打印出错提示
//		getchar();
//		return;
//	}
//	cout << "请依次输入航班信息(以回车键结束):\n";      //打印提示信息
//	cout << "-------------------------------------------------------------------------- \n";
//	for (i = 0; i < N; i++)
//	{
//		cout << "请输入航班号: ";
//		cin >> s[i].num;		//输入航班号
//		cout << "请输入起始站: ";
//		cin >> s[i].start;		//输入起始站
//		cout << "请输入终点站: ";
//		cin >> s[i].over;		//输入终点站
//		cout << "请输入时间(星期几 : ";
//		cin >> s[i].time;		//输入时间
//		cout << "请输入机票数: ";
//		cin >> s[i].count;	//输入机票数
//		fwrite(&s[i], sizeof(struct air), 1, fp);
//		m++;
//		cout << "添加完毕,是否继续添加?请键入y或n以回车键结束:";
//		cin >> ii;
//		if (strcmp(ii, "y") != 0)			//判断是否继续添加航班信息
//		{
//			fclose(fp);			//关闭文件
//			return;
//		}
//	}
//}
//
//void Read()	//定义读取文件函数
//{
//	FILE* fp;
//	if ((fp = fopen("hangban.dat", "r")) == NULL)
//	{
//		cout << "创建文件失败! ";
//		getchar();
//		return;
//	}
//	i = 0;
//	while (!feof(fp))
//	{
//		fread(&s[i], sizeof(struct air), 1, fp);		//逐块读取数据
//		i++;
//		m++;		//计算存在航班数
//	}
//	m--;
//	fclose(fp);
//	cout << "请稍候，正在初始化";
//	for (a = 0; a < 3; a++)
//	{
//		cout << ".";
//		Sleep(200);
//	}
//	cout << "\n";
//}
//
//void save() 		//定义保存函数
//{
//	FILE* fp;
//	if ((fp = fopen("hangban.dat", "wb")) == NULL)
//	{
//		cout << "创建文件失败! ";
//		getchar();
//		return;
//	}
//	for (i = 0; i < m; i++)			//逐块保存数据
//		fwrite(&s[i], sizeof(struct air), 1, fp);
//	fclose(fp);
//	cout << "正在保存数据并退出";
//	for (a = 0; a < 3; a++)
//	{
//		cout << ".";
//		Sleep(200);
//	}
//	cout << "\n";
//	cout << "\n";
//
//}
//
//void add()		//定义增加航班信息函数
//{
//	do {
//		cout << "请依次输入您要增加的航班信息(以回车键结束):  \n";      //打印提示信息
//		cout << "-------------------------------------------------------------------------- \n";
//		cout << "请输入航班号: ";
//		cin >> s[m].num;		//读取航班号
//		cout << "请输入起始站: ";
//		cin >> s[m].start;		//读取起始站
//		cout << "请输入终点站: ";
//		cin >> s[m].over;		//读取终点站
//		cout << "请输入时间(星期几): ";
//		cin >> s[m].time;		//读取时间
//		cout << "请输入机票数: ";
//		cin >> s[m].count;	//读取机票数
//		m++;
//		cout << "添加完毕,是否继续添加?请键入y或n以回车键结束:";
//		cin >> ii;
//	} while (!strcmp(ii, "y"));		//判断是否继续添加
//	cout << "正在保存，请稍候";
//	for (a = 0; a < 5; a++)
//	{
//		cout << ".";
//		Sleep(600);
//	}
//	cout << "\n";
//}
//
//void output()		//定义输出格式函数
//{
//
//	cout << "航班号\t\t起始站\t\t终点站\t\t时间\t\t机票数\n";		//信息标题
//	for (i = 0; i < m; i++)
//		cout << PRINT;//打印出信息
//
//}
//
//void print()		//定义显示航班信息函数
//{
//	cout << "正在加载,请稍候";
//	for (a = 0; a < 5; a++)
//	{
//		cout << ".";
//		Sleep(400);
//	}
//	cout << "\n";
//	system("cls");
//	cout << "\n目前我们有如下航班：\n\n";
//	output();			//调用输出格式函数
//	cout << "\n请按回车键返回上层菜单 ";
//	getchar();
//	getchar();
//
//}
//
//bool search()		//定义查询函数
//{
//	int n;
//	do
//	{
//		cout << "\n请输入航班号： ";
//		cin >> n;		//输入查询的航班号
//		cout << "正在查询";
//		for (a = 0; a < 5; a++)
//		{
//			cout << ".";
//			Sleep(400);
//		}
//		cout << "\n";
//		for (i = 0; i < m; i++)
//		{
//			if (s[i].num == n)	//按航班号判定输出条件
//			{
//				cout << "\n您所查找的航班信息为:\n ";
//				cout << "航班号\t\t起始站\t\t终点站\t\t时间\t\t机票数 \n\n";
//				cout << PRINT;		//显示信息
//				cout << "\n查询完毕，按回车键继续";
//				getchar();
//				getchar();
//				return true;
//			}
//		}
//		cout << "\n对不起，没有您需要的信息！\n ";
//		cout << "是否重新查找?请键入y或n以回车键结束 ";
//		cin >> ii;
//	} while (!strcmp(ii, "y"));//判定是否重新查找
//
//}
//
//void dingpiao()		//定义订票业务函数
//{
//	int n, x;
//	char a[10] = "y";
//	do
//	{
//
//		if (!search())
//		{
//			cout << "对不起!没有找到您所需要的航班,所以不能订票。\n";	//未查找到所需航班
//			cout << "\n请按回车键返回上层菜单 ";
//			getchar();
//			getchar();
//			strcpy(ii, "n");
//			break;
//		}
//		do
//		{
//			cout << "请输入您要订的机票数（以回车键结束）： ";
//			cin >> n;		//输入所订机票数
//			cout << "请稍候,正在订票";
//			for (x = 0; x < 3; x++)
//			{
//				cout << ".";
//				Sleep(600);
//			}
//			cout << "\n";
//			if (n <= 0)			//判定机票数是否出错
//			{
//				cout << "输入错误！至少需订1张机票。\n";
//			}
//			else if (s[i].count == 0)//判定机票是否售完
//			{
//				cout << "对不起，你所选择的航班的机票已售完!\n";
//				break;
//			}
//			else if (s[i].count != 0 && s[i].count >= n)	//判定机票数是否大于等于订票数
//			{
//				s[i].count = s[i].count - n;
//				cout << "订票成功! ";
//				break;
//			}
//			else if (s[i].count < n)//判定机票数是否小于订票数
//			{
//				cout << "对不起，你所选择的航班只剩" << s[i].count << "张机票\n";
//				cout << "是否需要重新输入机票数?\n请输入y或n以回车键结束: ";//判定是否重新输入订票数
//				cin >> a;
//				cout << "请稍候,正在订票";
//				for (x = 0; x < 3; x++)
//				{
//					cout << ".";
//					Sleep(600);
//				}
//				cout << "\n";
//			}
//		} while (!strcmp(a, "y"));
//		cout << "是否需要订其他航班的机票?\n请输入y或n以回车键结束: ";
//		cin >> a;
//	} while (!strcmp(a, "y"));		//判定是否继续订票
//}
//
//void tuipiao()	//定义退票函数
//{
//	int n, x;
//	char a[10];
//	do
//	{
//
//		if (!search())
//		{
//			cout << "对不起!没有找到您所需要的航班,所以不能退票。\n";
//			cout << "\n请按回车键返回上层菜单 ";
//			getchar();
//			getchar();
//			strcpy(ii, "n");
//			break;
//		}
//		cout << "请输入您要退的机票数目： ";
//		cin >> n;			//输入所退票数
//		cout << "请稍候,正在退票";
//		for (x = 0; x < 3; x++)
//		{
//			cout << ".";
//			Sleep(600);
//		}
//		cout << "\n";
//		if (n <= 0)			//判定票数是否有效
//			cout << "输入错误！至少需退1张机票。 ";
//		else
//		{
//			s[i].count = s[i].count + n;
//			cout << "退票成功! ";
//		}
//		cout << "是否继续？ 请键入y或n以回车键结束: ";		//判定是否继续退票
//		cin >> a;
//	} while (!strcmp(a, "y"));		//判定并跳出循环
//
//
//}
//
//void paixu()		//定义排序函数
//{
//	int n;
//
//	cout << "\n******************************************************************************** ";
//	cout << "\n\t\t1.按航班号从小到大排序\t\t\n"
//		"\t\t2.按航班号从大到小排序\t\t\n";
//	cout << "******************************************************************************** ";
//	cout << "请在1-2中选择以回车键结束： ";
//	cin >> n;		//输入排序方式
//	switch (n)
//	{
//	case 1:paixu1();//调用从小到大排序函数
//		break;
//	case 2:paixu2();//调用从大到小排序函数
//		break;
//	}
//	cout << "排序后的航班信息为:\n";
//	output();			//显示排序后航班信息
//	cout << "\n请按回车键返回上层菜单 ";
//	getchar();
//	getchar();
//	/*for(a=0;a<5;a++)
//			{
//				cout<<"." ;
//				Sleep(400);
//			}
//			cout<<"\n" ;*/
//}
//
//void paixu1()		//定义从小到大排序函数
//{
//	int k, j;
//	struct air t;
//	for (i = 0; i < m; i++)	//选择排序
//	{
//		k = i;
//		for (j = i + 1; j < m; j++)
//			if (s[k].num > s[j].num)
//				k = j;
//		if (i != k)
//		{
//			t = s[k];
//			s[k] = s[i];
//			s[i] = t;
//		}
//	}
//	cout << "正在排序，请稍后";
//	for (a = 0; a < 5; a++)
//	{
//		cout << ".";
//		Sleep(400);
//	}
//	cout << "\n";
//
//}
//
//void paixu2()		//定义从大到小排序函数
//{
//	int k, j;
//	struct air t;
//	for (i = 0; i < m; i++)
//	{
//		k = i;
//		for (j = i + 1; j < m; j++)
//			if (s[k].num < s[j].num)
//				k = j;
//		if (i != k)
//		{
//			t = s[k];
//			s[k] = s[i];
//			s[i] = t;
//		}
//	}
//	cout << "正在排序，请稍后";
//	for (a = 0; a < 5; a++)
//	{
//		cout << ".";
//		Sleep(400);
//	}
//	cout << "\n";
//}
//
//int head()		 	//进入订票系统
//{
//	cout << "=================================================================\n";
//	cout << "*                                                               *\n";
//	cout << "*                       欢迎使用机票订票管理系统                *\n";
//	cout << "*                                                               *\n";
//	cout << "*                                                               *\n";
//	cout << "=================================================================\n";
//	cout << "请按回车键进入界面";
//	getchar();
//	cout << "正在进入系统选项";
//	for (a = 0; a < 3; a++)
//	{
//		cout << ".";
//		Sleep(600);
//	}
//	cout << "\n";
//	return 0;
//}
