#include <iostream>
#include <string>
//#include <algorithm>
#include <stack>

std::string getStr()
{
	std::string s;
	std::cout << "Enter your string" << std::endl;
	std::cin >> s;
	return s;
}

bool isPair(char opening, char closing)
{
	if (opening == '{' && closing == '}') return true;
	else if (opening == '[' && closing == ']') return true;
	else if (opening == '(' && closing == ')') return true;
	return false;
}

bool isBalanced(const std::string& str)
{
	std::stack<char> s;
	int strSize = str.size();
	for (int i = 0; i < strSize; i++)
	{
		if (str[i] == '{' || str[i] == '[' || str[i] == '(')
		{
			s.push(str[i]);
		}
		else if (str[i] == '}' || str[i] == ']' || str[i] == ')')
		{
			if (s.empty() || !isPair(s.top(), str[i]))
			{
				return false;
			}
			else
			{
				s.pop();
			}
		}
	}
	return s.empty() ? true : false;
}


int main() {
	std::string s = getStr();
	if (isBalanced(s))
	{
		std::cout << "balanced" << std::endl;
	}
	else
	{
		std::cout << "unbalanced" << std::endl;

	}
}