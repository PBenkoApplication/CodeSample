#ifndef BAMEEXCEPTIONHANDLER
#define BAMEEXCEPTIONHANDLER
#include "BAMEException.h"

namespace BAME
{
	namespace BAMEExceptionHandler
	{
#define SAFE_CALL(expr)					\
    try {                               \
        expr;                 \
    }                                   \
    catch (const BAMEException& ex) {	\
         BAMEExceptionHandler:: BAMEExceptionHandler::handleException(ex, __LINE__ , __FILE__);  \
  } \


		class BAMEExceptionHandler
		{
		public:
			static void handleException(BAMEException const& exception, int line, const char* file)
			{
				switch (exception.whatType())
				{
				case BAMEException::ExceptionType::NOT_IMPLEMENTED_EXCEPTION:
					{
						std::cout << std::endl << "Not implemented Exception: " << std::endl << "File: " << file << std::endl << "Line: " << line << std::endl;
						break;
					}
				case BAMEException::ExceptionType::CUSTOM_EXCEPTION:
					{
						std::cout << std::endl << "Custom Exception: " << std::endl << "Message: " << exception.whatMessage() << std::endl << "File: " << file << std::endl << "Line: " << line << std::endl;

						break;
					}
				default: break;
				}
				std::cin.get();
				exit(EXIT_FAILURE);
			}
		};

		/*template <typename ReturnT, typename ClassT>
		ReturnT SAFE_CALL(ClassT* obj, ReturnT(ClassT::*func)())
		{
			try {
				return (obj->*func)();
			}
			catch (const BAMEException& ex) {
				handleException(ex);
			}

			return ReturnT();
		}

		void handleException(BAMEException const& exeption)
		{
			switch(exception)
		}*/
	};
};
#endif
