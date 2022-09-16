#pragma once
#include <string>
#include <vector>
#include <utility>

namespace mdb
{
	void init();
	void unload();

	std::string find_text(int category, int index);
	std::vector<std::pair<int, std::string>> get_uma_all();
}
