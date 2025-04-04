#include "table.h"

table::table(int choice)
{
	string fileName = "question\\question" + to_string(choice)+".txt";
	cout << fileName << endl;
	recFile(fileName);
	getTips();
	initSymbolNum();
}

void table::showTable()
{
	cout << "\t";
	for (auto it = this->tips[0].begin(); it != tips[0].end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	//����ÿ������
	for (int i = 0; i < sideWidth; i++)
	{
		cout << tips[1][i];
		cout << "\t";
		for (int j = 0; j < sideLength; j++)
		{
			if (cells[i][j]->isEmpty())
			{
				cout << " \t";
			}
			else
			{
				cout << cells[i][j]->getPlayerSymbol() << "\t";
			}
		}
		cout << endl;
	}
	//enum symbol{TRIANGLE=0,CIRCLE=1,RECTANGLE=2};
	cout << "TRIANGLE��" << this->symbolNum[0] << "  CIRCLE��" << this->symbolNum[1] << "  RECTANGLE��" << this->symbolNum[2] << endl;
}

void table::recFile(string path)
{
	ifstream ifs(path);
	if (ifs.is_open())
	{
		cout << "�ļ��Ѵ�" << endl;
	}
	else
	{
		cout << "�ļ�δ��" << endl;
	}
	ifs >> this->sideWidth >> this->sideLength;

	//��ʼ��������
	//����ÿһ��
	for (int i = 0; i < sideWidth; i++)
	{
		vector<cell*>rank;
		//����һ���е�ÿһ��
		for (int j = 0; j < sideLength; j++)
		{
			int num;
			ifs >> num;
			rank.push_back(new cell(changeIntToSymbol(num)));
		}
		this->cells.push_back(rank);
	}
	ifs.close();
	//��ʼ��symbolNum
	this->updateSymbolNum();
}

void table::addSymbol()
{
	int x=0, y=0, inputSymbol=0;
	cout << "�����¸�ʽ����:(�������꣩���������꣩���������ͼ�����֣�����" << endl;
	//��ʱ�����û���������ݶ�����Ч����
	cin >> x >> y >> inputSymbol;
	cells[x - 1][y - 1]->changePlayerSymbol(changeIntToSymbol(inputSymbol));
	//������Ӻ����е�symbol������Ӧ����
	this->symbolNum[inputSymbol]--;
	//ÿ�β����Ժ����³�ʼ��symbolNum
	updateSymbolNum();
}

bool table::isWin() const
{
	//����ÿһ������
	for (int i = 0; i < this->sideWidth; i++)
	{
		for (int j = 0; j < this->sideLength; j++)
		{
			//������Ϊ�ջ��Ǹ��Ӳ�Ϊ����Ϊ��ԣ���ֱ����false
			if (this->cells[i][j]->isEmpty() || (!this->cells[i][j]->isEmpty() &&
				this->cells[i][j]->getMySymbol() !=
				this->cells[i][j]->getPlayerSymbol()))
				return false;
		}
	}
	return true;
}

void table::getTips()
{
	//���������ʾ�����Ϸ���ʾ������
	vector<string>rank;
	//�ȼ���ÿһ���Ϸ���Ӧ����ʾ��Ϣ
	for (int i = 0; i < sideLength; i++)
	{
		string str;
		for (int j = 0; j < sideWidth; j++)
		{
			//���ڴ��������־�ĸ���
			int sNum = 1;
			while ((j < sideWidth - 1) && (cells[j][i]->getMySymbol() == cells[j + 1][i]->getMySymbol()))
			{
				sNum++;
				j++;
				if (j == sideWidth)
					break;
			}
			string tempStr = to_string(sNum);
			str += tempStr;
		}
		rank.push_back(str);
	}

	//����ÿһ������Ӧ��ʾ��Ϣʱͬ��
	vector<string>row;
	for (int i = 0; i < sideWidth; i++)
	{
		string str;
		for (int j = 0; j < sideLength; j++)
		{
			//���ڴ��������־�ĸ���
			int sNum = 1;
			while ((j < sideLength - 1) && (cells[i][j]->getMySymbol() == cells[i][j+1]->getMySymbol()))
			{
				sNum++;
				j++;
				if (j == sideLength)
					break;
			}
			string tempStr = to_string(sNum);
			str += tempStr;
		}
		row.push_back(str);
	}
	this->tips.push_back(rank);
	this->tips.push_back(row);
}

void table::initSymbolNum()
{
	symbolNum.clear();
	for (int i = 0; i <= 2; i++)
	{
		symbolNum.push_back(0);
	}
	//�������е�cells
	for (int i = 0; i < this->sideWidth; i++)
	{
		for (int j = 0; j < this->sideLength; j++)
		{
			{
				switch (cells[i][j]->getMySymbol())
				{
					//enum symbol{TRIANGLE=0,CIRCLE=1,RECTANGLE=2};
				case TRIANGLE:
				{
					this->symbolNum[0]++;
					break;
				}
				case CIRCLE:
				{
					this->symbolNum[1]++;
					break;
				}
				case RECTANGLE:
				{
					this->symbolNum[2]++;
					break;
				}
				default:
					break;
				}
			}
		}
	}
}

void table::updateSymbolNum()
{
	initSymbolNum();
	//�������е�cells
	for (int i = 0; i < this->sideWidth; i++)
	{
		for (int j = 0; j < this->sideLength; j++)
		{
			{
				if(!cells[i][j]->isEmpty())
				switch (cells[i][j]->getPlayerSymbol())
				{
					//enum symbol{TRIANGLE=0,CIRCLE=1,RECTANGLE=2};
				case TRIANGLE:
				{
					this->symbolNum[0]--;
					break;
				}
				case CIRCLE:
				{
					this->symbolNum[1]--;
					break;
				}
				case RECTANGLE:
				{
					this->symbolNum[2]--;
					break;
				}
				default:
					break;
				}
			}
		}
	}
}

symbol table::changeIntToSymbol(int num)
{
	//TRIANGLE, CIRCLE, RECTANGLE
	switch (num)
	{
	case 0:
		return TRIANGLE;
	case 1:
		return CIRCLE;
	case 2:
		return RECTANGLE;
	}
}
