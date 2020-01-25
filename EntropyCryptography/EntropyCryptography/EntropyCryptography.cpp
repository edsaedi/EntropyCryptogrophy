#include <iostream>
#include <string>

std::string Compressing(std::string string)
{
	std::string result = "";
	int count{};
	char standard = string[0];
	for (size_t i = 0; i < string.size(); i++)
	{
		if (string[i] == standard)
		{
			count++;
		}
		else
		{
			result += standard;
			result += std::to_string(count);
			standard = string[i];
			count = 1;
		}
	}
	result += standard;
	result += std::to_string(count);
	return result;
}

std::string Uncompressing(std::string string)
{
	std::string result;
	for (size_t i = 0; i < string.size(); i += 2)
	{
		int count = string[i + 1] - '0';
		char character = string[i];
		for (size_t j = 0; j < count; j++)
		{
			result += character;
		}
	}
	return result;
}

int main()
{
	std::cout << "Enter in a string to compress: \n";
	std::string comp;
	std::cin >> comp;
	std::string compressed = Compressing(comp);
	std::cout << compressed << "\n";
	std::cout << Uncompressing(compressed);
}