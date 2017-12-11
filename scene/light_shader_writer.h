#pragma once
#include "valkyrie/scene/light_position.h"
#include "valkyrie/vulkan/memory_buffer.h"
#define MAX_POSITION_LIGHT 16

namespace Valkyrie {
    class LightShaderWriter {
    public:
        LightShaderWriter();
        virtual ~LightShaderWriter();

        void addLight(unsigned int ID);
        void removeLight(unsigned int ID);
        void updateLights();

    private:
        std::vector<unsigned int> m_position_lights;
        std::unordered_map<unsigned int, Vulkan::MemoryBuffer> m_position_light_buffer;
    };
}