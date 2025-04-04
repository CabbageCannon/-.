#pragma once
#include<iostream>
enum symbol{TRIANGLE=0,CIRCLE=1,RECTANGLE=2};
class cell
{
public:
	cell(symbol);
	void changePlayerSymbol(symbol);
	symbol getMySymbol() const;
	symbol getPlayerSymbol() const;
	bool isEmpty() const;
	void changeIsEmpty(bool);
private:
	symbol mySymbol;
	bool IsEmpty;
	symbol playerSymbol;
};

