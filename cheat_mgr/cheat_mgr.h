#pragma once

#include <functional>
#include <map>
#include <stdexcept>
#include <string>

namespace CheatManager
{
	std::map<const std::string, const std::function<bool()>> Cheats;

	void Register(const std::string, std::function<bool()>);
	bool Call(const std::string);
}