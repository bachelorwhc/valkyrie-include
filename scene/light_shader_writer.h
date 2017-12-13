#pragma once
#include "valkyrie/scene/light_position.h"
#include "valkyrie/vulkan/memory_buffer.h"
#define MAX_POSITION_LIGHT 16

namespace Valkyrie {
    class LightShaderWriter {
    public:
        LightShaderWriter();
        virtual ~LightShaderWriter();

        bool addLight(unsigned int ID);
        void removeLight(unsigned int ID);
        void updateLights();
        VkWriteDescriptorSet getPositionLightWrite();
        Vulkan::MemoryBuffer getPositionLightCountBuffer() const;

    private:
        std::vector<unsigned int> m_position_lights;
        Vulkan::MemoryBuffer m_position_lights_buffer;
        Vulkan::MemoryBuffer m_position_light_count_buffer;
        VkWriteDescriptorSet m_position_light_write = {};
        VkDescriptorBufferInfo m_position_light_buffer_info = {};
    };
}