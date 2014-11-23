TETRIS_CG
=========

Tetris Game in C++

TETRIS GAME


INTRODUCTION
This program is an implementation of the classic puzzle arcade game ‘TETRIS’.
The game was originally designed in 1984 in Russia and has made it to almost all major platforms in several different forms.This project is an attempt to emulate the DOS tetris released in 1986 for windows.



GAMEPLAY
Tetriminos are game pieces shaped like  geometric shapes composed of four square blocks each. A random  sequence of pieces fall down the playing field (a rectangular vertical shaft, called the "well" or "matrix"). 

The objective of the game is to manipulate these pieces, by moving each one sideways and rotating it by 90 degree units, with the aim of creating a horizontal line of ten blocks without gaps. When such a line is created, it disappears, and any block above the deleted line will fall.


CONTROLS
The game controls are as:
Control:	ARROW KEYS
Exit:		Esc
VARIABLES & FUNCTIONS

#define BOARD_LINE_WIDTH 6			
Width of each of the two lines that delimit the board

#define BLOCK_SIZE 16
Width and Height of each block of a piece

#define  BOARD_POSITION 320
Center position of the board from the left of the screen

#define  BOARD_WIDTH 10
Board width in blocks 

#define  BOARD_HEIGHT 20
Board height in blocks

#define  MIN_VERTICAL_MARGIN 20
Minimum vertical margin for the board limit 		

#define  MIN_HORIZONTAL_MARGIN 20
Minimum horizontal margin for the board limit

#define  PIECE_BLOCKS 5	
Number of horizontal and vertical blocks of a matrix piece

char  mPieces [7][4][5][5]
Each piece is a 5x5 array, there are 4 possible rotations possible for each block and 7 such pieces

int  mPiecesInitialPosition [7 /*kind */ ][4 /* rotation */ ][2 /* position */]
Find the x and y initial position of each block from where it starts dropping. 

enum  { POS_FREE, POS_FILLED }
Indicates the state of the blocks in the board, either FREE or EMPTY


int   mBoard [BOARD_WIDTH][BOARD_HEIGHT]
Array to store the status of each Board Bloack
 
int  mPosX,  mPosY
Used to store position of Block that is falling down

int  mPiece,  mRotation
Used to store the type and rotation status of the blaock falling down

int  mNextPosX,  mNextPosY
Position of the next piece,ie it s shown on side of screen

int  mNextPiece, mNextRotation
Kind and rotation of the next piece

void   DrawRectangle  (int pX1, int pY1, int pX2, int pY2, int color)
Used to draw a single block in a given piece	
	
	
int  GetScreenHeight ()
Returns screen height


Int  GetBlockType  (int pPiece1, int pRotation1, int pX1, int pY1)
Return the type of a block in a given piece 
(0 = no-block, 1 = normal block) 


int  GetXInitialPosition  (int pPiece, int pRotation)
Returns the horizontal displacement of the piece that has to be applied in order to create it in the correct position.
	
	

int  GetYInitialPosition  (int pPiece, int pRotation)
Returns the vertical displacement of the piece that has to be applied in order to create it in the correct position.


int  IsFreeBlock (int pX, int pY)
Returns whether the board position is free or not


void  InitBoard ()
Sets all board blocks to FREE state


void  StorePiece  (int pX, int pY, int pPiece, int pRotation)
Store each block of the piece into the board



int  GetXPosInPixels (int pPos)
Returns the horizontal position (in pixels) of the block given like parameter
	

int  GetYPosInPixels (int pPos)
Returns the vertical position (in pixels) of the block given like parameter


void  DeleteLine  (int pY)
Moves all the upper lines one row down


int IsGameOver ()
If the first line has blocks, then, game over
	

void  DeletePossibleLines ()
If it is possible to delete a line,do so by calling DeleteLine



int  IsPossibleMovement  (int pX, int pY, int pPiece, int pRotation)
Checks collision with pieces already stored in the board or the board limits



int  GetRand  (int pA, int pB)
Get a random int between to integers pa and pb



void  Board (int pScreenHeight)
Init the board blocks with free positions



void  InitGame()
Creates the Initial pieces and the next piece




void  CreateNewPiece ()
Sets next piece to current piece and then randomly creates a next pieces


void  Game ()
Initializes the game

void  DrawPiece  (int pX, int pY, int pPiece, int pRotation)
Draws a piece that is falling down or a piece shown as the next piece


void  DrawBoard  ()
Draws the rectangle that delimits the board and the blocks that are now fixed in the board


void  DrawScore ()
Output Score and name of game

void  DrawScene  ()
Draw on screen


void  Play ()
Sets up and starts a new game


int  main ()
The main program, calls the Play() method and on a loss asks whether to quit or replay 
