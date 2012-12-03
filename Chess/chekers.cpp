#include "Checkers.h"

CChess::CChess()
{
	pBoard = new CCell[BOARD_SIZE];
	memset(pBoard, 0, sizeof(CCell) * BOARD_SIZE);

	memset(mChess, 0, (COUNT_CHESS + COUNT_TARGS) * sizeof(CPos));	//mChess[2] and mTargs[2] - sets zero

	bool bFlag = true;
	for(BYTE i = 0; i < BOARD_HEIGTH; i += 1)
	{
		for(BYTE j = 0; j < BOARD_HEIGTH; j += 1)
		{
			if(bFlag == true)
			{
				pBoard[(i* BOARD_HEIGTH) + j].vColor |= 1U;
			}
			bFlag = bFlag^true;
		}
		bFlag = bFlag^true;
	}
}

CChess::~CChess()
{}

void CChess::Clear()
{
	memset(pBoard, 0, sizeof(CCell) * BOARD_SIZE);

	memset(mChess, 0, (COUNT_CHESS + COUNT_TARGS) * sizeof(CPos));	//mChess[2] and mTargs[2] - sets zero

	bool bFlag = true;
	for(BYTE i = 0; i < BOARD_HEIGTH; i += 1)
	{
		for(BYTE j = 0; j < BOARD_HEIGTH; j += 1)
		{
			if(bFlag == true)
			{
				pBoard[(i* BOARD_HEIGTH) + j].vColor |= 1U;
			}
			bFlag = bFlag^true;
		}
		bFlag = bFlag^true;
	}
}

void CChess::ShowBoard()
{
	cout<<"\n   1 2 3 4 5 6 7 8\n\n";
	for(BYTE i = 0; i < BOARD_HEIGTH; i += 1)
	{
		cout<<(int)(i + 1)<<"  ";
		for(BYTE j = 0; j < BOARD_HEIGTH; j += 1)
		{
			switch(*(BYTE*)&pBoard[(i * BOARD_HEIGTH) + j])
			{
				case M_EMPTY:
				{
					cout<<char(1)<<"|";
				}break;

				case M_BLACK_COLOR:
				{
					cout<<char(2)<<"|";
				}break;

				default:
				{
					switch(*(BYTE*)&pBoard[(i * BOARD_HEIGTH) + j] & ~M_BLACK_COLOR)
					{
						case M_HOLE:	//hole
						{
							cout<<"-|";
						}break;

						case M_WHITE_TARGET:	//black target
						{
							cout<<"+|";
						}break;

						case M_BLACK_TARGET:	//white target
						{
							cout<<"*|";
						}break;

						case M_WHITE_CHESS:	//white chess
						{
							cout<<"W|";
						}break;

						case M_BLACK_CHESS:	//black chess
						{
							cout<<"B|";
						}break;

						case M_WHITE_PASS:	//white chess pass
						{
							cout<<"1|";
						}break;

						case M_BLACK_PASS:	//black chess pass
						{
							cout<<"2|";
						}break;

						default:
						{
							cout<<"||";
						}
					}
				}
			}
		}
		cout<<"\n";
	}
}

bool CChess::Set( BYTE x, BYTE y, int obj)
{
	--x;	//update to array
	--y;	//update to array

	//temporary pointer to pBoard[x][y];
	BYTE *pTmp;	
	pTmp = (BYTE*)(pBoard + ((y * BOARD_HEIGTH) + x ));

	if(x < 0 && x >= BOARD_HEIGTH && y < 0 && y >= BOARD_HEIGTH)
	{
		return false;
	}

	//to ignore least bit
	switch(*pTmp  & ~M_BLACK_COLOR)
	{
		case M_EMPTY:	//if cell is free
		{
			switch(obj)
			{
				case M_WHITE_CHESS:	//sets color
				{
					if(*pTmp & (BYTE)BLACK_COL || *(BYTE*)&mChess[WHITE_COL] != 0) //not white cell -OR- already setted
					{
						return false;
					}

					mChess[WHITE_COL].x = x + 1;
					mChess[WHITE_COL].y = y + 1;
				}break;

				case M_BLACK_CHESS:	//sets color
				{
					if(((*pTmp & (BYTE)BLACK_COL)) == NULL || *(BYTE*)&mChess[BLACK_COL] != 0) //not black cell -OR- already setted
					{
						return false;
					}
					mChess[BLACK_COL].x = x + 1;
					mChess[BLACK_COL].y = y + 1;
				}break;

				case M_HOLE:	//sets hole
				{

				}break;

				case M_WHITE_TARGET:	//sets white target
				{
					if(*pTmp & (BYTE)BLACK_COL || *(BYTE*)&mTargs[WHITE_COL] != 0) //not white cell -OR- already setted
					{
						return false;
					}
					mTargs[WHITE_COL].x = x + 1;
					mTargs[WHITE_COL].y = y + 1;
				}break;

				case M_BLACK_TARGET:	//sets black target
				{
					if((*pTmp & (BYTE)BLACK_COL) == NULL || *(BYTE*)&mTargs[BLACK_COL] != 0) //not black cell -OR- already setted
					{
						return false;
					}
					mTargs[BLACK_COL].x = x + 1;
					mTargs[BLACK_COL].y = y + 1;
				}break;

				case M_WHITE_PASS:	//sets white pass
				{
					
				}break;

				case M_BLACK_PASS:	//sets black pass
				{
					
				}break;

				default:
				{
					return false;
				}
			}

			//set object on board
			*pTmp |= obj;
			return true;
		}break;

		default:
		{
			return false;
		}
	}
}

BYTE CChess::MoveToTarg(int Color)
{
	BYTE cTmp = 0;	//temporary count of turns

	while(*(BYTE*)&mChess[Color] != *(BYTE*)&mTargs[Color])
	{
		if(mChess[Color].x > mTargs[Color].x)
		{
			mChess[Color].x -= 1;
		}
		else
		{
			if(mChess[Color].x < mTargs[Color].x)
			{
				mChess[Color].x += 1;
			}
			else	//if(mChess[Color].x == mTargs[Color].x)
			{
				if(mChess[Color].x > 7)
				{
					mChess[Color].x -= 1;
				}
				else
				{
					mChess[Color].x += 1;
				}
			}
		}
		/////////////
		if(mChess[Color].y > mTargs[Color].y)
		{
			mChess[Color].y -= 1;
		}
		else
		{
			if(mChess[Color].y < mTargs[Color].x)
			{
				mChess[Color].y += 1;
			}
			else	//if(mChess[WHITE_COL].y == mTargs[WHITE_COL].y)
			{
				if(mChess[Color].y > 7)
				{
					mChess[Color].y -= 1;
				}
				else
				{
					mChess[Color].y += 1;
				}
			}
		}
		if(Color == WHITE_COL)
		{
			Set(mChess[Color].x, mChess[Color].y, M_WHITE_PASS);
		}
		else
		{
			Set(mChess[Color].x, mChess[Color].y, M_BLACK_PASS);
		}
		cTmp++;

	}

	return cTmp;
}