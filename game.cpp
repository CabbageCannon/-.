#include "game.h"



game::game()
{
	//加载用户资源
    loadFile();
}

int game::showMenu()
{
	cout << "1.登录账号\n2.注册账号\n3.登录管理员账号" << endl;
	cout << "?";
	int choice;
	cin >> choice;
	while ((choice == 1) + (choice == 2) + (choice == 3) < 1)
	{
		cout << "输入有误，请重新输入：" << endl;
		cin >> choice;
	}
	switch (choice)
	{
		//登录账号
	case 1:
		loginUser();
		system("cls");
		return 1;
		//注册账号
	case 2:
		addUser();
		system("cls");
		return 2;
		//登录管理员账号
	case 3:
	{
        manager myManager;
		while(1)
		{
			myManager.menu();
		}
		return 3;
	}
	default:
		break;
	}
}

void game::levelMenu() const
{
	cout << "1.选择关卡\n2.注销账号" << endl;
	cout << "?";
	int choice;
	cin >> choice;
	while ((choice == 1) + (choice == 2) < 1)
	{
		cout << "输入有误，请重新输入：" << endl;
		cin >> choice;
	}
	switch (choice)
	{
		//选择关卡
	case 1:
		chooseLevel();
		//注销账号
	case 2:

	default:
		break;
	}
}

void game::loadFile()
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

void game::loginUser()
{
	string account;
	string password;
	cout << "请输入您的账户：" << endl;
	cin >> account;
	while (account.size() > 10|| users.find(account) == users.end())
	{
		cout << "输入有误，请重新输入：" << endl;
		cin >> account;
	}

	cout << "请输入密码：" << endl;
	cin >> password;
	while (this->users.at(account).password != password)
	{
		cout << "输入有误，请重新输入：" << endl;
		cin >> password;
	}

	cout << "登录成功！" << endl;
}

void game::addUser()
{
	ofstream addUser;
	addUser.open("users.dat", ios::binary | ios::app);

	if (!addUser.is_open())
	{
		cerr << "文件打开失败" << endl;
		exit(EXIT_FAILURE);
	}

	user newUser;

	cout << "请输入1-10位的账号" << endl;
	string account;
	cin >> account;
	while (account.size() > 10)
	{
		cout << "输入过长！请重新输入：" << endl;
		cin >> account;
	}
	while (users.find(account) != users.end())
	{
		cout<<"该账号已存在，请重新输入："<<endl;
		cin >> account;
	}

	strcpy_s(newUser.account, account.c_str());

	cout << "请输入1-10位的密码" << endl;
	string password;
	cin >> password;
	while (password.size() > 10)
	{
		cout << "输入过长！请重新输入：" << endl;
		cin >> password;
	}

	strcpy_s(newUser.password,password.c_str());

	this->users.insert(make_pair(account, newUser));
	//写入到文件中
	addUser.write(reinterpret_cast<const char*>(&newUser), sizeof(user));
	addUser.close();
}

void game::chooseLevel() const
{
	cout << "现有1-20关，请选择你要玩的关卡：" << endl;
	int choice;
	cin >> choice;
	while (choice < 1 || choice>20)
	{
		cout << "输入有误，请重新输入：" << endl;
		cin >> choice;
	}
	table t(choice);
	t.showTable();
	while (true)
	{
		t.addSymbol();
		system("cls");
		t.showTable();
		if (t.isWin())
		{
			cout << "胜利了" << endl;
			break;
		}
	}
}
