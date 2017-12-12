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
        VkWriteDescriptorSet* getPositionLightWrites();
        uint32_t getPositionLightWritesCount() const;
        Vulkan::MemoryBuffer getPositionLightCountBuffer() const;
        VkWriteDescriptorSet* getDummyPositionLightWrites();
        uint32_t getDummyPositionLightWritesCount() const;

    private:
        std::vector<unsigned int> m_position_lights;
        std::unordered_map<unsigned int, Vulkan::MemoryBuffer> m_position_light_buffer;
        std::vector<VkWriteDescriptorSet> m_position_light_writes;
        Vulkan::MemoryBuffer m_position_light_count_buffer;
        std::vector<VkWriteDescriptorSet> m_dummy_position_light_writes;
        Vulkan::MemoryBuffer m_dummy_position_light_buffer;
    };
}