#include"�û���Ϣ��.h"
void registers();
void Input_login();
void reback();
void main()
{
	/*���������û��˺�������ļ�*/
	void Create_File();
	{
		FILE* fp;
		if ((fp = fopen("users.dat", "rb")) == NULL)                 /*������ļ�������*/
		{
			if ((fp = fopen("users.dat", "wb+")) == NULL)
			{
				printf("�޷������ļ���\n");
				exit(0);

			}
		}
	}
	printf("ѡ����:\n1:ע���˺�\t2:��½�˺�\n");
	int Choose1;
	int Choose2;
	scanf("%d", &Choose1);
	if (Choose1 == 1)
	{
		registers();
		printf("�Ƿ��¼��(1/0)\n");
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
/*ע���˺�*/
void registers()  //���ṹ��Ĵ�С��һ��д����߶���1���ṹ���С
{
	users a, b;//�ṹ�� The_users ����������
	FILE* fp;
	char temp[20];
	int count = 0;
	printf("��ӭ����ע����棡\n");
	Sleep(1000);
	fp = fopen("users.dat", "rb");

	fread(&b, sizeof(struct The_users), 1, fp); //����һ���ṹ���ַ��� ��b
	printf("�������˺�\n");
	scanf("%s", &a.id);
	while (1)
	{
		if (strcmp(a.id, b.id)) /*������������*/
		{
			if (!feof(fp))    /*���δ���ļ�β*/


			{
				fread(&b, sizeof(struct The_users), 1, fp);
			}
			else
				break;
		}
		else

		{
			printf("���û����Ѵ��ڣ�������ע�ᣡ\n");
			Sleep(1000);
			fclose(fp);
			return;
		}
	}
	printf("������������\n");
	scanf("%s", &a.name);
	printf("�������Ա�(f(Ů)/m(��))��\n");
	scanf(" %c", &a.sex);
	do {
		if (a.sex != 'f' && a.sex != 'm') {
			printf("�Ա�����������������룡\n");
			scanf("%c", &a.sex);
		}
	} while (a.sex != 'f' && a.sex != 'm');
	getchar();
	printf("������绰���룺\n");
	scanf("%ld", &a.phone);
	printf("����������\n");
	scanf(" %s", &a.pwd);
	printf("��ȷ������\n");
	scanf(" %s", &temp);
	int flag = 0;
	do {

		if (!strcmp(a.pwd, temp))
		{
			fp = fopen("users.dat", "ab");
			fwrite(&a, sizeof(struct The_users), 1, fp);
			printf("�˺�ע��ɹ������¼��\n");
			flag = 1;
			Sleep(500);
			fclose(fp);
		}
		else {
			printf("�������벻ƥ�䣡���������룡\n");
			scanf("%s", &a.pwd);
			printf("��ȷ������\n");
			scanf("%s", &temp);
		}
	} while (flag == 0);
}
/*��¼ϵͳ*/
void  Input_login()
{
	users a, b;//����ṹ��The_users����

	FILE* fp;
	printf("��ӭ������¼���棡\n");
	Sleep(1000);
	fp = fopen("users.dat", "r");

	fread(&b, sizeof(struct The_users), 1, fp); //����һ���ṹ���ַ��� д��b
	printf("�������˺�\n");
	scanf("%s", &a.id);

	while (1)
	{
		if (strcmp(a.id, b.id) == 0)         //����д��û���
		{
			break;
		}

		else
		{
			if (!feof(fp))  //����ļ�û�ж���                            

			{
				fread(&b, sizeof(struct The_users), 1, fp);
			}

			else
			{
				printf("���������˺�\n");
				scanf("%s", &a.id);
				if (strcmp(a.id, b.id) == 0)         //����д��û���
				{
					break;
				}
				else
				{
					if (!feof(fp))  //����ļ�û�ж���                            

					{
						fread(&b, sizeof(struct The_users), 1, fp);
					}
					else
						printf("�����������Σ����Ƴ�������������");
					return;
				}

			}
		}
	}
	printf("����������\n");
	scanf("%s", &a.pwd);
	do {

		if (strcmp(a.pwd, b.pwd) == 0)            /*�������ƥ��*/

		{
			fclose(fp);
			printf("��¼�ɹ�,��ӭʹ��!");
			Sleep(500);
			return;
		}
		else
		{
			printf("���벻��ȷ!��������������\n");
			scanf("%s", &a.pwd);
		}
	} while (strcmp(a.pwd, b.pwd) == 0);

}
