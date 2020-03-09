#pragma once
#include <string>
#include <thirdp/any.hpp>>

namespace moduru {

	namespace observer {

		class Observable;

		class Observer {

		public:
            virtual void update(nonstd::any) {}
			virtual void update(Observable* obs, nonstd::any arg) {}

		public:
			virtual ~Observer() {}
		};

	}
}
