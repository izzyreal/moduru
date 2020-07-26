#pragma once
#ifndef SERIALIZATIONEXCEPTION
#define SERIALIZATIONEXCEPTION

#include <exception>
#include <string>

class SerializationException
	: public std::exception
{
public:
	SerializationException(const std::string& key, const std::string& value)
	{
		msg = "An error occurred while serializing key '" + key + "' and value '" + value + "'";
	}

private:
	std::string msg;

public:
	const char* what() const throw () override
	{
		return msg.c_str();
	}
};

#endif