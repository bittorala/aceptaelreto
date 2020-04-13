// bittorala
#include <string.h>
#include <stdio.h>
#define N_ALPHABET 26
using uint = unsigned int;
bool is_vowel[N_ALPHABET];

inline bool different(char * letters)
{
	return (letters[0] != 'Z' || letters[1] != 'Z' || letters[2] != 'Z');
}

inline uint fastscan() 
{
    char c = getchar_unlocked();
    uint num = 0;

    for (;c < '0' || c > '9'; c = getchar_unlocked()) {}

    for (; c >= '0' && c <= '9'; c = getchar_unlocked()) {
        num = 10 * num + c - '0';
    }

    return num;
}

inline char fastscanchar()
{
	char c = getchar_unlocked();
	for (;c < 'A' || c > 'Z'; c = getchar_unlocked()) {}
	return c;
}

void prepare_vowels()
{
	for(int i = 0; i < 'z'-'a'+1; ++i) is_vowel[i] = false;
	is_vowel['a'-'a'] = true;
	is_vowel['e'-'a'] = true;
	is_vowel['i'-'a'] = true;
	is_vowel['o'-'a'] = true;
	is_vowel['u'-'a'] = true;
}

inline char add_char(char a, bool plusone)
{
	return 'A' + ((a - 'A') + 1 + (int) plusone) % N_ALPHABET;
}

void solve(uint num, char * letters)
{
	bool carry = !(bool(++num % 10000));
	num %= 10000;
	for(uint i = 0; i < 3 && carry; ++i)
	{
		letters[2-i] = add_char(letters[2-i], is_vowel[(letters[2-i]-'A'+1) % N_ALPHABET]);
		carry = letters[2-i] == 'B';
	}
	//std::cout << std::setw(4) << std::setfill('0') << num << " " << letters << "\n";
	uint aux = 1000;
	while (aux >= 10 && !(num / aux))
	{
		aux /= 10;
		putchar('0');
	}
	printf("%i %c%c%c\n", num, letters[0], letters[1], letters[2]);
}

int main()
{
	prepare_vowels();
	uint num;
	//std::string letters = "AAA";
	char letters[3];
	num = fastscan();
	letters[0] = fastscanchar();
	letters[1] = fastscanchar();
	letters[2] = fastscanchar();
	while(num != 9999 || different(letters))
	{
		solve(num, letters);
		num = fastscan();
		letters[0] = fastscanchar();
		letters[1] = fastscanchar();
		letters[2] = fastscanchar();
	}
	return 0;
}