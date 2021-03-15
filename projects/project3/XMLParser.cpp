// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
	elementNameBag = new Bag<std::string>();
	parseStack = new Stack<std::string>();
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
	clear();
}  // end destructor

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
static std::string deleteAttributes(std::string input)
{
	std::string holder = "";
	for (std::size_t i = 0;i < input.length();i++ )
	{
		if (input[i] == ' ')
		break;
		holder = holder + input[i];
		
	}
	return holder;
}

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	std::string holder, inputStr;
	inputStr = inputString;
	int place;
	TokenStruct token;
	int i;
	while (inputStr.length()> 1)
	{
		std::cout<< inputStr<<endl;
		place = inputStr.find_first_not_of(" \t\n");
		inputStr = inputStr.substr(place);
		i = 0;
		if (inputStr[i] == '<')
		{
			if (inputStr[i+1]=='?')
			{
				place = inputStr.find('>');
				if (inputStr[place - 1] != '?'){
					clear();
				return false;}

				holder = inputStr.substr(2,place - 3);
				
				token.tokenType = DECLARATION;
				token.tokenString = holder;
				tokenizedInputVector.push_back(token);
				inputStr.erase(0, place+1);


			}
			else if (inputStr[1]=='/')
			{
				place = inputStr.find('>');
				holder = inputStr.substr(2,place-2);
				if (holder[0] > 47 && holder[0]<=57){
					clear();
					return false;}
					if (holder[0] > 43 && holder[0]<=46){
						clear();
					return false;}
					if ( holder[0]== ' '){
						clear();
					return false;}
					
				for (i = 1; i < holder.length();i++)
				{
					if (holder[i] > 32 && holder[i]<=47){
						clear();
					return false;}
					if (holder[i] > 58 && holder[i]<=64){
						clear();
					return false;}
					if (holder[i] > 90 && holder[i]<=94){
						clear();
					return false;}
					if ( holder[i]== 96){
						clear();
					return false;}
					if (holder[i] > 122 && holder[i]<=126){
						clear();
					return false;}
				}
				token.tokenType = END_TAG;
				
				token.tokenString = holder;
				elementNameBag->add(holder);
				tokenizedInputVector.push_back(token);
				inputStr.erase(0, place +1);
			}
			else
			{
				place = inputStr.find('>');
				if (inputStr[place-1] == '/'){
					holder = inputStr.substr(1,place-2);
					for (i = 1; i < holder.length();i++)
					{
						if (holder[i]=='<'){
							clear();
						return false;}
					}
				
				
				
				if (holder[0] > 47 && holder[0]<=57){
					clear();
					return false;}
					if (holder[0] > 43 && holder[0]<=46){
						clear();
					return false;}
					if ( holder[0]== ' '){
						clear();
					return false;}
					holder = deleteAttributes(holder);
					
				for (i = 1; i < holder.length();i++)
				{
					if (holder[i] > 32 && holder[i]<=47){
						clear();
					return false;}
					if (holder[i] > 58 && holder[i]<=64){
						clear();
					return false;}
					if (holder[i] > 90 && holder[i]<=94){
						clear();
					return false;}
					if ( holder[i]== 96){
						clear();
					return false;}
					if (holder[i] > 122 && holder[i]<=126){
						clear();
					return false;}
				}
				token.tokenType = EMPTY_TAG;
				
				token.tokenString = holder;
				elementNameBag->add(holder);
				tokenizedInputVector.push_back(token);
				inputStr.erase(0, place +1);
				}
				else
				{
					holder = inputStr.substr(1,place-1);
					for (i = 1; i < holder.length();i++)
					{
						if (holder[i]=='<'){
							clear();
						return false;}
					}
					
				
				
				if (holder[0] > 47 && holder[0]<=57){
					clear();
					return false;}
					if (holder[0] > 43 && holder[0]<=46){
						clear();
					return false;}
					if ( holder[0]== ' '){
						clear();
					return false;}
					holder = deleteAttributes(holder);
				for (i = 1; i < holder.length();i++)
				{
					if (holder[i] > 32 && holder[i]<=47){
						clear();
					return false;}
					if (holder[i] > 58 && holder[i]<=64){
						clear();
					return false;}
					if (holder[i] > 90 && holder[i]<=94){
						clear();
					return false;}
					if ( holder[i]== 96){
						clear();
					return false;}
					if (holder[i] > 122 && holder[i]<=126){
						clear();
					return false;}
				}
				
				token.tokenType = START_TAG;
				token.tokenString = holder;
				elementNameBag->add(holder);
				parseStack->push(holder);
				tokenizedInputVector.push_back(token);
				inputStr.erase(0, place +1);
				}
			}
		}
		else
		{
			place = inputStr.find('<');
			holder = inputStr.substr(0,place);
			token.tokenType = CONTENT;
			
				token.tokenString = holder;
				tokenizedInputVector.push_back(token);
				inputStr.erase(0, place);
		}
		i = inputStr.length();
		std::cout << i << endl;
	}
	return true;
}  // end



// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	int size = tokenizedInputVector.size();
	if (tokenizedInputVector[size-1].tokenType != END_TAG)
	return false;
	StringTokenType type1 = DECLARATION;
	std::size_t i = 0;
	while (type1 !=START_TAG)
	{
		type1 = tokenizedInputVector[i].tokenType;
		if (type1 == END_TAG || type1 == CONTENT || type1 == EMPTY_TAG)
		return false;
		i++;
	}
	std::string holder;
	while(!parseStack->isEmpty())
	{
		holder = parseStack->pop();
		size = elementNameBag->getFrequencyOf(holder);
		if ( size%2 !=0)
		return false;
	}
	return true;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	tokenizedInputVector.empty();
	parseStack->clear();
	elementNameBag->clear();
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	return elementNameBag->contains(inputString);
	
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	return elementNameBag->getFrequencyOf(inputString);
}

