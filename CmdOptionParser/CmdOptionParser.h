#pragma once

#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <algorithm>

class CmdOptionParser
{

public:
	CmdOptionParser(char** argv, int argc, const std::string& prefix, std::vector<std::pair<std::string, bool> >& o_key_list)
	{

		arguments_list_size = argc;
		arguments_list = argv;
		option_prefix = prefix;
		option_prefix_size = prefix.size();

		std::vector<std::pair<std::string, bool> > tmp(o_key_list.size());
		auto result = std::copy(o_key_list.begin(), o_key_list.end(), tmp.begin());
		if(result == o_key_list.end())
		{
			options_key_list = tmp;

			if (option_prefix_size > 0 && argc > 0)
			{
				isAvailableKey = true;
			}
		}
	}

	~CmdOptionParser() {}

	int DetectOptions();

	bool IsAvailableRun() { return isAvailableKey;  }

	std::vector<std::pair<std::string, std::string> > GetOptions();

private:
	char** arguments_list = nullptr;
	int arguments_list_size;
	std::string option_prefix;
	size_t option_prefix_size;
	std::vector<std::pair<std::string, bool> > options_key_list;
	std::vector<std::pair<std::string, std::string> > options_list = {};
	bool isAvailableKey = false;

	bool DetectOptinonKey(char* target, size_t size);

};


