#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <time.h>
									


#define BOARD_LINE_WIDTH 6			// Width of each of the two lines that delimit the board
#define BLOCK_SIZE 16				// Width and Height of each block of a piece
#define BOARD_POSITION 320			// Center position of the board from the left of the screen
#define BOARD_WIDTH 10				// Board width in blocks 
#define BOARD_HEIGHT 20				// Board height in blocks
#define MIN_VERTICAL_MARGIN 20		// Minimum vertical margin for the board limit 		
#define MIN_HORIZONTAL_MARGIN 20	// Minimum horizontal margin for the board limit
#define PIECE_BLOCKS 5				// Number of horizontal and vertical blocks of a matrix piece
#define WAIT_TIME 700


char mPieces [7 /*kind */ ][4 /* rotation */ ][5 /* horizontal blocks */ ][5 /* vertical blocks */ ] =
{
// Square
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    }
   },

// I
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 2, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0}, 
    {0, 0, 2, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {1, 1, 2, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    }
   }
  ,
// L
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 2, 1, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 2, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    }
   },
// L mirrored
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 2, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 2, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0}
    }
   },
// N
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 2, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 2, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    }
   },
// N mirrored
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 2, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 1, 2, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    }
   },
// T
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 2, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 2, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 2, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    }
   }
};


