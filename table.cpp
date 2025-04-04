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
	//遍历每个格子
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
	cout << "TRIANGLE：" << this->symbolNum[0] << "  CIRCLE：" << this->symbolNum[1] << "  RECTANGLE：" << this->symbolNum[2] << endl;
}

void table::recFile(string path)
{
	ifstream ifs(path);
	if (ifs.is_open())
	{
		cout << "文件已打开" << endl;
	}
	else
	{
		cout << "文件未打开" << endl;
	}
	ifs >> this->sideWidth >> this->sideLength;

	//初始化答案数组
	//遍历每一行
	for (int i = 0; i < sideWidth; i++)
	{
		vector<cell*>rank;
		//遍历一行中的每一个
		for (int j = 0; j < sideLength; j++)
		{
			int num;
			ifs >> num;
			rank.push_back(new cell(changeIntToSymbol(num)));
		}
		this->cells.push_back(rank);
	}
	ifs.close();
	//初始化symbolNum
	this->updateSymbolNum();
}

void table::addSymbol()
{
	int x=0, y=0, inputSymbol=0;
	cout << "按如下格式输入:(（横坐标），（纵坐标），（填入的图案数字））：" << endl;
	//暂时假设用户输入的数据都是有效数据
	cin >> x >> y >> inputSymbol;
	cells[x - 1][y - 1]->changePlayerSymbol(changeIntToSymbol(inputSymbol));
	//放入格子后，现有的symbol数量相应减少
	this->symbolNum[inputSymbol]--;
	//每次操作以后重新初始化symbolNum
	updateSymbolNum();
}

bool table::isWin() const
{
	//遍历每一个格子
	for (int i = 0; i < this->sideWidth; i++)
	{
		for (int j = 0; j < this->sideLength; j++)
		{
			//若格子为空或是格子不为空且为填对，均直接判false
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
	//存放最终显示于最上方提示的数组
	vector<string>rank;
	//先计算每一列上方对应的提示信息
	for (int i = 0; i < sideLength; i++)
	{
		string str;
		for (int j = 0; j < sideWidth; j++)
		{
			//用于存放连续标志的个数
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

	//计算每一行左侧对应提示信息时同理
	vector<string>row;
	for (int i = 0; i < sideWidth; i++)
	{
		string str;
		for (int j = 0; j < sideLength; j++)
		{
			//用于存放连续标志的个数
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
	//遍历所有的cells
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
	//遍历所有的cells
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
