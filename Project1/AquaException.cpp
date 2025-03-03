#include "AquaException.h"
#include <sstream>

AquaException::AquaException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* AquaException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* AquaException::GetType() const noexcept
{
	return "Aqua Exception";
}

int AquaException::GetLine() const noexcept
{
	return line;
}

const std::string& AquaException::GetFile() const noexcept
{
	return file;
}

std::string AquaException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}




