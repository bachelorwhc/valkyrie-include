#ifndef _VALKYRIE_MESH_H
#define _VALKYRIE_MESH_H
#include <glm/glm.hpp>
#include "valkyrie/asset/asset.h"
#include "valkyrie/vulkan/memory_buffer.h"

namespace ValkyrieFactory {
	class MeshFactory;
}

namespace Valkyrie {
	class MeshSupport {
	public:
		MeshSupport() {};
		virtual ~MeshSupport() {};

		virtual uint32_t getDrawVertexCount() = 0;
		virtual uint32_t getVerticeBufferOffset() = 0;
		virtual uint32_t getIndiceBufferOffset() = 0;
		virtual uint32_t getVerticeBufferLength() = 0;
		virtual uint32_t getIndiceBufferLength() = 0;
	};

	using MeshSupportPtr = std::shared_ptr<MeshSupport>;

	class Mesh : 
		public Asset,
		public MeshSupport {
	public:
		Mesh() = delete;
		Mesh(const MeshSupportPtr& mesh_ptr);
		virtual ~Mesh();

		virtual uint32_t getDrawVertexCount();
		virtual uint32_t getVerticeBufferOffset();
		virtual uint32_t getIndiceBufferOffset();
		virtual uint32_t getVerticeBufferLength();
		virtual uint32_t getIndiceBufferLength();
		glm::vec3 getMaxXYZ();
		glm::vec3 getMinXYZ();
		VkBuffer getVulkanBuffer() { return m_vulkan_buffer.handle; }

	private:
		friend class ValkyrieFactory::MeshFactory;
		Vulkan::MemoryBuffer m_vulkan_buffer;
		MeshSupportPtr m_mesh_support_ptr;
		glm::vec3* mp_min_xyz = nullptr;
		glm::vec3* mp_max_xyz = nullptr;
	};

	using MeshPtr = std::shared_ptr<Mesh>;
}

#endif