#include <observer/Observable.hpp>

using namespace moduru::observer;

void Observable::notifyObservers()
{
	notifyObservers(nullptr);
}

void Observable::notifyObservers(Message message)
{
	for (auto& a : observers)
	{
		a->update(this, message);
	}
}

void Observable::addObserver(moduru::observer::Observer* o)
{
	for (auto& obs : observers)
	{
		if (obs == o)
		{
			return;
		}
	}

	observers.push_back(o);
}

void Observable::deleteObserver(moduru::observer::Observer* o) {
	int counter = 0;
	
	for (auto& o1 : observers)
	{
		if (o1 == o)
		{
			observers.erase(observers.begin() + counter);
			break;
		}
		counter++;
	}
}
