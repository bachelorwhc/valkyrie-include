#ifndef _VALKYRIE_SCENE_LIGHT_H
#define _VALKYRIE_SCENE_LIGHT_H
#include <glm/glm.hpp>
#include "valkyrie/scene/object.h"

namespace Valkyrie {
	namespace Scene {
		class Light : public Object {
		public:
			enum Type {
				POSITION,
				DIRECTIONAL,
				SPOTLIGHT
			};
			Light() = delete;
			Light(const Type type);
			virtual ~Light();

			void setColor(const glm::vec3& color);
			glm::vec3 getColor();
			Type getType();

		private:
			Type m_type;
			glm::vec3 m_color;
		};
	}
}

#endif