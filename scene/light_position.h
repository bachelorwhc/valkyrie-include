#ifndef _VALKYRIE_SCENE_LIGHT_POSITION_H
#define _VALKYRIE_SCENE_LIGHT_POSITION_H
#include "valkyrie/scene/light.h"

namespace Valkyrie {
	namespace Scene {
		class PositionLight :
			public Light {
		public:
			PositionLight();
			virtual ~PositionLight();
		};
	}
}

#endif