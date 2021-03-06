#ifndef _VULKAN_DEBUG_H
#define _VULKAN_DEBUG_H
#include "valkyrie/common.h"

namespace Vulkan {
	struct Instance;

	VkBool32 DebugCallback(
		VkDebugReportFlagsEXT flags, 
		VkDebugReportObjectTypeEXT object_type, 
		uint64_t source_object,
		size_t location,
		int32_t code,
		const char* p_layer,
		const char* p_message,
		void* p_user_data);

	void SetupDebug(VkDebugReportFlagsEXT flags);
}

#endif