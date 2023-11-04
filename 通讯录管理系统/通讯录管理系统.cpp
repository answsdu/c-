//定义部分

#include <iostream>
using namespace std;
#define max 1000

//菜单界面
void showmenu()
{
	cout << "***** ********** *******" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出系统   *****" << endl;
	cout << "***** ********** *******" << endl;
}

//添加联系人结构体
struct person
{
	string name;
	int sex;//1、男 2、女
	int age;
	long long int tel;
	string addr;
};

//添加通讯录结构体


struct addressbooks
{
	person personArr[max];
	int size;//当前存储个数
};

//添加联系人函数
void addperson(addressbooks* p)
{
	//判断是否满了？
	if (p->size == max)
	{
		cout << "通讯录已满，无法添加!" << endl;
		return;
	}
	else
	{
		//添加联系人具体信息

		//姓名
		cout << "请输入联系人姓名：" << endl;
		string name;
		cin >> name;
		p->personArr[p->size].name = name;

		//性别
		cout << "请输入联系人性别：" << endl;
		cout << "1--男\t2--女" << endl;
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
				cout << "输入有误，请重新输入：" << endl;
			}
		}

		//年龄
		cout << "请输入联系人年龄：" << endl;
		int age;
		cin >> age;
		p->personArr[p->size].age = age;

		//联系电话
		cout << "请输入联系人电话：" << endl;
		long long int tel;
		cin >> tel;
		p->personArr[p->size].tel = tel;

		//地址
		cout << "请输入联系人地址：" << endl;
		string address;
		cin >> address;
		p->personArr[p->size].addr = address;

		//更新通讯录人数
		p->size++;

		//反馈结果
		cout << "\n\n添加成功！\n" << endl;

		//清屏
		system("pause");
		system("cls");

	};
}


//显示联系人函数
void showperson(addressbooks* p)
{
	if (p->size == 0)
	{
		cout << "通讯录当前为空！" << endl;
	}

	else
	{
		for (int i = 0; i < p->size; i++)
		{
			cout << "姓名：" << p->personArr[i].name << "\t" 
				 << "性别：" << (p->personArr[i].sex == 1 ? "男" : "女") << "\t" 
				 << "年龄："<< p->personArr[i].age << "\t" 
				 << "电话：" << p->personArr[i].tel << "\t" 
			     << "地址：" << p->personArr[i].addr << endl;
		}
	}
	system("pause");
	system("cls");
}

	//检测联系人是否存在
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
	//删除联系人
	cout << "请输入您要删除的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = existperson(p,name);
	if (ret == -1)
	{
		cout << "查无此人！" << endl;
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
		cout << "删除成功！" << endl;
		system("pause");
		system("cls");
	}
}

//查找联系人并显示信息
void finperson(addressbooks* p)
{
	cout << "请输入您要查找的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = existperson(p, name);
	if (ret == -1)
	{
		cout << "查无此人！" << endl;
	}
	else
	{
		cout << "姓名：" << p->personArr[ret].name << "\t"
			 << "性别：" << (p->personArr[ret].sex == 1 ? "男" : "女") << "\t" 
			 << "年龄："<< p->personArr[ret].age << "\t"
			 << "电话：" << p->personArr[ret].tel << "\t" 
			 << "地址：" << p->personArr[ret].addr << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人信息
void changeperson(addressbooks* p)
{
	cout << "请输入您要修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = existperson(p, name);
	if (ret == -1)
	{
		cout << "查无此人！" << endl;
	}
	else
	{
		//姓名
		cout << "请输入联系人姓名：" << endl;
		string name;
		cin >> name;
		p->personArr[ret].name = name;

		//性别
		cout << "请输入联系人性别：" << endl;
		cout << "1--男\t2--女" << endl;
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
				cout << "输入有误，请重新输入：" << endl;
			}
		}

		//年龄
		cout << "请输入联系人年龄：" << endl;
		int age;
		cin >> age;
		p->personArr[ret].age = age;

		//联系电话
		cout << "请输入联系人电话：" << endl;
		long long int tel;
		cin >> tel;
		p->personArr[ret].tel = tel;

		//地址
		cout << "请输入联系人地址：" << endl;
		string address;
		cin >> address;
		p->personArr[ret].addr = address;


		//反馈结果
		cout << "\n\n修改成功！\n" << endl;
	}
	system("pause");
	system("cls");
}

//清空联系人
void clearperson(addressbooks* p)
{
	p->size = 0;
	cout << "通讯录已清空" << endl;
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
			case 1:/*添加*/
				addperson(&abs);
				break;
			case 2:/*显示*/
				showperson(&abs);
				break;
			case 3:/*删除*/
				deleteperson(&abs);
				break;
			case 4:/*查找*/
				finperson(&abs);
				break;
			case 5:/*修改*/
				changeperson(&abs);
				break;
			case 6:/*清空*/
				clearperson(&abs);
				break;
			case 0:/*退出*/
				cout << "欢迎下次使用" << endl;
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
	