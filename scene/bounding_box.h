#ifndef _VALKYRIE_SCENE_ROUNDING_BOX_H
#define _VALKYRIE_SCENE_ROUNDING_BOX_H
#include <glm/glm.hpp>

namespace Valkyrie {
	namespace Scene {
		class RoundingBox {
		public:
			RoundingBox();
			RoundingBox(const glm::vec3& position, const glm::vec3& diagonal);
			virtual ~RoundingBox();

			bool overlap(const RoundingBox& rhs) const;
			glm::vec3 min;
			glm::vec3 max;
		};
	}
}

Valkyrie::Scene::RoundingBox operator&(const Valkyrie::Scene::RoundingBox& lhs, const Valkyrie::Scene::RoundingBox& rhs);
Valkyrie::Scene::RoundingBox operator|(const Valkyrie::Scene::RoundingBox& lhs, const Valkyrie::Scene::RoundingBox& rhs);

#endif