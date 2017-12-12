#ifndef _VALKYRIE_SCENE_LIGHT_POSITION_H
#define _VALKYRIE_SCENE_LIGHT_POSITION_H
#include "valkyrie/scene/light.h"

namespace Valkyrie {
	namespace Scene {
		class PositionLight :
			public Light {
		public:
            enum DirtyFlag {
                POSITION = 1,
                COLOR = 2,
                ATTEN_FACTOR = 4,
                INTENSITY = 8
            };

			PositionLight();
			virtual ~PositionLight();

            virtual void setColor(const glm::vec3& color) override;
            void setPosition(const glm::vec3& position);
            glm::vec3 getPosition() const;
            void setAttenFactor(const glm::vec3& atten_factor);
            glm::vec3 getAttenFactor() const;
            void setIntensity(const float intensity);
            float getIntensity() const;

        private:
            virtual bool _isNeedUpdateBuffer() const override;
            virtual void _resetDirty() override;

            DirtyFlags m_dirty;
            glm::vec3 m_position;
            glm::vec3 m_atten_factor = glm::vec3(0.0f, 1.0f, 0.0f);
            float m_intensity = 1.0f;
		};
	}
}

#endif