#include "Logger.hpp"
#include <sstream>


namespace Dot
{
	bool				Logger::_active = false;
	Logger::LogLevel	Logger::_level = Logger::Warning;
	std::ofstream		Logger::_debugFile = std::ofstream();

	void	Logger::init(const std::string & filePath, LogLevel level)
	{
		_active = true;
		_debugFile.open(filePath);
		_level = level;
	}

	void 	Logger::log(const std::string & title, const std::string & msg, LogLevel l)
	{
		if (l < _level || !_active)
			return ;

		std::string	out;
		out += "[" + title + "] ";

		if (title.size() < 10)
			out.append(10 - title.size(), ' ');
		out += msg + "\n";
		_debugFile << out;
	}

	void	Logger::debug(const std::string & msg) { log("DEBUG", msg, Debug); }
	void	Logger::error(const std::string & msg) { log("ERROR", msg, Error); }
	void	Logger::warning(const std::string & msg) { log("WARNING", msg, Warning); }
	void	Logger::info(const std::string & msg) { log("INFO", msg, Info); }
}
