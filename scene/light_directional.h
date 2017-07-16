#ifndef _VALKYRIE_SCENE_LIGHT_DIRECTIONAL_H
#define _VALKYRIE_SCENE_LIGHT_DIRECTIONAL_H
#include "valkyrie/scene/light.h"

namespace Valkyrie {
	namespace Scene {
		class DirectionalLight :
			public Light {
		public:
			DirectionalLight();
			virtual ~DirectionalLight();
		};
	}
}

#endif