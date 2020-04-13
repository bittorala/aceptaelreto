// bittor
#include <stdio.h>
#include <cstring>

#define nullchar '\0'

inline char tolower(char c)
{
    return (c >= 'A' && c <= 'Z') ?  'a' + c - 'A' : c;
}

void computeLPSArray(const char* pat, int M, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

bool KMPSearch(const char* pat, const char* txt, int M, int N) 
{ 
    // int M = strlen(pat); 
    // int N = strlen(txt); 
  
    // create lps[] that will hold the longest prefix suffix 
    // values for pattern 
    int lps[M]; 
  
    // Preprocess the pattern (calculate lps[] array) 
    computeLPSArray(pat, M, lps); 
  
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < 2 * N) 
    {
        if (pat[j] == txt[i % N]) 
        { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
            return true;
            j = lps[j - 1]; 
        } 
  
        // mismatch after j matches 
        else if (i < 2 * N && pat[j] != txt[i % N]) { 
            // Do not match lps[0..lps[j-1]] characters, 
            // they will match anyway 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
    return false;
} 

// inline bool compare(char s1[], char s2[], unsigned n, unsigned startpos)
// {
//     bool trif = true;
//     for (unsigned i = 0; i < n && trif; ++i)
//     {
//         trif = s1[(startpos + i) % n] == s2[i];
//     }
//     return trif;
// }

int main()
{
    //std::ios::sync_with_stdio(false);
    unsigned s1_size, s2_size;
   // std::string s1, s2;
    bool same, trif;
            char s1[25];
        char s2[25];
    int N;
    scanf("%i", &N);
    //std::cin >> N;
    for (int i = 0; i < N; ++i)
    {
        scanf("%s", s1);
        scanf("%s", s2);
        //std::cin >> s1 >> s2;
        trif = false, same = true;
        s1_size = strlen(s1);
        s2_size = strlen(s2);
        if (s1_size != s2_size)
        {
            puts("NO"); continue;
        } 
        for (unsigned i = 0; i < s1_size; ++i)
        {
            if (s1[i] == 'v' || s1[i] == 'V') s1[i] = 'b';
            if (s2[i] == 'v' || s2[i] == 'V') s2[i] = 'b';
            s1[i] = tolower(s1[i]);
            s2[i] = tolower(s2[i]);
            if (same) same = s1[i] == s2[i];
        }
        if (same)
        {
            puts("NO"); continue;
        } 
        trif = KMPSearch(s2, s1, s2_size, s1_size);
        trif ? puts("SI") : puts("NO");
        //trif ? std::cout << "SI\n" : std::cout << "NO\n";
    }
    return 0;
}