#ifndef _VALKYRIE_ASSET_MANAGER_H
#define _VALKYRIE_ASSET_MANAGER_H
#include <filesystem>
#include <unordered_map>
#include "valkyrie/asset/asset.h"
#include "valkyrie/asset/lavy_loader.h"

namespace Valkyrie {
	class MemoryChunk;
	using MemoryChunkPtr = std::shared_ptr<MemoryChunk>;

	class AssetManager {
	public:
		static int initialize();
		static void close();
		static bool initialized();
		static AssetManager& instance() { return *gp_asset_manager; }

		virtual ~AssetManager();

		void load(std::experimental::filesystem::path file_path) throw(...);
		void fillMemoryFromFile(MemoryChunkPtr& ptr, const std::experimental::filesystem::path& abs_path) throw(...);
		std::experimental::filesystem::path getAssetsDirectory() { return m_path; };
		AssetPtr getAsset(std::string relative_path);
		MeshPtr getMesh(std::string mesh_name);

	private:
		static AssetManager* gp_asset_manager;
		AssetManager();

		std::experimental::filesystem::path m_path;
		std::unordered_map <std::string, AssetPtr> m_asset_map;
		std::unordered_map <std::string, MeshPtr> m_mesh_map;
		std::unordered_map <std::string, MemoryChunkPtr> m_memory_chunk_map;
		LavyLoader m_lavy_loader;
	};
}

#endif