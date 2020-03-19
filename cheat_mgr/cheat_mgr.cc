#include "cheat_mgr.h"

namespace CheatManager
{
	/// <summary>
	/// Add the cheat to our map.
	/// </summary>
	/// <param name="CheatName">The name of the cheat. This will be used in commands/menus.</param>
	/// <param name="Function">The cheat's function. Will be called everytime the cheat is used.</param>
	void CheatManager::Register(
		const std::string CheatName, 
		const std::function<bool()> Function)
	{
		const auto Cheat = std::pair<const std::string, const std::function<bool()>>(CheatName, Function);

		Cheats.insert(Cheat);
	}

	/// <summary>
	/// Search for the cheat and call it.
	/// </summary>
	/// <param name="CheatName">The cheat to call.</param>
	/// <returns>False if cheat not found. Otherwise what function returns.</returns>
	bool CheatManager::Call(
		const std::string CheatName)
	{
		try
		{
			const auto Function = Cheats.at(CheatName);
			return Function();
		}
		catch (const std::out_of_range)
		{
			return false;
		}
	}
}