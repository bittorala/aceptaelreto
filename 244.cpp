// bittorala
#include <stdio.h>
#include <bitset>
#define MAX_PIECES 100
static const int MAX = 2000;
static std::bitset<2*MAX> DH_DIAGONALS;
static std::bitset<2*MAX> UH_DIAGONALS;
static std::bitset<MAX> X_POSITIONS;
static std::bitset<MAX> Y_POSITIONS; 
static int used_dh_diagonals[MAX_PIECES];
static int used_uh_diagonals[MAX_PIECES];
static int used_x_positions[MAX_PIECES];
static int used_y_positions[MAX_PIECES];

static int ROWS, PIECES, X, Y;

bool attacked, linebreak;

inline void process(int i)
{
	if (DH_DIAGONALS[X - Y + MAX] || UH_DIAGONALS[X+Y] || X_POSITIONS[X] || Y_POSITIONS[Y])
		attacked = true;
	else
	{
		DH_DIAGONALS.set(X-Y+MAX);
		UH_DIAGONALS.set(X+Y);
		X_POSITIONS.set(X);
		Y_POSITIONS.set(Y);
		used_dh_diagonals[i] = X - Y + MAX;
		used_uh_diagonals[i] = X + Y;
		used_x_positions[i] = X;
		used_y_positions[i] = Y;
	}
}

inline int fastscan()
{
	int num = 0; char c;
	for (c = getchar_unlocked(); c < '0' || c > '9'; c = getchar_unlocked());
	for (; c >= '0' && c <= '9'; c = getchar_unlocked())
		num = num * 10 + ((int) c - '0');
	return num;
}

int main()
{
	for (ROWS = fastscan(); ROWS != 0; ROWS = fastscan())
	{
		PIECES = fastscan();
		attacked = false;
		for (int i = 0; i < PIECES; ++i)
		{
			X = fastscan(); Y = fastscan(); --X; --Y;
			if (!attacked) process(i);
		}
		if (attacked)
		{
			putchar_unlocked('S'); putchar_unlocked('I'); putchar_unlocked('\n');
		}
		else 
		{
			putchar_unlocked('N'); putchar_unlocked('O'); putchar_unlocked('\n');
		}
		for (unsigned int i = 0; i < PIECES; ++i) 
		{
			DH_DIAGONALS.reset(used_dh_diagonals[i]);
			UH_DIAGONALS.reset(used_uh_diagonals[i]);
			X_POSITIONS.reset(used_x_positions[i]);
			Y_POSITIONS.reset(used_y_positions[i]);
		}
	}
	return 0;
}