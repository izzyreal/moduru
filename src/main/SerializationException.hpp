#pragma once
#ifndef SERIALIZATIONEXCEPTION
#define SERIALIZATIONEXCEPTION

#include <exception>
#include <string>

using namespace std;

class SerializationException : public exception
{
public:
	SerializationException(const string& key, const string& value) {
		msg = "An error occurred while serializing key '" + key + "' and value '" + value + "'";
	}

private:
	string msg;

public:
	const char* what() const throw () override {
		return msg.c_str();
	}
};

#endif