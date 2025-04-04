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
	cout <<setw(10)<< "�û��˺�"<<setw(10)<< "�˺�����" << endl;
	for (auto it = this->users.begin(); it != users.end(); it++)
	{
		cout << setw(10) << (*it).first << setw(10) << (*it).second.password<< endl;
	}
}

bool manager::isFileEmpty() const
{
	std::ifstream inFile("manager.dat");
	if (!inFile) {
		cerr << "�޷����ļ�"<<endl;
		return true;
	}

	char ch;
	bool isEmpty = !inFile.get(ch); // �����ȡʧ�ܣ��ļ�Ϊ��
	inFile.close();
	return isEmpty;
}

void manager::setPassword()
{
	string passWord;
	cout << "������1-10λ������:" << endl;
	cin >> passWord;
	while (passWord.size() > 10 || passWord.size()< 1)
	{
		cout << "�����������������룺" << endl;
		cin >> passWord;
	}
	ofstream ofs("manager.dat",ios::out|ios::binary);
	if (!ofs.is_open())
	{
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	ofs << passWord;
	cout << "�������óɹ���" << endl;
}

void manager::login()
{
	ifstream ifs("manager.dat", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	string rightPassWord;
	ifs >> rightPassWord;
	ifs.close();
	string passWord;
	cout << "���������룺" << endl;
	cin >> passWord;
	while (passWord != rightPassWord)
	{
		cout << "�����������������룺" << endl;
		cin >> passWord;
	}
	cout << "��¼�ɹ���" << endl;
	system("pause");
	system("cls");
}

void manager::menu()
{
	cout << "1.�鿴�û���Ϣ��" << endl;
	cout << "2.�޸�����" << endl;
	int choice = 0;
	cout << "?";
	while ((choice == 1) + (choice == 2) == 0)
	{
		cout << "�����������������룺" << endl;
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
