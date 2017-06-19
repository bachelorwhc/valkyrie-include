#ifndef _VALKYRIE_SCENE_CAMERA_H
#define _VALKYRIE_SCENE_CAMERA_H
#include "valkyrie/scene/object.h"
#include "valkyrie/component/camera.h"
namespace Valkyrie {
	namespace Scene {
		class Camera : public Object {
		public:
			Camera();
			virtual ~Camera();

			virtual void start();
			virtual void update();
			virtual ValkyrieComponent::ComponentPtr getComponentPtr(const std::string& component_name);
			
			ValkyrieComponent::Camera& feature() { return *m_camera_component_ptr; }

		private:
			friend class Valkyrie::ComponentAttacher;
			ValkyrieComponent::CameraComponentPtr m_camera_component_ptr;
		};
	}
}

#endif