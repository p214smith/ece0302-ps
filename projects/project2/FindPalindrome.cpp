#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	locale loc;
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i],loc);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	string teststring = "";
	vector<string> newCurrentStringVector,newCandidateStringVector;
	bool testbool = false;
	
	for (int j = 0; j< currentStringVector.size();j++)
	newCurrentStringVector.push_back(currentStringVector[j]);
	
	if (newCurrentStringVector.empty())
	{
		
	if (cutTest1(candidateStringVector))
	{
		vector<string> left, right;
		int canSize = candidateStringVector.size();
		if (canSize ==1)
		{
			teststring = teststring + candidateStringVector[0];
			testbool = isPalindrome(teststring);
			if (testbool)
			{
				m_totalPalindromes++;
				m_Palindromes.push_back(candidateStringVector);
			}

		}
		else{
			for (int i =0 ; i <canSize/2;i++)
			{
				left.push_back(candidateStringVector[i]);
			}
			for (int i = canSize/2;i<canSize;i++)
			right.push_back(candidateStringVector[i]);
		if (cutTest2(left,right))
		{
			for (int i =0; i<candidateStringVector.size();i++)
			teststring = teststring + candidateStringVector[i];
			testbool = isPalindrome(teststring);
			if (testbool)
			{
				m_totalPalindromes++;
				m_Palindromes.push_back(candidateStringVector);
			}
		}}
		
		return;}
	
	}else{
	for (int n = 0; n< candidateStringVector.size();n++)
	newCandidateStringVector.push_back(candidateStringVector[n]);
	for (int m = 0; m<newCurrentStringVector.size();m++)
		{
			newCandidateStringVector.push_back(newCurrentStringVector[0]);
			
		vector<string>::iterator it;
		string hold = newCurrentStringVector[0];
		it = newCurrentStringVector.begin();
		newCurrentStringVector.erase(it);
		
	
		recursiveFindPalindromes(newCandidateStringVector,newCurrentStringVector);
		newCurrentStringVector.push_back(hold);
		
		}


}}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	m_totalPalindromes = 0;

}

FindPalindrome::~FindPalindrome()
{
	clear();
}

int FindPalindrome::number() const
{
	return m_totalPalindromes;
}

void FindPalindrome::clear()
{
	m_posPalindrome.clear();
	m_Palindromes.clear();
	m_totalPalindromes = 0;
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	std::size_t i;
	std::string test1;
	convertToLowerCase(test1);
	int occurences=0;
	for  (i= 0; i<m_posPalindrome.size();i++)
	test1 = test1 + stringVector[i];
	if (test1.size()%2 == 0)
	{
		for (i = 0; i<test1.size()/2;i++ )
		{
			for (std::size_t j = 0; j<test1.size();j++)
			{
				if (test1[i]==test1[j])
				occurences++;
			}
			if (occurences%2==1)
			return false;
			occurences = 0;
		}
	}
	else
	{
			
		for (i = 0; i<test1.size()/2;i++ )
		{
			for (std::size_t j = 0; j<test1.size();j++)
			{
				if (test1[i]==test1[j])
				occurences++;
			}
			if (occurences%2==1)
			return false;
			occurences = 0;
		}

	}
	return true;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	std::string left;
	std::string right;
	int i,j,k,l, test1;
	k = stringVector1.size();
	for (i = 0; i<k;i++)
	left = left + stringVector1[i];
	l = stringVector2.size();
	for (i = 0; i<l; i++)
	right = right + stringVector2[i];
	convertToLowerCase(left);
	convertToLowerCase(right);
	bool test = false;
	k = left.size();
	l = right.size();
	test1 = 0;
	for (i = 0; i<k;i++)
	{
		test = false;
		for (j = 0; j<l;j++)
		{
			if (left[i]==right[j])
			test = true;
		}
		if (test == true)
		test1++;
	}
	if (test1 == k)
	return true;
	else
	return false;
}

bool FindPalindrome::add(const string & value)
{
	string hold = value;
	string hold1;
	convertToLowerCase(hold);
	for (size_t i = 0; i < hold.size();i++){
		if (hold[i] < 'a' || hold[i] > 'z')
		return false;
	}
	if (m_posPalindrome.size() > 0){
			for (size_t j = 0; j < m_posPalindrome.size();j++)
			{
				hold1 = m_posPalindrome[j];
				convertToLowerCase(hold1);
				if (hold1.compare(hold)==1)
				return false;
			}
		}

	
	m_posPalindrome.push_back(value);
	vector<string> candidateString;
	m_totalPalindromes = 0;
	m_Palindromes.clear();
	recursiveFindPalindromes(candidateString,m_posPalindrome);

	return true; 
	
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	string hold, hold1;
	for (size_t i = 0; i < stringVector.size();i++)
	{
		hold = stringVector[i];
		convertToLowerCase(hold);
		for ( size_t k = 0; k < hold.size();k++){
			if (hold[k] < 'a' || hold[k] > 'z')
			return false;
		}
		if (m_posPalindrome.size() > 0){
			for (size_t j = 0; j < m_posPalindrome.size();j++)
			{
				hold1 = m_posPalindrome[j];
				convertToLowerCase(hold1);
				if (hold1.compare(hold)==1)
				return false;
			}
		}
	}
	for (size_t i = 0; i < stringVector.size();i++)
	m_posPalindrome.push_back(stringVector[i]);
	vector<string> candidateString;
	m_totalPalindromes = 0;
	m_Palindromes.clear();
	recursiveFindPalindromes(candidateString,m_posPalindrome);

	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	return m_Palindromes;
}

