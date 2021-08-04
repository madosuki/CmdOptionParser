#include "framework.h"
#include "pch.h"

#include "CmdOptionParser.h"

std::vector<std::pair<std::string, std::string> > CmdOptionParser::GetOptions()
{

	return options_list;
}

bool CmdOptionParser::DetectOptinonKey(char* target, size_t size)
{
	if (size <= option_prefix_size)
	{
		return false;
	}

	int count = 0;
	for (size_t i = 0; i < option_prefix_size; ++i)
	{
		if (target[i] == option_prefix[i])
		{
			++count;
		}
	}

	if (count != option_prefix_size)
	{
		return false;
	}

	return true;
}

int CmdOptionParser::DetectOptions()
{

	if (arguments_list_size < 1 || !isAvailableKey)
	{
		return -1;
	}


	std::vector<std::pair<std::string, std::string> > result = {};

	int count = 0;
	bool isDetectOptionKey = false;
	bool isValue = false;


	for (int i = 0; i < arguments_list_size; ++i)
	{
		size_t s_size = strnlen_s(arguments_list[i], sizeof(size_t));


		if (isDetectOptionKey && !isValue)
		{
			if (!DetectOptinonKey(arguments_list[i], s_size))
			{
				isValue = true;
			}

		}

		if (!isDetectOptionKey && !isValue)
		{
			isDetectOptionKey = DetectOptinonKey(arguments_list[i], s_size);

			if (isDetectOptionKey)
			{
				size_t tmp_size = s_size - 1;
				auto tmp = std::make_unique<char[]>(tmp_size);
				int err = memmove_s(tmp.get(), tmp_size, arguments_list[i] + option_prefix_size, tmp_size);

				auto iter = std::find_if(options_key_list.begin(), options_key_list.end(), [&](const std::pair<std::string, bool>& x) { return x.first == tmp.get(); });

				if (iter != options_key_list.end() && iter->first == tmp.get())
				{
					if (iter->second)
					{
						isDetectOptionKey = false;
					}
					result.push_back(std::make_pair(iter->first, ""));
				}
				else
				{
					isDetectOptionKey = false;
				}
			}

		}

		if (isDetectOptionKey && isValue)
		{
			result[count].second = std::string(arguments_list[i]);
			++count;
			isDetectOptionKey = false;
			isValue = false;
		}

	}

	if (count > 0)
	{
		options_list = std::move(result);
	}

	return count;
}

