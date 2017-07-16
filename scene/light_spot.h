#ifndef _VALKYRIE_SCENE_LIGHT_SPOT_H
#define _VALKYRIE_SCENE_LIGHT_SPOT_H
#include "valkyrie/scene/light.h"

namespace Valkyrie {
	namespace Scene {
		class Spotlight :
			public Light {
		public:
			Spotlight();
			virtual ~Spotlight();

			float range = 0.0f;
			glm::vec3 decay;
		};
	}
}

#endif