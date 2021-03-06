#ifndef _VALKYRIE_GRAPHICS_PIPELINE_H
#define _VALKYRIE_GRAPHICS_PIPELINE_H
#include "valkyrie/vulkan/pipeline_module.h"
#include "valkyrie/vulkan/vertex_input.h"
#include "valkyrie/vulkan/shader.h"
#include "valkyrie/vulkan/descriptor.h"
#include "valkyrie/vulkan/command_buffer.h"
#include "valkyrie/common.h"

namespace Valkyrie {
	class Renderer;

	namespace Graphics {
		class Pipeline {
		public:
			enum ShaderStage {
                UNKNOWN,
				VERTEX,
				FRAGMENT
			};

			Pipeline();
			virtual ~Pipeline();

			void initialize(const Renderer& renderer);
			void commandBind(const Vulkan::CommandBuffer& command);

			Vulkan::VertexInput vertexInput;
			Vulkan::DescriptorPoolPtr descriptorPoolPtr;
			std::map<ShaderStage, Vulkan::ShaderPointer> shaderPtrs;

			Vulkan::PipelineModule module;
		};
	}
}

#endif