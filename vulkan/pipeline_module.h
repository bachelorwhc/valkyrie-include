#ifndef _VULKAN_PIPELINE_H
#define _VULKAN_PIPELINE_H
#include "valkyrie/common.h"

namespace Vulkan {
	struct Device;
	struct DescriptorSetLayout;
	struct RenderPass;
	struct VertexInput;

	struct PipelineModule {
		static VkPipelineCache cache;
		static VkResult initializeCache();

		PipelineModule();
		virtual ~PipelineModule();

		VkResult initialize();
		VkResult initializeLayout(const std::vector<VkDescriptorSetLayout>& descriptor_set_layouts);
		void setRenderPass(const VkRenderPass render_pass);
		void setVertexInput(const VertexInput& vertex_input);

		VkPipeline handle = VK_NULL_HANDLE;
		VkPipelineLayout layout = VK_NULL_HANDLE;
		std::vector<VkPipelineShaderStageCreateInfo> shaderStageCreates;
		std::vector<VkPushConstantRange> pushConstantRanges;
		std::vector<VkPipelineColorBlendAttachmentState> colorBlendAttachments;

	private:
		void initializeVertexInputState();
		void initializeInputAssemblyState();
		//void initializeTessellationState();
		void initializeViewportState();
		void initializeRasterizationState();
		void initializeMultisampleState();
		void initializeDepthStencilState();
		void initializeColorBlendState();
		void initializeDynamicState();

		VkGraphicsPipelineCreateInfo m_pipeline_create = {};

		VkPipelineVertexInputStateCreateInfo m_vertex_input_state = {};
		VkPipelineInputAssemblyStateCreateInfo m_input_assembly_state = {};
		//VkPipelineTessellationStateCreateInfo m_tessellation_state = {};
		VkPipelineViewportStateCreateInfo m_viewport_state = {};
		VkPipelineRasterizationStateCreateInfo m_rasterization_state = {};
		VkPipelineMultisampleStateCreateInfo m_multisample_state = {};
		VkPipelineDepthStencilStateCreateInfo m_depth_state = {};
		VkPipelineColorBlendStateCreateInfo m_color_blend_state = {};
		VkPipelineDynamicStateCreateInfo m_dynamic_state = {};
		std::vector<VkDynamicState> m_dynamic_state_enables;
	};

	typedef std::shared_ptr<PipelineModule> PipelineModulePointer;

	void DestroyPipeline(PipelineModule& pipeline);
	void DestroyPipelineCache();
}

#endif