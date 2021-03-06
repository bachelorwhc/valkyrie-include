#ifndef _DEFAULT_CREATE_INFO_H
#define _DEFAULT_CREATE_INFO_H
#include <vulkan/vulkan.h>

const VkBufferCreateInfo VK_DEFAULT_BUFFER_CREATE_INFO = {
	VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
	nullptr,
	NULL,
	NULL,
	NULL,
	VK_SHARING_MODE_EXCLUSIVE,
	NULL,
	nullptr
};

const VkPipelineColorBlendAttachmentState VK_DEFAULT_COLOR_BLEND_ATTACHMENT_STATE = {
	VK_TRUE,
	VK_BLEND_FACTOR_SRC_ALPHA,
	VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA,
	VK_BLEND_OP_ADD,
	VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA,
	VK_BLEND_FACTOR_ZERO,
	VK_BLEND_OP_ADD,
	VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT
};

const VkImageCreateInfo VK_DEFAULT_DEPTH_IMAGE_CREATE_INFO = {
	VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
	nullptr,
	NULL,
	VK_IMAGE_TYPE_2D,
	VK_FORMAT_UNDEFINED,
	{
		0,
		0,
		1
	},
	1,
	1,
	VK_SAMPLE_COUNT_1_BIT,
	VK_IMAGE_TILING_OPTIMAL,
	VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT,
	VK_SHARING_MODE_EXCLUSIVE,
	0,
	nullptr,
	VK_IMAGE_LAYOUT_UNDEFINED
};

const VkImageCreateInfo VK_DEFAULT_TEXTURE_IMAGE_CREATE_INFO = {
	VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
	nullptr,
	NULL,
	VK_IMAGE_TYPE_2D,
	VK_FORMAT_R8G8B8A8_UNORM,
	{
		0,
		0,
		1
	},
	1,
	1,
	VK_SAMPLE_COUNT_1_BIT,
	VK_IMAGE_TILING_LINEAR,
	VK_IMAGE_USAGE_SAMPLED_BIT,
	VK_SHARING_MODE_EXCLUSIVE,
	0,
	nullptr,
	VK_IMAGE_LAYOUT_PREINITIALIZED
};

const VkImageViewCreateInfo VK_DEFAULT_DEPTH_IMAGE_VIEW_CREATE_INFO = {
	VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
	nullptr,
	NULL,
	VK_NULL_HANDLE,
	VK_IMAGE_VIEW_TYPE_2D,
	VK_FORMAT_UNDEFINED,
	{
		VK_COMPONENT_SWIZZLE_R,
		VK_COMPONENT_SWIZZLE_G,
		VK_COMPONENT_SWIZZLE_B,
		VK_COMPONENT_SWIZZLE_A
	},
	{
		VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT,
		0,
		1,
		0,
		1
	}
};

const VkImageViewCreateInfo VK_DEFAULT_TEXTURE_IMAGE_VIEW_CREATE_INFO = {
	VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
	nullptr,
	NULL,
	VK_NULL_HANDLE,
	VK_IMAGE_VIEW_TYPE_2D,
	VK_FORMAT_R8G8B8A8_UNORM,
	{
		VK_COMPONENT_SWIZZLE_R,
		VK_COMPONENT_SWIZZLE_G,
		VK_COMPONENT_SWIZZLE_B,
		VK_COMPONENT_SWIZZLE_A
	},
	{
		VK_IMAGE_ASPECT_COLOR_BIT,
		0,
		1,
		0,
		1
	}
};

const VkImageViewCreateInfo VK_DEFAULT_SWAPCHAIN_IMAGE_VIEW_CREATE_INFO = {
	VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
	nullptr,
	NULL,
	VK_NULL_HANDLE,
	VK_IMAGE_VIEW_TYPE_2D,
	VK_FORMAT_MAX_ENUM,
	{
		VK_COMPONENT_SWIZZLE_R,
		VK_COMPONENT_SWIZZLE_G,
		VK_COMPONENT_SWIZZLE_B,
		VK_COMPONENT_SWIZZLE_A
	},
	{
		VK_IMAGE_ASPECT_COLOR_BIT,
		0,
		1,
		0,
		1
	}
};

const VkClearValue VK_DEFAULT_COLOR_CLEAR_VALUE = {
	{
		0.1f,
		0.1f,
		0.1f,
		0.1f
	}
};

const VkClearValue VK_DEFAULT_DEPTH_CLEAR_VALUE = {
	{
		1.0f,
		0
	}
};

const VkClearValue VK_DEFAULT_CLEAR_VALUES[2] = {
	VK_DEFAULT_COLOR_CLEAR_VALUE,
	VK_DEFAULT_DEPTH_CLEAR_VALUE
};

const VkRenderPassBeginInfo VK_DEFAULT_RENDER_PASS_BEGIN = {
	VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,
	nullptr,
	VK_NULL_HANDLE,
	VK_NULL_HANDLE,
	{ },
	2,
	VK_DEFAULT_CLEAR_VALUES
};

#endif