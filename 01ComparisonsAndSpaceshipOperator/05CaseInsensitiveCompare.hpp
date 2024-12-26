#pragma once


#include <set>
#include <string>

struct CaseInsensitiveCompare
{
public:
	bool operator()(const std::string& lhs, const std::string& rhs)
	{
		//return std::strcmp(lhs.c_str(), rhs.c_str()) < 0;
	}
};

void for_main()
{
	std::set<std::string, CaseInsensitiveCompare> case_insensitive_set{};
	case_insensitive_set.insert("Hello");
	case_insensitive_set.insert("hELLO");
}