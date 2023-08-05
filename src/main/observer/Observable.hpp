#pragma once
#include <observer/Observer.hpp>
#include <string>
#include <vector>
#include <memory>

namespace moduru::observer
{
	class Observable
	{

	public:
		virtual void notifyObservers();
		virtual void notifyObservers(Message message);
		void addObserver(moduru::observer::Observer* o);
        void deleteObserver(moduru::observer::Observer* o);

    private:
		std::vector<moduru::observer::Observer*> observers;

	};
}
