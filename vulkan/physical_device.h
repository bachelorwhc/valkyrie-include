#ifndef _VULKAN_PHYSICAL_DEVICE_H 
#define _VULKAN_PHYSICAL_DEVICE_H
#include "valkyrie/common.h"

namespace Vulkan {
	struct Instance;

	struct PhysicalDevice {
		VkPhysicalDevice handle = NULL;
		static VkPhysicalDeviceProperties properties;
		static VkPhysicalDeviceMemoryProperties memoryProperties;
		static std::vector<VkQueueFamilyProperties> queueFamilyProperties;

		static bool setMemoryType(uint32_t type_bits, VkFlags requirements_mask, uint32_t& type_index);
        static uint32_t getAlignedMemorySize(const uint32_t size, const uint32_t count);
        static uint32_t getAlignedMemoryStep(const uint32_t size);
	};

	VkResult CreatePhysicalDevice(PhysicalDevice& physical_device);
}

#endif