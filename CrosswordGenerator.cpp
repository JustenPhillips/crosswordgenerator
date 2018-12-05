     //Name: Justen Phillips
     // Course: CIS 006 Intro to programming
     // CRN: 20577
     // Date: 3/20/2017
     // Assignment: Crossword Generator
     #include "CrosswordGenerator.h"
     
     bool CountWordsInFile(const char * pFile, int * pCount)
     {
    	fstream inFile;
    
    	*pCount = 0;
    
    	//Open a file named wordlist.txt
    	inFile.open(pFile);
    	if (!inFile.is_open())
    	{
    		cout << "Failed to open: " << pFile << endl;
    		return false;
    	}
    
    	//Determine the number of words (N) in the file.
    	string line;
    	int count = 0;
    	while (getline(inFile, line))
    		++count;
    	inFile.close();
    	*pCount = count;
    	return true;
    }
    
    //Function to read lines from file into string list
    bool ReadWordListFromFile(const char * pFile, string* pWordArray, int count)
    {
    	
    	fstream inFile;
    	//Open a file named wordlist.txt
    	inFile.open(pFile);
    	if (!inFile.is_open())
    	{
    		cout << "Failed to open: " << pFile << endl;
    		return false;
    	}
    	
    	string line;
    	//Read exactly (count) words
    	for (int i = 0; i < count; ++i)
    	{
    		if (!getline(inFile, line))
    		{
    			//Something went wrong!
    			inFile.close();
    			return false;
    		}
    
    		//sanitize the word from line and put it into array
    		pWordArray[i] = "";
    		for (int j = 0; j < line.length(); ++j)
    		{
    			//make every letter lower case
    			char c = tolower(line[j]);
    
    			//only accept alphabets 
    			if (c >= 'a' && c <= 'z')
    				pWordArray[i] += c;
    		}
    	}
    
    	//success!
    	inFile.close();	
    	return true;
    }
    
    //Used by qsort
    int compareLength(const void *arg1, const void *arg2)
    {
    	/* Compare all of both strings: */
    	string s1 = *(string*)arg1;
    	string s2 = *(string*)arg2;
    	int len1 = s1.length();
    	int len2 = s2.length();
    
    	if (len1 < len2)
    		return 1;
    	else if (len1 > len2)
    		return -1;
    
    	return 0;	
    }
    
    void SortWordsByLenDesc(string * pWordList, int count)
    {
    	qsort((void *)pWordList, (size_t)count, sizeof(string), compareLength);
    }
    
    void printWordList(string * pWordList, int count)
    {
    	for (int i = 0; i < count; ++i)
    		cout << i << " - " << pWordList[i] << endl;
   }
   
   string sharedLetters(string s1, string s2)
   {
   	int found[256] = { 0 };
   	string shared = "";
   	
   	for (int i = 0; i < s1.length(); ++i)
   		found[s1[i]] = 1;
   
   	for (int j = 0; j < s2.length(); ++j)
   	{
   		if (found[s2[j]])
   		{
   			shared += s2[j];
   			found[s2[j]] = 0; //only add it once, no need to duplicate		
   		}
   	}
   	return shared;
   }
   
   bool WriteWordIntersectionToFile(const char * pFile, string ** pWordIntersect, int count)
   {
   	ofstream outFile(pFile);
   
   	if (outFile.bad())
   	{
   		cout << "Failed to create: " << pFile << endl;
   		return false;
   	}
   
   	for (int i = 0; i < count; ++i)
   		for (int j = 0; j < count; ++j)
   		{
   			if (i != j)
   			{
   				outFile << i << "," << j << "," << pWordIntersect[i][j] << endl;
   			}
   		}
   	outFile.close();
   	return true;
   }
   
   
   
   
   
   void openFile(void)
   {
   int N = 643;
   //Create an array of that size called wordArray[];
   	string wordArray[N];
   	int sortedArray[N];
   	string wordsIntersect[N][N];
   	//my acumulator to set my array size
   	int x=0;
   	string line; 
   	string getStr, getStr2;
   	
   	fstream inFile;
   //Open a file named wordlist.txt
   	inFile.open ("wordlist.txt");
   
   
   		if (inFile.is_open()) 
   		{
   //Determine the number of words (N) in the file.
  				for(int i=0;i<N;i++)
   				{
   //Read all the words from the file into an array called wordArray[N].
   				getline (inFile,line);
   				wordArray[i] = line;
   				//count each line to find the size
   				x++;
   				//make a paralle array of lengths for sorting
   				sortedArray[i] = line.length();
   				//test-stub to see if gathered correct data
   				//and array size or how many strings in wordlist
   				//cout << x << " " << wordArray[i] 
   				//<< " is " << sortedArray[i] << " long" << endl << endl;
   				}
   				
   		inFile.close();
   		}
   		else cout << "Unable to open file";
   //Sort the array of words by length in descending order
   		DualSort(sortedArray, wordArray, N);
   		
   //test-stub output array to check if they have been sorted successfully
   		//for(int i=0;i<N;i++)
   		//{
   		//cout << wordArray[i] << endl;
   		//}
   		
   //Start at the beginning of the array and examine the word
   //Find all other words in the array that  can intersect the current word
   
   
   
   for(int a=0;a<643;a++){
   char *cstr = new char[wordArray[a].length()];
   strcpy(cstr, wordArray[a].string::c_str());
   
   char *cstr2 = new char[wordArray[a].length()];
   strcpy(cstr2, wordArray[a].string::c_str());
   
   for(int i=0;i<sortedArray[i];i++)
       {
           if(cstr[i]=='-')
           {++i;}
           else 
           {cstr2[i] = cstr[i];}
     
       
       }
   for(int b=0;b<643;b++){   
       char *cstr3 = new char[wordArray[b].length()];
       strcpy(cstr3, wordArray[b].string::c_str());
   
       char *cstr4 = new char[wordArray[b].length()];
       strcpy(cstr4, wordArray[b].string::c_str());
   
   for(int i=0;i<sortedArray[i];i++)
       {
           if(cstr3[i]=='-')
           {++i;}
           else 
           {cstr4[i] = cstr3[i];}
    
      
       }
       string sharedLetters(cstr2, cstr4);
       delete cstr;
   delete cstr2; 
   delete cstr3;
   delete cstr4;  
   }
   
   }   
    
   
   
         
   }
   
   //sort my two parallel arrays in decending order
   	void DualSort(int sortedArray[], string wordArray[], int size)
   	{
   		int startScan, maxIndex;
   		string tempid;
   		double maxValue;
   		
   		for (startScan = 0; startScan < (size - 1); startScan++)
   		{
   			maxIndex = startScan;
   			maxValue = sortedArray[startScan];
   			tempid = wordArray[startScan];
   		for(int index = startScan + 1; index < size; index++)
   		{
   				if (sortedArray[index] > maxValue)
   				{
   					maxValue = sortedArray[index];
   					tempid = wordArray[index];
   					maxIndex = index;
   				}
   			
   		}
   		sortedArray[maxIndex] = sortedArray[startScan];
   		wordArray[maxIndex] = wordArray[startScan];
   		sortedArray[startScan] = maxValue;
   		wordArray[startScan] = tempid;
   		}
   	}
   	
   	
