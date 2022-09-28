#pragma once
#include <string>
#include <vector>
#include <utility>

#include "parallel_hashmap/phmap.h"

using phmap::flat_hash_map;

namespace mdb
{
	void init();
	void unload();

	std::string find_text(int category, int index);
	std::vector<std::pair<int, std::string>> get_uma_all();
	flat_hash_map<int, std::vector<int>> get_story_all(flat_hash_map<int, std::pair<bool, bool>>selected_uma_id);
	std::vector<int> get_story(int id);
}
