#include "game.h"



game::game()
{
	//�����û���Դ
    loadFile();
}

int game::showMenu()
{
	cout << "1.��¼�˺�\n2.ע���˺�\n3.��¼����Ա�˺�" << endl;
	cout << "?";
	int choice;
	cin >> choice;
	while ((choice == 1) + (choice == 2) + (choice == 3) < 1)
	{
		cout << "�����������������룺" << endl;
		cin >> choice;
	}
	switch (choice)
	{
		//��¼�˺�
	case 1:
		loginUser();
		system("cls");
		return 1;
		//ע���˺�
	case 2:
		addUser();
		system("cls");
		return 2;
		//��¼����Ա�˺�
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
	cout << "1.ѡ��ؿ�\n2.ע���˺�" << endl;
	cout << "?";
	int choice;
	cin >> choice;
	while ((choice == 1) + (choice == 2) < 1)
	{
		cout << "�����������������룺" << endl;
		cin >> choice;
	}
	switch (choice)
	{
		//ѡ��ؿ�
	case 1:
		chooseLevel();
		//ע���˺�
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
			cerr << "�ļ���ʧ��" << endl;
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
	cout << "�����������˻���" << endl;
	cin >> account;
	while (account.size() > 10|| users.find(account) == users.end())
	{
		cout << "�����������������룺" << endl;
		cin >> account;
	}

	cout << "���������룺" << endl;
	cin >> password;
	while (this->users.at(account).password != password)
	{
		cout << "�����������������룺" << endl;
		cin >> password;
	}

	cout << "��¼�ɹ���" << endl;
}

void game::addUser()
{
	ofstream addUser;
	addUser.open("users.dat", ios::binary | ios::app);

	if (!addUser.is_open())
	{
		cerr << "�ļ���ʧ��" << endl;
		exit(EXIT_FAILURE);
	}

	user newUser;

	cout << "������1-10λ���˺�" << endl;
	string account;
	cin >> account;
	while (account.size() > 10)
	{
		cout << "������������������룺" << endl;
		cin >> account;
	}
	while (users.find(account) != users.end())
	{
		cout<<"���˺��Ѵ��ڣ����������룺"<<endl;
		cin >> account;
	}

	strcpy_s(newUser.account, account.c_str());

	cout << "������1-10λ������" << endl;
	string password;
	cin >> password;
	while (password.size() > 10)
	{
		cout << "������������������룺" << endl;
		cin >> password;
	}

	strcpy_s(newUser.password,password.c_str());

	this->users.insert(make_pair(account, newUser));
	//д�뵽�ļ���
	addUser.write(reinterpret_cast<const char*>(&newUser), sizeof(user));
	addUser.close();
}

void game::chooseLevel() const
{
	cout << "����1-20�أ���ѡ����Ҫ��Ĺؿ���" << endl;
	int choice;
	cin >> choice;
	while (choice < 1 || choice>20)
	{
		cout << "�����������������룺" << endl;
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
			cout << "ʤ����" << endl;
			break;
		}
	}
}
