#ifndef _VULKAN_TEXTURE_H
#define _VULKAN_TEXTURE_H
#include "valkyrie/common.h"
#include "valkyrie/asset/image.h"
#include "valkyrie/vulkan/image.h"
#include "valkyrie/vulkan/set_updatable.h"

namespace Vulkan {
	struct Device;
	struct PhysicalDevice;
	struct Queue;
	struct CommandBuffer;

	class Texture : 
		public Image,
		public SetUpdable {
	public:
		Texture() = delete;
		Texture(const Valkyrie::ImageMemoryPointer& image_ptr);
		virtual ~Texture();

		virtual VkImageCreateInfo getImageCreate() const;
		virtual VkImageViewCreateInfo getImageViewCreate() const;
		virtual VkFlags getMemoryType() const;
		VkResult initializeSampler();
		VkResult write();

		virtual VkWriteDescriptorSet getWriteSet();
		VkDescriptorImageInfo* getInformationPointer();

		VkImageLayout layout = VK_IMAGE_LAYOUT_GENERAL;
		VkSampler sampler = VK_NULL_HANDLE;
	private:
		VkDescriptorImageInfo* mp_information = nullptr;
		Valkyrie::ImageMemoryPointer m_image_ptr;
		uint32_t m_size = 0;
	};
}

#endif