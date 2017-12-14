#pragma once
#include "valkyrie/common.h"
#include "valkyrie/graphics/pipeline.h"

namespace Valkyrie {
    class PipelineShadersInitializer {
    public:
        enum VertexShaderVariableType {
            POSITION,
            NORMAL,
            UV
        };
    public:
        PipelineShadersInitializer() {};
        ~PipelineShadersInitializer() {};

        void initializeShaders(const std::string& filepath, Graphics::Pipeline& pipeline);

        void initializePool(Graphics::Pipeline& pipeline);

        void initializeBindings(Graphics::Pipeline& pipeline);

        void setShaderVariableName(const VertexShaderVariableType variable, const std::string& name);

        std::string getShaderVariableName(const VertexShaderVariableType variable) const;

        void setPipelineVertexInput(Graphics::Pipeline& pipeline, std::vector<uint32_t>&& default_attr_sizes = { 12, 12, 8 });

        void initializePipelinePushConstantRanges(Graphics::Pipeline& pipeline);

    private:
        std::map<Graphics::Pipeline::ShaderStage, Vulkan::ShaderPointer> m_shader_ptrs;
        JSON m_json;
        std::vector<VkPushConstantRange> m_push_constant_ranges;
        std::map<VertexShaderVariableType, std::string> m_shader_variable_names;

        static const uint32_t GetTypeSize(const std::string& type_name) {
            if (type_name == "float") { return sizeof(float); }
            else if (type_name == "double") { return sizeof(double); }
            else if (type_name == "float16_t") { return 16; }
            else if (type_name == "int") { return sizeof(int); }
            else if (type_name == "uint") { return sizeof(unsigned int); }
            else if (type_name == "int64_t") { return 64; }
            else if (type_name == "uint64_t") { return 64; }
            else if (type_name == "int16_t") { return 16; }
            else if (type_name == "uint16_t") { return 16; }
            else if (type_name == "bool") { return sizeof(int); }
            else { throw std::exception("unacceptable type"); }
        };
    };
}