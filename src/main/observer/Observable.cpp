#include <observer/Observable.hpp>

using namespace moduru::observer;
using namespace std;

int Observable::countObservers()
{
	return (int)(observers.size());
}

void Observable::notifyObservers()
{
	notifyObservers(nullptr);
}

void Observable::notifyObservers(nonstd::any arg)
{
	for (auto& a : observers)
	{
		a->update(this, arg);
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
	// This check adds a bit of breathing space to application teardown.
	if (this == nullptr)
	{
		return;
	}

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

void Observable::deleteObservers()
{
	observers.clear();
}
