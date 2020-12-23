// Bittor
#include <stdio.h>

struct AccidentRecord 
{
    int casualties, YYYY, MM, DD;
    int prevBiggest = -1;
};

AccidentRecord accidents[300002];

inline bool fastscan(int & num)
{
    num = 0;
    char c = getchar_unlocked();
    for (; (c < '0' || c > '9') && c >= 0; c = getchar_unlocked());
    if (c < 0) return false;
    for (; c >= '0' && c <= '9'; c = getchar_unlocked())
        num = num * 10 + c - '0';
    return c >= 0;
}

inline void scanaccident(AccidentRecord & acc)
{
    fastscan(acc.DD);
    fastscan(acc.MM);
    fastscan(acc.YYYY);
    fastscan(acc.casualties);
}

inline void printaccidentdate(int i)
{
    if (i < 0) puts("NO HAY");
    else printf("%02d/%02d/%04d\n", accidents[i].DD, accidents[i].MM, accidents[i].YYYY);
}

inline int findPrevBiggest(int i)
{
    int j = i - 1;
    while (j >= 0 && accidents[j].casualties <= accidents[i].casualties)
    {
        j = accidents[j].prevBiggest;
    }  
    accidents[i].prevBiggest = j;
    return j;
}

int main()
{
    int N;
    while(fastscan(N))
    {
        for (int i = 0; i < N; ++i)
        {
            scanaccident(accidents[i]);
            printaccidentdate(findPrevBiggest(i));
        } 
        puts("---");
    }    
    return 0;
}


