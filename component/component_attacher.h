#ifndef _VALKYRIE_COMPONENT_ATTACHER_H
#define _VALKYRIE_COMPONENT_ATTACHER_H
#include <memory>
#include <mutex>

namespace ValkyrieComponent {
	class Component;
	class Camera;
	using ComponentPtr = std::shared_ptr<Component>;
	using CameraComponentPtr = std::shared_ptr<Camera>;
}

namespace Valkyrie {
	namespace Scene {
		class Object;
		class Camera;
		using ObjectPtr = std::shared_ptr<Object>;
		using CameraPtr = std::shared_ptr<Camera>;
	}

	class ComponentAttacher {
	public:
		ComponentAttacher();
		virtual ~ComponentAttacher();

		void attachComponent(const Scene::ObjectPtr& object_ptr, const ValkyrieComponent::ComponentPtr& component_ptr);
		void attachComponent(const Scene::CameraPtr& camera_ptr, const ValkyrieComponent::CameraComponentPtr& component_ptr);
	private:
		std::mutex m_attach_component;
	};
}

#endif