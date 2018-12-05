// Name: Justen Phillips
 // Course: CIS 006 Intro to programming
     // CRN: 20577
     // Date: 3/20/2017
     // Assignment: Crossword Generator
     #ifndef CrosswordGenerator
     #define CrosswordGenerator
     #include <string>
     #include <cstring>
    #include <fstream>
    #include <iostream>
    #include <ctype.h> //tolower
    
    using namespace std;
    
    bool ReadWordListFromFile(const char * , string* , int );
    bool CountWordsInFile(const char * , int * );
    int compareLength(const void *, const void *);
    void SortWordsByLenDesc(string * pWordList, int count);
    string sharedLetters(string s1, string s2);
    bool WriteWordIntersectionToFile(const char *, string **, int);
    
    void DualSort(int [], string [], int );
    #endif
    
