#pragma once
#include <observer/Observer.hpp>
#include <string>
#include <vector>
#include <memory>
#include <thirdp/any.hpp>

namespace moduru::observer
{
	class Observable
	{

	public:
		virtual void notifyObservers();
		virtual void notifyObservers(nonstd::any a);
		void addObserver(moduru::observer::Observer* o);
		void deleteObservers();
		void deleteObserver(moduru::observer::Observer* o);
		int countObservers();

	private:
		std::vector<moduru::observer::Observer*> observers;

	};
}
