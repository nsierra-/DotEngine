#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>
# include <fstream>

namespace Dot
{
	class		Logger
	{
	public:

		enum LogLevel
		{
			Debug,
			Warning,
			Error,
			Info
		};

		static void	init(const std::string & = "log.log", LogLevel level = Warning);
		static void	debug(const std::string & msg);
		static void	error(const std::string & msg);
		static void	warning(const std::string & msg);
		static void	info(const std::string & msg);
		static void log(const std::string &, const std::string &, LogLevel);

	private:
		Logger();

		static bool				_active;
		static LogLevel			_level;
		static std::ofstream	_debugFile;
	};
}


#endif
