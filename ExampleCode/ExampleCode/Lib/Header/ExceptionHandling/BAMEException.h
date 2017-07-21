#ifndef BAMEEXEPTION_H
#define BAMEEXEPTION_H

namespace BAME
{
	class BAMEException
	{
	public:

		enum class ExceptionType
		{
			NOT_IMPLEMENTED_EXCEPTION,
			CUSTOM_EXCEPTION
		};

		BAMEException(std::string const& s)
		{
			type = ExceptionType::CUSTOM_EXCEPTION;
			this->s = s;
		}

		BAMEException(ExceptionType exceptionType)
		{
			type = exceptionType;
		}

		virtual ~BAMEException() throw()
		{
		}

		ExceptionType whatType() const
		{
			return type;
		}

		std::string const& whatMessage() const
		{
			return s;
		}


	private:
		BAMEException();
		std::string s;
		ExceptionType type;
	};
}
#endif
