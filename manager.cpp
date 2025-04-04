#include "manager.h"

manager::manager()
{
	if (isFileEmpty())
		setPassword();
	else
		login();
	loadUser();
	menu();
}

void manager::showUser() const
{
	cout <<setw(10)<< "用户账号"<<setw(10)<< "账号密码" << endl;
	for (auto it = this->users.begin(); it != users.end(); it++)
	{
		cout << setw(10) << (*it).first << setw(10) << (*it).second.password<< endl;
	}
}

bool manager::isFileEmpty() const
{
	std::ifstream inFile("manager.dat");
	if (!inFile) {
		cerr << "无法打开文件"<<endl;
		return true;
	}

	char ch;
	bool isEmpty = !inFile.get(ch); // 如果读取失败，文件为空
	inFile.close();
	return isEmpty;
}

void manager::setPassword()
{
	string passWord;
	cout << "请输入1-10位的密码:" << endl;
	cin >> passWord;
	while (passWord.size() > 10 || passWord.size()< 1)
	{
		cout << "输入有误！请重新输入：" << endl;
		cin >> passWord;
	}
	ofstream ofs("manager.dat",ios::out|ios::binary);
	if (!ofs.is_open())
	{
		cerr << "文件打开失败！" << endl;
		return;
	}
	ofs << passWord;
	cout << "密码设置成功！" << endl;
}

void manager::login()
{
	ifstream ifs("manager.dat", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	string rightPassWord;
	ifs >> rightPassWord;
	ifs.close();
	string passWord;
	cout << "请输入密码：" << endl;
	cin >> passWord;
	while (passWord != rightPassWord)
	{
		cout << "输入有误！请重新输入：" << endl;
		cin >> passWord;
	}
	cout << "登录成功！" << endl;
	system("pause");
	system("cls");
}

void manager::menu()
{
	cout << "1.查看用户信息：" << endl;
	cout << "2.修改密码" << endl;
	int choice = 0;
	cout << "?";
	while ((choice == 1) + (choice == 2) == 0)
	{
		cout << "输入有误！请重新输入：" << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
		this->showUser();
		break;
	case 2:
		this->setPassword();
		break;
	default:
		break;
	}
	system("pause");
	system("cls");
}

void manager::loadUser()
{
	ifstream loadFile;
	loadFile.open("users.dat", ios::out | ios::binary);

	if (!loadFile.is_open())
	{
		cerr << "文件打开失败" << endl;
		exit(EXIT_FAILURE);
	}

	user recordUser;
	memset(&recordUser, 0, sizeof(user));
	while (loadFile.read(reinterpret_cast<char*>(&recordUser), sizeof(user)))
	{
		string account(recordUser.account);
		this->users.insert(make_pair(account, recordUser));
	}
	loadFile.close();
}
