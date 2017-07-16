#ifndef _VALKYRIECOMPONENT_MESH_RENDERER_H
#define _VALKYRIECOMPONENT_MESH_RENDERER_H
#include "valkyrie/component/component.h"
#include "valkyrie/vulkan/command_buffer.h"
#include "valkyrie/vulkan/memory_buffer.h"
#include "valkyrie/asset/mesh_asset.h"
#include "valkyrie/graphics/recorder.h"

namespace ValkyrieComponent {
	class MeshRenderer : 
		public Component,
		public Valkyrie::Recorder {
	public:
		MeshRenderer() = delete;
		MeshRenderer(const Valkyrie::MeshPtr& mesh_ptr);
		virtual ~MeshRenderer() {};

		virtual void start() {};
		virtual void update() {};
		virtual void recordDrawCommand(Vulkan::CommandBuffer& command);

	private:
		Valkyrie::MeshPtr m_mesh_ptr;
	};
}

#endif