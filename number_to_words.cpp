/*
	Convert a integer to its english words representation.

	For example:
		0 		-> "Zero"
		123 	-> "One Hundred Twenty Three"
		12345 	-> "Twelve Thousand Three Hundred Forty Five"
		1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
		-123	-> "Negative One Hundred Twenty Three"
*/
#include <string>

std::string numberToWords(int num)
{
	if (num == 0)
		return "Zero";
	if (num < 0)
		return "Negative " + numberToWords((unsigned int)abs(num));

	switch (num)
	{
		case 1: return "One";
		case 2: return "Two";
		case 3: return "Three";
		case 4: return "Four";
		case 5: return "Five";
		case 6: return "Six";
		case 7: return "Seven";
		case 8: return "Eight";
		case 9: return "Nine";

		case 10: return "Ten";
		case 11: return "Eleven";
		case 12: return "Twelve";
		case 13: return "Thirteen";
		case 14: return "Fourteen";
		case 15: return "Fifteen";
		case 16: return "Sixteen";
		case 17: return "Seventeen";
		case 18: return "Eighteen";
		case 19: return "Nineteen";

		case 20: return "Twenty";
		case 30: return "Thirty";
		case 40: return "Forty";
		case 50: return "Fifty";
		case 60: return "Sixty";
		case 70: return "Seventy";
		case 80: return "Eighty";
		case 90: return "Ninety";
	}

	int base = 1000000000;
	int cnt = num / base;
	int rest = num % base;
	if (cnt)
		return numberToWords(cnt) += (rest) ?
		                             " Billion " + numberToWords(rest) :
		                             " Billion";
	base = 1000000;
	cnt = num / base;
	rest = num % base;
	if (cnt)
		return numberToWords(cnt) += (rest) ?
		                             " Million " + numberToWords(rest) :
		                             " Million";
	base = 1000;
	cnt = num / base;
	rest = num % base;
	if (cnt)
		return numberToWords(cnt) += (rest) ?
		                             " Thousand " + numberToWords(rest) :
		                             " Thousand";
	base = 100;
	cnt = num / base;
	rest = num % base;
	if (cnt)
		return numberToWords(cnt) += (rest) ?
		                             " Hundred " + numberToWords(rest) :
		                             " Hundred";
	base = 10;
	return numberToWords((num / base) * base) + " " + numberToWords(num % base);
}