int mPiecesInitialPosition  [7 /*kind */ ][4 /* rotation */ ][2 /* position */] =
{
/* Square */
  {
	{-2, -3}, 
    {-2, -3},
    {-2, -3},
    {-2, -3}
   },
/* I */
  {
	{-2, -2},
    {-2, -3},
    {-2, -2},
    {-2, -3}
   },
/* L */
  {
	{-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
/* L mirrored */
  {
	{-2, -3},
    {-2, -2},
    {-2, -3},
    {-2, -3}
   },
/* N */
  {
	{-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
/* N mirrored */
  {
	{-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
/* T */
  {
	{-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
};

enum { POS_FREE, POS_FILLED };			// POS_FREE = free position of the board; POS_FILLED = filled position of the board



int mBoard [BOARD_WIDTH][BOARD_HEIGHT];	// Board that contains the pieces
int mPosX, mPosY;				// Position of the piece that is falling down
int mPiece, mRotation;
int mScreenHeight;				// Screen height in pixels
int mNextPosX, mNextPosY;		// Position of the next piece
int mNextPiece, mNextRotation;	// Kind and rotation of the next piece
int score,temp;
char* scorestring;

void DrawRectangle(int pX1, int pY1, int pX2, int pY2, int color)
	{
	if(color==1)
	setfillstyle(XHATCH_FILL, LIGHTGRAY);
	else if(color==2)
	setfillstyle(SOLID_FILL, BROWN);
	else
	setfillstyle(HATCH_FILL, LIGHTGRAY);
	
	//bar(100, 100, 200, 200);
	bar(pX2, pY1, pX1, pY2);
	rectangle(pX2, pY1, pX1, pY2);
	//floodfill(pX1+1,pY1+1,WHITE);
	//boxColor (mScreen, pX1, pY1, pX2, pY2-1, mColors[pC]);
	}
	
	
	
int GetScreenHeight()
	{
	return getmaxy();
	}
	
int GetBlockType		(int pPiece1, int pRotation1, int pX1, int pY1)
	{
	
			/* 
			======================================									
			Return the type of a block (0 = no-block, 1 = normal block, 2 = pivot block)

			Parameters:

			>> pPiece:		Piece to draw
			>> pRotation:	1 of the 4 possible rotations
			>> pX:			Horizontal position in blocks
			>> pY:			Vertical position in blocks
			====================================== 
			*/

	return mPieces [pPiece1][pRotation1][pX1][pY1];
	}	


int GetXInitialPosition (int pPiece, int pRotation)
	{
			/* 
			======================================									
			Returns the horizontal displacement of the piece that has to be applied in order to create it in the
			correct position.

			Parameters:

			>> pPiece:	Piece to draw
			>> pRotation:	1 of the 4 possible rotations
			====================================== 
			*/
	return mPiecesInitialPosition [pPiece][pRotation][0];
	}	
	

	int GetYInitialPosition (int pPiece, int pRotation)
	{
	
			/* 
			======================================									
			Returns the vertical displacement of the piece that has to be applied in order to create it in the
			correct position.

			Parameters:

			>> pPiece:	Piece to draw
			>> pRotation:	1 of the 4 possible rotations
			====================================== 
			*/

	return mPiecesInitialPosition [pPiece][pRotation][1];
	
	}

int IsFreeBlock(int pX, int pY)
	{
			/* 
			======================================									
			Returns 1 (1) if the this block of the board is empty, 0 if it is filled

			Parameters:

			>> pX:		Horizontal position in blocks
			>> pY:		Vertical position in blocks
			====================================== 
			*/

	if (mBoard [pX][pY] == POS_FREE) return 1; else return 0;
}



void InitBoard()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
		for (int j = 0; j < BOARD_HEIGHT; j++)
			mBoard[i][j] = POS_FREE;
}

void StorePiece (int pX, int pY, int pPiece, int pRotation)
{
	// Store each block of the piece into the board
	for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
		{	
			// Store only the blocks of the piece that are not holes
			if (GetBlockType (pPiece, pRotation, j2, i2) != 0)		
				mBoard[i1][j1] = POS_FILLED;	
		}
	}
}


int GetXPosInPixels(int pPos)
	{
			/* 
			======================================									
			Returns the horizontal position (isn pixels) of the block given like parameter

			Parameters:

			>> pPos:	Horizontal position of the block in the board
			====================================== 
			*/

	return  ( ( BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) ) + (pPos * BLOCK_SIZE) );
}
	
	
int GetYPosInPixels(int pPos)
	{

			/* 
			======================================									
			Returns the vertical position (in pixels) of the block given like parameter

			Parameters:

			>> pPos:	Horizontal position of the block in the board
			====================================== 
			*/

	return ( (mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE) );
}


void DeleteLine (int pY)
{	score=score+10;
	// Moves all the upper lines one row down
	for (int j = pY; j > 0; j--)
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			mBoard[i][j] = mBoard[i][j-1];
		}
	}	
}


int IsGameOver()
{
	//If the first line has blocks, then, game over
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		if (mBoard[i][0] == POS_FILLED) return 1;
	}

	return 0;
}


void DeletePossibleLines ()
{
	for (int j = 0; j < BOARD_HEIGHT; j++)
	{
		int i = 0;
		while (i < BOARD_WIDTH)
		{
			if (mBoard[i][j] != POS_FILLED) break;
			i++;
		}

		if (i == BOARD_WIDTH) DeleteLine (j);
	}
}


int IsPossibleMovement (int pX, int pY, int pPiece, int pRotation)
{
	// Checks collision with pieces already stored in the board or the board limits
	// This is just to check the 5x5 blocks of a piece with the appropiate area in the board
	for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
		{	
			// Check if the piece is outside the limits of the board
			if (	i1 < 0 			|| 
				i1 > BOARD_WIDTH  - 1	||
				j1 > BOARD_HEIGHT - 1)
			{
				if (GetBlockType (pPiece, pRotation, j2, i2) != 0)
					return 0;		
			}

			// Check if the piece have collisioned with a block already stored in the map
			if (j1 >= 0)	
			{	int b=IsFreeBlock(i1,j1);
				if ((GetBlockType (pPiece, pRotation, j2, i2) != 0) &&
					(b == 0)	)
					return 0;
			}
		}
	}

	// No collision
	return 1;
}


	int GetRand (int pA, int pB)
	{
			/*
			======================================
			Get a random int between to integers

			Parameters:
			>> pA: First number
			>> pB: Second number
			======================================
			*/

	return rand () % (pB - pA + 1) + pA;
}



void Board(int pScreenHeight)
	{
	// Get the screen height
	mScreenHeight = pScreenHeight;

	//Init the board blocks with free positions
	InitBoard();
	}



	void InitGame()
{
	
			/* 
			======================================									
			Initial parameters of the game
			====================================== 
			*/
			
	// Init random numbers
	srand ((unsigned int) time(NULL));

	// First piece
	mPiece			= GetRand (0, 6);
	mRotation		= GetRand (0, 3);
	mPosX 			= (BOARD_WIDTH / 2) + GetXInitialPosition (mPiece, mRotation);
	mPosY 			= GetYInitialPosition (mPiece, mRotation);

	//  Next piece
	mNextPiece 		= GetRand (0, 6);
	mNextRotation 	= GetRand (0, 3);
	mNextPosX 		= BOARD_WIDTH + 5;
	mNextPosY 		= 5;	
	}



void CreateNewPiece ()
	{
			/*
			======================================
			Create a random piece
			======================================
			*/

	// The new piece
	mPiece			= mNextPiece;
	mRotation		= mNextRotation;
	mPosX 			= (BOARD_WIDTH / 2) + GetXInitialPosition (mPiece, mRotation);
	mPosY 			= GetYInitialPosition (mPiece, mRotation);

	// Random next piece
	mNextPiece 		= GetRand (0, 6);
	mNextRotation 	= GetRand (0, 3);
}





void Game()
	{		// Game initialization
	InitGame ();
	}


void DrawPiece (int pX, int pY, int pPiece, int pRotation)
{
	//color mColor;				// Color of the block

	// Obtain the position in pixel in the screen of the block we want to draw
	int mPixelsX = GetXPosInPixels (pX);
	int mPixelsY = GetYPosInPixels (pY);

	// Travel the matrix of blocks of the piece and draw the blocks that are filled
	for (int i = 0; i < PIECE_BLOCKS; i++)
	{
		for (int j = 0; j < PIECE_BLOCKS; j++)
		{
			// Get the type of the block and draw it with the correct color
			//switch (mPieces->GetBlockType (pPiece, pRotation, j, i))
			//{
			//	case 1: mColor = GREEN; break;	// For each block of the piece except the pivot
			//	case 2: mColor = BLUE; break;	// For the pivot
			//}

			if (GetBlockType (pPiece, pRotation, j, i) != 0)
				DrawRectangle	(mPixelsX + i * BLOCK_SIZE,
									mPixelsY + j * BLOCK_SIZE,
									(mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
									(mPixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
									1);
		}
	}
}



void DrawBoard ()
{
	// Calculate the limits of the board in pixels
	int mX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
	int mX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
	int mY = mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT);

	// Check that the vertical margin is not to small
	//assert (mY > MIN_VERTICAL_MARGIN);

	// Rectangles that delimits the board
	DrawRectangle (mX1 - BOARD_LINE_WIDTH, mY, mX1, mScreenHeight - 1, 2);
	DrawRectangle (mX2, mY, mX2 + BOARD_LINE_WIDTH, mScreenHeight - 1, 2);

	// Check that the horizontal margin is not to small
	//assert (mX1 > MIN_HORIZONTAL_MARGIN);

	// Drawing the blocks that are already stored in the board
	mX1 += 1;
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{	int a=IsFreeBlock(i,j);
			// Check if the block is filled, if so, draw it
			if (a==0)
				DrawRectangle (	mX1 + i * BLOCK_SIZE,
										mY + j * BLOCK_SIZE,
										(mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
										(mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
										3);
		}
	}
}


void DrawScore()
{
temp=sprintf (scorestring, "score: %d", score);
outtextxy(30, 50, scorestring);
outtextxy(30, 30, "...T-E-T-R-I-S...");
}
	void DrawScene ()
{

	DrawScore();
	DrawBoard ();													// Draw the delimitation lines and blocks stored in the board
	DrawPiece (mPosX, mPosY, mPiece, mRotation);					// Draw the playing piece
	DrawPiece (mNextPosX, mNextPosY, mNextPiece, mNextRotation);	// Draw the next piece
}



/*///////////////////////////////////////////////////////*/


int main()
{
	// ----- Vars -----
		int driver,mode,move,down,k=0,m=1;
		driver = DETECT;
		initgraph(&driver,&mode,"C:\\TurboC3\\BGI");
		char ch;
		clock_t t1,t2;
		score=0;

	// Class for drawing staff, it uses SDL for the rendering. Change the methods of this class
	// in order to use a different renderer

	//DrawRectangle(100,100,200,200,1);

mScreenHeight=GetScreenHeight();
InitBoard();
//DrawBoard();

InitGame();
//DrawScene();

//setbkcolor(WHITE);

//t1 = clock();
time (&t1);


while (1)
		{
			//ClearScreen (); 		// Clear screen
			if(k==1 || m==1)
			{
			cleardevice();
			DrawScene ();			// Draw staff
			k=0;
			m=0;
			}

			

			if(kbhit())
			{
				ch=getch();
				if (ch==75)
				{	if (IsPossibleMovement (mPosX - 1, mPosY, mPiece, mRotation))
					mPosX--;
					k=1;	
					}
				else if (ch==77)
				{	if (IsPossibleMovement (mPosX + 1, mPosY, mPiece, mRotation))
					mPosX++;
					k=1;	
					}
				else if (ch==72)
				{	if (IsPossibleMovement (mPosX, mPosY, mPiece, (mRotation + 1) % 4))
					mRotation = (mRotation + 1) % 4;
					k=1;	
					}
				else if (ch==80) //Down Arrow
				{	down=1;}
				else if (ch==27) //Escape
				{	exit(0);
					}
				else{}
			}
			
			
			



		////////////////////////////////////////Downward Movement
		//t2 = clock();
		time (&t2);
		
		if(((difftime (t2,t1))>0.5)|| down==1)
		{	down=0;
			m=1;
			
			move=IsPossibleMovement (mPosX, mPosY + 1, mPiece, mRotation);
			if (move==1)
			{
				mPosY++;
			}
			else
			{
				StorePiece (mPosX, mPosY, mPiece, mRotation);

				DeletePossibleLines ();

				if ((IsGameOver())==1)
				{

					exit(0);
				}

				CreateNewPiece();
			}
			
		//t1 = clock();
		time (&t1);
		
		}






			}


	getch();
	closegraph();

	return 0;
}
