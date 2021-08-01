#pragma once

#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <algorithm>

class CmdOptionParser
{

public:
	CmdOptionParser(char** l, int s, const std::string& d, std::vector<std::pair<std::string, bool> >& o_key_list)
	{

		arguments_list_size = s;
		arguments_list = l;
		delimiter = d;
		delimiter_size = d.size();

		// options_key_list.resize(o_key_list.size());
		// std::copy(o_key_list.begin(), o_key_list.end(), options_key_list.begin());
		options_key_list = std::move(o_key_list);
	}

	~CmdOptionParser() {}

	int DetectOptions();

	std::vector<std::pair<std::string, std::string> > GetOptions();

private:
	char** arguments_list = nullptr;
	int arguments_list_size;
	std::string delimiter;
	std::vector<std::pair<std::string, bool> > options_key_list;
	std::vector<std::pair<std::string, std::string> > options_list = {};
	size_t delimiter_size;

	bool DetectOptinonKey(char* target, size_t size);

};


