#ifndef CHESS_H
#define CHESS_H

#include <iostream>

using namespace std;

#define IN	const
#define OUT

#define BOARD_SIZE		64		//all chess cells
#define BOARD_HEIGTH	8		//count of horizontal cells
#define COUNT_CHESS		2		//count of chess
#define COUNT_TARGS		2		//count of targets

#define BLACK_COL		1
#define WHITE_COL		0

//masks
#define M_EMPTY			0x0		//empty or white color			0000 0000
#define M_BLACK_COLOR	0x1		//black color					0000 0001
#define M_HOLE			0x2		//hole - disable cell			0000 0010
#define M_WHITE_TARGET	0x4		//white target!!!				0000 0100
#define M_BLACK_TARGET	0x8		//black target!!!				0000 1000
#define M_WHITE_CHESS	0x10	//white chess					0001 0000
#define M_BLACK_CHESS	0x20	//black chess					0010 0000
#define M_WHITE_PASS	0x40	//marked pass of white chess	0100 0000
#define M_BLACK_PASS	0x80	//marked pass of black chess	1000 0000

typedef unsigned char BYTE;

struct CCell
{
	BYTE vColor	: 1;	//color:	0 - while, 1 - black
	BYTE vHole	: 1;	//hole:		0 - non hole, 1 - hole
	BYTE vTarg	: 2;	//target	0 - non target,	01 - white target,	10 - black target
	BYTE vChess	: 2;	//chess		00 - non chess, 01 - white chess, 10 - black chess
	BYTE vPass	: 2;	//pass		00 - non pass, 01 - white pass, 10 - black pass
};

struct CPos
{
	BYTE x:4;	//x position
	BYTE y:4;	//y position
};

class CChess
{
public:
	CChess();
	~CChess();
	void ShowBoard();
	bool Set(BYTE x, BYTE y, int obj);

	BYTE MoveToTarg(int Color);
	void Clear();

private:
	CCell* pBoard;
	CPos mChess[COUNT_CHESS];
	CPos mTargs[COUNT_TARGS];
};

#endif /*CHESS_H*/