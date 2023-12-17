#pragma once
#include "parallel_hashmap/phmap.h"

#include <string>

using namespace std;
using phmap::flat_hash_map;

namespace shader
{
	extern flat_hash_map<string, string> ShaderTypeDic;
}

