#include"notes.h"
#include<iostream>
using namespace std;
int main()
{
	//所有的XXcount都是个数，不是对应下标！下标要减一
	static FlightID ID[999];//默认最多存储999个航线 全局变量所有函数均可访问
	static FlightTicket DATA[366][999];//存储一年的航班数
	int FlightID_Count = 0;//存储当前航班号个数
	int SearchReasult[999];//用于存储搜索结果
	int SearchCount = 0;//存储搜索结果数
	int SortReasult[999];//用于存储排序后的顺序，这样就不会更改原有的结构体数组顺序，不影响下标访问。

	//以下都是测试用的临时代码

	FlightID_Count = ImportFlightDatabase(ID);
	PrintFlightTitle();
	for (int i = 0; i < 10; i++)
	{
		PrintFlight(ID, i, i + 1);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t" << JudgeAircraftSize(ID, i) << endl;
	}

	//cout << "请输入你要查询的航班号" << endl;
	//char search[10];
	//int result;
	//cin >> search;
	//SearchFlightID(ID, search, FlightID_Count, SearchReasult, SearchCount);//查找航班号，返回查找到航班个数	
	//result = PrintSearch(ID, FlightID_Count, SearchReasult, SearchCount);
	//PrintFlight(ID, result, 1);
	//NewFlight(ID, FlightID_Count);
	//NewFlight(ID, FlightID_Count);
	//NewFlight(ID, FlightID_Count);
	//PrintFlightTitle();
	//for (int i = FlightID_Count-1, i2 = 1; i > 200; i--)
	//{
	//	PrintFlight(ID, i, i2);

	//	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t" << JudgeAircraftSize(ID, i) << endl;
	//	i2++;
	//}
	//SortByDepartureTime(ID, FlightID_Count, SortReasult);
	//for (int i = 0; i < FlightID_Count; i++)
	//{
	//	cout<<SortReasult[i]<<"\t";
	//}
	//PrintFlightTitle();
	//for (int i = 0; i < 100; i++)
	//{
	//	PrintFlight(ID, SortReasult[i], i + 1);
	//}
	SaveFlightDatabase(ID,FlightID_Count);



	return 0;
}