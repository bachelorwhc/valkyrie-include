#ifndef _VULKAN_SURFACE_H
#define _VULKAN_SURFACE_H
#include <memory>
#include "utility.h"
#include "wendy.h"
#include "valkyrie/vulkan/attachment.h"

namespace Vulkan {
	struct PhysicalDevice;
	struct Instance;

	struct Surface : public Attachment {
		VkSurfaceKHR handle = NULL;
		VkSurfaceFormatKHR format = {};

		virtual VkAttachmentDescription getAttachmentDescription() const;
	};

	VkResult setSurface(Surface& surface, const Wendy::Window& window, const Instance& instance);
	void DestroySurface(Instance& instance, Surface& surface);
}

#endif