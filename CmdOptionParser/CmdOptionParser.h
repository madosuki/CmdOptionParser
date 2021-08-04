#pragma once

#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <algorithm>

class CmdOptionParser
{

public:
	std::vector<std::pair<std::string, std::string> > GetOptions();
	int DetectOptions();
	bool IsAvailableRun();

	CmdOptionParser(char** argv, int argc, const std::string& prefix, std::vector<std::pair<std::string, bool> > o_key_list);

	~CmdOptionParser();

private:
	char** arguments_list = nullptr;
	int arguments_list_size;
	std::string option_prefix;
	size_t option_prefix_size;
	std::vector<std::pair<std::string, bool> > options_key_list = {};
	std::vector<std::pair<std::string, std::string> > options_list = {};
	bool isAvailableRun = false;

	bool DetectOptinonKey(char* target, size_t size);


};


