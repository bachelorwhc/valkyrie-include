#ifndef _VALKYRIE_GRAPHICS_PIPELINE_H
#define _VALKYRIE_GRAPHICS_PIPELINE_H
#include "valkyrie/vulkan/pipeline_module.h"
#include "valkyrie/vulkan/vertex_input.h"
#include "valkyrie/vulkan/shader.h"
#include "valkyrie/vulkan/descriptor.h"
#include "common.h"

namespace Valkyrie {
	namespace Graphics {
		class Pipeline {
		public:
			enum ShaderStage {
				VERTEX,
				FRAGMENT
			};

			Pipeline();
			virtual ~Pipeline();

			void initializePipeline();

			Vulkan::VertexInput vertexInput;
			Vulkan::DescriptorPoolPtr descriptorPoolPtr;
			std::map<ShaderStage, Vulkan::ShaderPointer> shaders;

		private:
			Vulkan::PipelineModule module;
		};
	}
}

#endif