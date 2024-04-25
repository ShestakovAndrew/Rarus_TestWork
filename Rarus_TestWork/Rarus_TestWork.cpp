#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <iterator>

std::string GetMostFrequentNumbers(std::string const& sequence)
{
	std::stringstream ss(sequence);
	std::string numberStr;
	std::unordered_map<size_t, size_t> frequencyMap;
	while (ss >> numberStr)
	{
		frequencyMap[std::stoull(numberStr)]++;
	}

	size_t maxFrequency = 0;
	for (const auto& pair: frequencyMap) 
	{
		maxFrequency = std::max(maxFrequency, pair.second);
	}
	
	std::vector<size_t> mostFrequentNumbers;
	for (const auto& pair: frequencyMap) 
	{
		if (pair.second == maxFrequency) 
		{
			mostFrequentNumbers.push_back(pair.first);
		}
	}

	if (mostFrequentNumbers.size() == 1) 
	{
		return std::to_string(mostFrequentNumbers[0]);
	}
	else 
	{
		std::sort(mostFrequentNumbers.begin(), mostFrequentNumbers.end());

		std::stringstream ss;

		size_t last = mostFrequentNumbers.size() - 1;
		for (size_t i = 0; i < mostFrequentNumbers.size(); i++)
		{
			ss << mostFrequentNumbers[i];
			if (i != last)
			{
				ss << " ";
			}
		}
		return ss.str();
	}
}

int main()
{
	std::vector<std::pair<std::string, std::string>> TESTS =
	{
		{"5 12 76 34 2 76 5 3 5 2 8 5", "5"},
		{"7 13 11 34 2 12 7 34", "7 34"},
		{"7 13 76 34 2 12 7 34 7 13 34", "7 34"}
	};

	for (auto& testCase : TESTS)
	{
		assert(GetMostFrequentNumbers(testCase.first) == testCase.second);
	}
}
