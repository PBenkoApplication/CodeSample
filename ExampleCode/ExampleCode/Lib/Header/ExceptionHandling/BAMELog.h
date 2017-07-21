#ifndef BAMELOGGING_H
#define BAMELOGGING_H

#if (defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__))


#define BAMESUCCESS(message) { _BAMESuccess(message, __FILE__ , __LINE__); }
#define BAMESUCCESSIF(cond, message) { _BAMESuccess(cond, message, __FILE__ , __LINE__); }

#define BAMEINFO(message) { _BAMEInfo(message, __FILE__ , __LINE__); }
#define BAMEINFOIF(cond, message) { _BAMEInfo(cond, message, __FILE__ , __LINE__); }

#define BAMEWARN(message) { _BAMEWarn(message, __FILE__ , __LINE__); }
#define BAMEWARNIF(cond, message) { _BAMEWarn(cond, message, __FILE__ , __LINE__); }

#define BAMEERROR(message) { _BAMEError(message, __FILE__ , __LINE__); }
#define BAMEERRORIF(cond, message) { _BAMEError(cond, message, __FILE__ , __LINE__); }

#define BAMEFATAL(message) { _BAMEFatal(message, __FILE__ , __LINE__); }
#define BAMEFATALIF(cond, message) { _BAMEFatal(cond, message, __FILE__ , __LINE__); }


#include <string>
#include <iostream>
#include <stdio.h>
#include <windows.h>

namespace BAME
{
	inline void _BAMELog(std::string const& level, int color, std::string const& message, std::string const& file, int line)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		std::string namecpp = file.substr(file.find_last_of("\\") + 1);
		int index = static_cast<int>(namecpp.find_last_of("."));
		std::string name = namecpp.substr(0, index);
		SetConsoleTextAttribute(hConsole, color);
		std::cout << level << " [" << name << " @ " << line << "] " << message << std::endl;
		SetConsoleTextAttribute(hConsole, 7);
	}

	// SUCCESS
	inline void _BAMESuccess(std::string const& message, std::string const& file, int line)
	{
		_BAMELog("SUCCESS:", 10, message, file, line);
	}

	inline void _BAMESuccess(bool cond, std::string const& message, std::string const& file, int line)
	{
		if (cond)
		{
			_BAMESuccess(message, file, line);
		}
	}

	// INFO
	inline void _BAMEInfo(std::string const& message, std::string const& file, int line)
	{
		_BAMELog("INFO:   ", 7, message, file, line);
	}

	inline void _BAMEInfo(bool cond, std::string const& message, std::string const& file, int line)
	{
		if (cond)
		{
			_BAMEInfo(message, file, line);
		}
	}

	// WARNING
	inline void _BAMEWarn(std::string const& message, std::string const& file, int line)
	{
		_BAMELog("WARNING:", 14, message, file, line);
	}

	inline void _BAMEWarn(bool cond, std::string const& message, std::string const& file, int line)
	{
		if (cond)
		{
			_BAMEWarn(message, file, line);
		}
	}

	// ERROR
	inline void _BAMEError(std::string const& message, std::string const& file, int line)
	{
		_BAMELog("ERROR:  ", 12, message, file, line);
	}

	inline void _BAMEError(bool cond, std::string const& message, std::string const& file, int line)
	{
		if (cond)
		{
			_BAMEError(message, file, line);
		}
	}

	// FATAL
	inline void _BAMEFatal(std::string const& message, std::string const& file, int line)
	{
		_BAMELog("FATAL:  ", 79, message, file, line);
	}

	inline void _BAMEFatal(bool cond, std::string const& message, std::string const& file, int line)
	{
		if (cond)
		{
			_BAMEFatal(message, file, line);
		}
	}
}

#endif
#endif

//HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//for (int k = 1; k < 255; k++)
//{
//	// pick the colorattribute k you want
//	SetConsoleTextAttribute(hConsole, k);
//	std::cout << k << " I want to be nice today!" << std::endl;
//}
