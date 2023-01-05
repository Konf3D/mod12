#include <iostream>
#include <string>
#include <array>

bool isKPeriodic(const std::string&,int);

int main()
{
	std::array<std::string, 5> strings = {
		"foobarfoobar",
		"foobarfoobarb",
		"foobarfoobarbcd",
		"foobarfoobarbcdfoobar",
		"abcabcabcabc"
	};
	
	for (auto& element : strings)
	{
		for (int i = 0; i < element.size(); ++i)
		{
			std::cout << "String = " << element << ", K = " << i << " isKperiodic = " << (isKPeriodic(element,i) ? "yes" : "no") << '\n';
		}
	}
}

bool isKPeriodic(const std::string& string, int k)
{

	if (k == 1)
		return true;
	int stringSize = string.size();
	// if string is empty
	// if k is negative or zero
	// if k is not dividible
	// if not enough symbols
	if (stringSize == 0 ||  k <= 0 || stringSize % k != 0 || k > stringSize/2)
		return false;

	int i = k;
	while (i < stringSize)
	{
		if ( string.substr(0, k) != string.substr(i, k) )
			return false;
		i += i;
	}
	return true;
}

