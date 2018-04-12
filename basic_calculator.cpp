/*
    Implement a basic calculator to evaluate a simple expression string.

    The expression string may contain open ( and closing parentheses ),
    the plus + or minus sign -, non-negative integers and empty spaces.

    You may assume that the given expression is always valid.

    Some examples:
    "1 + 1" = 2
    " 2-1 + 2 " = 3
    "(1+(4+5+2)-3)+(6+8)" = 23
*/
#include <vector>
#include <string>

int calculate(std::string s)
{
	std::vector<int> num = {};
	std::vector<char> sign = {};

	for (unsigned int i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case '+': case '-': case '(':
			sign.push_back(s[i]);
			break;
		case ')':
			sign.pop_back();
			if (sign.back() == '+' || sign.back() == '-')
			{
				num[num.size() - 2] += (sign.back() == '+') ? num.back() : -num.back();
				num.pop_back();
				sign.pop_back();
			}
			break;
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			std::string n = "";
			while (i != s.size() && isdigit(s[i]))
			{
				n += s[i];
				i++;
			}
			i--;
			if (sign.size() > 0 && (sign.back() == '+' || sign.back() == '-'))
			{
				num.back() += (sign.back() == '+') ? stoi(n) : -stoi(n);
				sign.pop_back();
			} else
				num.push_back(stoi(n));
			break;
		}
		case ' ':
			break;
		}
	}
	return num[0];
}