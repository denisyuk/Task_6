#include "Checkers.h"

void main(void)
{
	CChess *pCh = new CChess;
	BYTE ch;
	BYTE Y= 0;
	BYTE X = 0;

	cout<<"\nHello! Welcome to chess!\n";
	pCh->ShowBoard();
	system("pause");

do
{	
	pCh->Clear();
	do
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		system("cls");
		pCh->ShowBoard();
		cout<<"\nLook at chess board, and set BLACK chess in position!\n";
		cout<<"(horizontal) X: ";
			cin>>(int&)X;
		cout<<"(vertical) Y: ";
			cin>>(int&)Y;
		if(!cin.good())
		{
			cout<<"\nError! Try again!\n";
			system("pause");
		}
	}
	while(!pCh->Set(X,Y, M_BLACK_CHESS));
	cout<<"\nGood! \n";
	system("pause");

	do
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		system("cls");
		pCh->ShowBoard();

		cout<<"\nAt now set WHITE chess in position!\n";
		cout<<"(horizontal) X: ";
			cin>>(int&)X;
		cout<<"(vertical) Y: ";
			cin>>(int&)Y;
		
		if(!cin.good())
		{
			cout<<"\nError! Try again!\n";
			system("pause");
		}
	}
	while(!pCh->Set(X,Y, M_WHITE_CHESS));
	cout<<"\nGood! \n";
	system("pause");

	do
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		system("cls");
		pCh->ShowBoard();

		cout<<"\nSet BLACK TARGET in position!\n";
		cout<<"(horizontal) X: ";
			cin>>(int&)X;
		cout<<"(vertical) Y: ";
			cin>>(int&)Y;

		if(!cin.good())
		{
			cout<<"\nError! Try again!\n";
			system("pause");
		}
	}
	while(!pCh->Set(X,Y, M_BLACK_TARGET));
	cout<<"\nGood! \n";
	system("pause");

	do
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		system("cls");
		pCh->ShowBoard();

		cout<<"\nSet WHITE TARGET in position!\n";
		cout<<"(horizontal) X: ";
			cin>>(int&)X;
		cout<<"(vertical) Y: ";
			cin>>(int&)Y;

		if(!cin.good())
		{
			cout<<"\nError! Try again!\n";
			system("pause");
		}
	}
	while(!pCh->Set(X,Y, M_WHITE_TARGET));
	cout<<"\nGood! \n";
	system("pause");

	
	system("cls");

	cout<<"\nCount of WHITE turns: "<<(int)pCh->MoveToTarg(WHITE_COL)<<"\n";
	cout<<"\nCount of BLACK turns: "<<(int)pCh->MoveToTarg(BLACK_COL)<<"\n";

	pCh->ShowBoard();
	system("pause");

	

	do
	{
		system("cls");
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());

		cout<<"\n\n\'y\' - to play again\n\'n\' - to exit\n\nLet enter you choice: ";
		cin>>ch;

		if(!cin.good() || (ch != 'y' && ch != 'n'))
		{
			cout<<"\nTry again!\n";
			system("pause");
		}
	}
	while(ch != 'y' && ch != 'n');
}
while(ch == 'y');

delete pCh;

//cout<<"\nGood luck!\n";
system("pause");
}