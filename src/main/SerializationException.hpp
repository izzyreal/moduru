#pragma once
#ifndef SERIALIZATIONEXCEPTION
#define SERIALIZATIONEXCEPTION

#include <exception>
#include <string>

using namespace std;

class SerializationException : public exception
{
public:
	SerializationException(const string& _key, const string& _value) : key(_key), value(_value) {}

private:
	const string key, value;

public:
	virtual char const * what() const { return ("An error occurred while serializing key '%s' and value '%s'.", key, value).c_str(); }
};

#endif