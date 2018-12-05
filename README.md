# crosswordgenerator
CrosswordGenerator.cpp
Requested files: CrosswordGenerator.cpp, CrosswordGenerator.h, CrosswordGenerator_test.cpp (Download)
Type of work: Individual work

For this assignment, you will write a program that forms the basis of a crossword puzzle generator. In order to create a crossword puzzle you need to identify letters that are common to one or more words. This program helps you generate crossword puzzles by identifying letters that are common to several words and string them in an intermediate data structure.

Using intermediate data structures is one way to simplify your coding. You create a data structure that organizes your input so the final output is easier to create. Your CrosswordGenerator program will open a file containing a list of words. To prepare for crossword puzzle generation your code should implement the following pseudo code:

    Open a file named wordlist.txt
    Determine the number of words (N) in the file.
    Create an array of that size called wordArray[];
    Read all the words from the file into an array called wordArray[N].
    Sort the array of words by length in descending order
    Start at the beginning of the array (the longest word) and examine the word
    Find all other words in the array that  can intersect the current word
    Two words can intersect if they share a letter.
    Write a function called String sharedLetters(String S1, String S2)
    Implement sharedLetters(S1,S2) that will return a string containing letters shared by the two parameter strings S1 and S2.
    If no letters are shared between S1 and S2 sharedLetters() should return the empty string "".
    sharedLetters(S1,S2) should ignore case; capital and lower case letters are considered equal
    Create a two dimensional array of Strings wordsIntersect[N][N]  where each dimension N is the size of wordArray.
    Iterate over wordArray comparing distinct words. Do not compare a word to itself.
    If wordArray[i] shares any letters with wordArray[j] place the result of sharedLetters(wordArray[i],wordArray[j]) into wordsIntersect[i][j]

    Non-alphabetic characters should be ignored.

    Upper and lower case letters should be equivalent. Your program should not treat them as distinct tokens.

    The order of shared letters is not a consideration for this program.
    Write the contents of the wordsIntersect array to a Comma Separated Values (CSV) text file named wordsIntersect.csv in row-major form: row,col,value. In the example below, there is an entry in wordsIntersect[12][33] which contains the string "tci". There would also be a line in wordsIntersect.csv that contains 12,33,tci  -- there are no quotes around the letters and the line ends after the letter 'i'. Given that wordsIntersect[12][78] will contains "" there would be a line in the file containing: 12,78, where there is an end of line after the last comma.


N.B.

Example of what sharedLetters() output.

SharedLetters(transaction,dictum) returns "tci"
SharedLetters(Transaction,kudzu) returns ""

If "transaction" is stored in wordArray[12] and "dictum" is stored in wordArray[33] then wordsIntersect[12][33] will contain "tci"

if "kudzu" is stored in wordArray[78] then wordsIntersect[12][78] will contain ""
