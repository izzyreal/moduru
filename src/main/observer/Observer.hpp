#pragma once
#include <string>
#include <any>

namespace moduru {

	namespace observer {

		class Observable;

		class Observer {

		public:
            virtual void update(std::any) {}
			virtual void update(Observable* obs, std::any arg) {}

		public:
			virtual ~Observer() {}
		};

	}
}
