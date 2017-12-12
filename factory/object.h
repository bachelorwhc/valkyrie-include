#ifndef _VALKYRIE_OBJECT_FACTORY_H
#define _VALKYRIE_OBJECT_FACTORY_H
#include <memory>
#include "valkyrie/component/component_attacher.h"
#include "valkyrie/scene/light.h"

namespace Valkyrie {
	class ObjectManager;
	namespace Scene {
		class Object;
		class Camera;
	}
}

namespace ValkyrieFactory {
	class ObjectFactory {
	public:
		static int initialize();
		static void close();
		static bool initialized();
		static ObjectFactory& instance() { return *gp_object_factory; }

		virtual ~ObjectFactory();
		
		Valkyrie::Scene::ObjectPtr createObject();
		Valkyrie::Scene::CameraPtr createCamera(float fov, float ratio, float _near, float _far);
        Valkyrie::Scene::LightPtr createLight(Valkyrie::Scene::Light::Type type);

	private:
		static ObjectFactory* gp_object_factory;
		ObjectFactory();

		template<typename T>
		std::shared_ptr<T> processObjectCreationRoutine();
		void acquireID(std::shared_ptr<Valkyrie::Scene::Object>& ptr, Valkyrie::ObjectManager& manager);
		void registerObject(std::shared_ptr<Valkyrie::Scene::Object>& ptr, Valkyrie::ObjectManager& manager);

		Valkyrie::ComponentAttacher m_component_attacher;
	};
}

#endif