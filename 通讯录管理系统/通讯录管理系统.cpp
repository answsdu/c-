//���岿��

#include <iostream>
using namespace std;
#define max 1000

//�˵�����
void showmenu()
{
	cout << "***** ********** *******" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ϵͳ   *****" << endl;
	cout << "***** ********** *******" << endl;
}

//�����ϵ�˽ṹ��
struct person
{
	string name;
	int sex;//1���� 2��Ů
	int age;
	long long int tel;
	string addr;
};

//���ͨѶ¼�ṹ��


struct addressbooks
{
	person personArr[max];
	int size;//��ǰ�洢����
};

//�����ϵ�˺���
void addperson(addressbooks* p)
{
	//�ж��Ƿ����ˣ�
	if (p->size == max)
	{
		cout << "ͨѶ¼�������޷����!" << endl;
		return;
	}
	else
	{
		//�����ϵ�˾�����Ϣ

		//����
		cout << "��������ϵ��������" << endl;
		string name;
		cin >> name;
		p->personArr[p->size].name = name;

		//�Ա�
		cout << "��������ϵ���Ա�" << endl;
		cout << "1--��\t2--Ů" << endl;
		int sex = 0;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				p->personArr[p->size].sex = sex;
				break;
			}
			else
			{
				cout << "�����������������룺" << endl;
			}
		}

		//����
		cout << "��������ϵ�����䣺" << endl;
		int age;
		cin >> age;
		p->personArr[p->size].age = age;

		//��ϵ�绰
		cout << "��������ϵ�˵绰��" << endl;
		long long int tel;
		cin >> tel;
		p->personArr[p->size].tel = tel;

		//��ַ
		cout << "��������ϵ�˵�ַ��" << endl;
		string address;
		cin >> address;
		p->personArr[p->size].addr = address;

		//����ͨѶ¼����
		p->size++;

		//�������
		cout << "\n\n��ӳɹ���\n" << endl;

		//����
		system("pause");
		system("cls");

	};
}


//��ʾ��ϵ�˺���
void showperson(addressbooks* p)
{
	if (p->size == 0)
	{
		cout << "ͨѶ¼��ǰΪ�գ�" << endl;
	}

	else
	{
		for (int i = 0; i < p->size; i++)
		{
			cout << "������" << p->personArr[i].name << "\t" 
				 << "�Ա�" << (p->personArr[i].sex == 1 ? "��" : "Ů") << "\t" 
				 << "���䣺"<< p->personArr[i].age << "\t" 
				 << "�绰��" << p->personArr[i].tel << "\t" 
			     << "��ַ��" << p->personArr[i].addr << endl;
		}
	}
	system("pause");
	system("cls");
}

	//�����ϵ���Ƿ����
int existperson(addressbooks* p,string name)
{
	for (int i = 0; i < p->size; i++)
	{
		if (p->personArr[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

void deleteperson(addressbooks * p)
{
	//ɾ����ϵ��
	cout << "��������Ҫɾ������ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = existperson(p,name);
	if (ret == -1)
	{
		cout << "���޴��ˣ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = ret; i < p->size; i++)
		{
			p->personArr[i] = p->personArr[i + 1];
		}
		p->size--;
		cout << "ɾ���ɹ���" << endl;
		system("pause");
		system("cls");
	}
}

//������ϵ�˲���ʾ��Ϣ
void finperson(addressbooks* p)
{
	cout << "��������Ҫ���ҵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = existperson(p, name);
	if (ret == -1)
	{
		cout << "���޴��ˣ�" << endl;
	}
	else
	{
		cout << "������" << p->personArr[ret].name << "\t"
			 << "�Ա�" << (p->personArr[ret].sex == 1 ? "��" : "Ů") << "\t" 
			 << "���䣺"<< p->personArr[ret].age << "\t"
			 << "�绰��" << p->personArr[ret].tel << "\t" 
			 << "��ַ��" << p->personArr[ret].addr << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ����Ϣ
void changeperson(addressbooks* p)
{
	cout << "��������Ҫ�޸ĵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = existperson(p, name);
	if (ret == -1)
	{
		cout << "���޴��ˣ�" << endl;
	}
	else
	{
		//����
		cout << "��������ϵ��������" << endl;
		string name;
		cin >> name;
		p->personArr[ret].name = name;

		//�Ա�
		cout << "��������ϵ���Ա�" << endl;
		cout << "1--��\t2--Ů" << endl;
		int sex = 0;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				p->personArr[ret].sex = sex;
				break;
			}
			else
			{
				cout << "�����������������룺" << endl;
			}
		}

		//����
		cout << "��������ϵ�����䣺" << endl;
		int age;
		cin >> age;
		p->personArr[ret].age = age;

		//��ϵ�绰
		cout << "��������ϵ�˵绰��" << endl;
		long long int tel;
		cin >> tel;
		p->personArr[ret].tel = tel;

		//��ַ
		cout << "��������ϵ�˵�ַ��" << endl;
		string address;
		cin >> address;
		p->personArr[ret].addr = address;


		//�������
		cout << "\n\n�޸ĳɹ���\n" << endl;
	}
	system("pause");
	system("cls");
}

//�����ϵ��
void clearperson(addressbooks* p)
{
	p->size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

	int main()
	{
		int select = 0;

		addressbooks abs;
		abs.size = 0;

		while (1)
		{
			showmenu();

			cin >> select;
			switch (select)
			{
			case 1:/*���*/
				addperson(&abs);
				break;
			case 2:/*��ʾ*/
				showperson(&abs);
				break;
			case 3:/*ɾ��*/
				deleteperson(&abs);
				break;
			case 4:/*����*/
				finperson(&abs);
				break;
			case 5:/*�޸�*/
				changeperson(&abs);
				break;
			case 6:/*���*/
				clearperson(&abs);
				break;
			case 0:/*�˳�*/
				cout << "��ӭ�´�ʹ��" << endl;
				system("pause");
				return 0;
				break;
			default:
				break;
			}
		}

		system("pause");
		return 0;
	}
	