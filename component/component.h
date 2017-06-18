#ifndef _VALKYRIECOMPONENT_COMPONENT_H
#define _VALKYRIECOMPONENT_COMPONENT_H
#include <memory>
#include <string>
#include <atomic>
#include <mutex>
#include "valkyrie/utility/base_unit.h"
#define GET_COMPONENT_NAME(component) \
public: \
virtual std::string getName() { return get ## component ## ComponentName(); } \
static std::string get ## component ## ComponentName() { return #component; }

namespace Valkyrie {
	namespace Scene {
		class Object;
	}
}

namespace ValkyrieComponent {
	class Component : public Valkyrie::Base {
		GET_COMPONENT_NAME(ValkyrieComponent)

	public:
		Component() : m_set_enabled() {};
		virtual ~Component() {};

		std::weak_ptr<Valkyrie::Scene::Object> objectWeakPtr;
		void enable() {
			std::lock_guard<std::mutex> lock(m_set_enabled);
			m_enabled = true;
		}
		void disable() {
			std::lock_guard<std::mutex> lock(m_set_enabled);
			m_enabled = false;
		}
		bool isEnabled() { return m_enabled; }

	private:
		bool m_enabled = true;
		std::mutex m_set_enabled;
	};

	using ComponentPtr = std::shared_ptr<Component>;
}

#endif