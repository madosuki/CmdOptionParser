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

		options_key_list = std::move(o_key_list);
	}

	~CmdOptionParser() {}

	int DetectOptions();

	std::vector<std::pair<std::string, std::string> > GetOptions();

private:
	char** arguments_list = nullptr;
	int arguments_list_size;
	std::string option_prefix;
	size_t option_prefix_size;
	std::vector<std::pair<std::string, bool> > options_key_list;
	std::vector<std::pair<std::string, std::string> > options_list = {};

	bool DetectOptinonKey(char* target, size_t size);

};


