    //Name: Justen Phillips
    // Course: CIS 006 Intro to programming
     // CRN: 20577
     // Date: 3/20/2017
     // Assignment: Crossword Generator
    
    #include "CrosswordGenerator.h" 
    
    int main()
    {
    	const char * pWordListFile = "wordlist.txt";
    	const char * pCSVFile = "wordsIntersect.csv";
    	
    	int wordCount = 0;
    
    	//Determine wordlist size (count)
    	if (!CountWordsInFile(pWordListFile, &wordCount))
    		return -1; //Failed to open file
    
    	cout << pWordListFile << " contains " << wordCount << " words in it" << endl;
    
    	//Allocate a big enough array to hold all strings from file
    	string * pWordArray = new string[wordCount];
    	if (NULL == pWordArray)
    	{
    		//Out of Memory!
    		cout << "Failed to allocated wordList array in memory!" << endl;
    		return false;
    	}
    	
    	if (!ReadWordListFromFile(pWordListFile, pWordArray, wordCount))
    		return -2; //failed to read words from file
    
    	//Sort decending according to word length
    	SortWordsByLenDesc(pWordArray, wordCount);
    
    	//printWordList(pWordArray, wordCount);
    
    	//Create a 2D array for intersection 
    	string **pWordsIntersect = new string*[wordCount];
    	if (NULL == pWordsIntersect)
    	{		
    		cout << "Cannot create WordsIntersect array in memory" << endl;
    		delete[] pWordArray;
    		return -3;
    	}
    
    	//Allocate every row
    	for (int i = 0; i < wordCount; ++i)
    	{
   		pWordsIntersect[i] = new string[wordCount];
   		if (NULL == pWordsIntersect[i])
   		{
   			cout << "Cannot create WordsIntersect array in memory" << endl;
   			delete[] pWordArray;
   			delete[] pWordsIntersect;
   			return -4;
   		}
   	}
   
   
   	for (int i = 0; i < wordCount; ++i)
   	{
   		for (int j = 0; j < wordCount; ++j)
   		{
   			if (i != j)
   			{
   				string shared = sharedLetters(pWordArray[i], pWordArray[j]);
   				pWordsIntersect[i][j] = shared;
   			}
   		}
   	}
   
   	int nRet = 0;
   	//Write intesection to wordsIntersect.csv file
   	if (!WriteWordIntersectionToFile(pCSVFile, pWordsIntersect, wordCount))
   	{
   		cout << "Failed to create CSV file" << endl;
   		nRet = -5;
   	}
   
   	//Cleanup
   	for (int i = 0; i < wordCount; ++i)
   	{
   		delete[] pWordsIntersect[i];
   	}
   	
   	delete[] pWordsIntersect;
   	delete[] pWordArray;
   	
   	cout << "Done!" << endl;
       return nRet;
   }
