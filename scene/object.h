#ifndef _VALKYRIE_SCENE_OBJECT_H
#define _VALKYRIE_SCENE_OBJECT_H
#include <vector>
#include <unordered_map>
#include <memory>
#include "valkyrie/scene/transform.h"
#include "valkyrie/utility/base_unit.h"

namespace ValkyrieComponent {
	class Component;
	using ComponentPtr = std::shared_ptr<Component>;
}

namespace Valkyrie {
	class ComponentAttacher;

	namespace Scene {
		class Object : public Base {
		public:
			Object();
			virtual ~Object();

			virtual void start();
			virtual void update();
			
			Transform transform;
		private:
			friend class Valkyrie::ComponentAttacher;
			std::unordered_map<std::string, unsigned int> m_component_index;
			std::vector<ValkyrieComponent::ComponentPtr> m_component_ptrs;
		};
		using ObjectPtr = std::shared_ptr<Object>;
	}
}

#endif