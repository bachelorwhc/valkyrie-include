#ifndef _VALKYRIE_RECORDER_H
#define _VALKYRIE_RECORDER_H
#include "valkyrie/vulkan/command_buffer.h"

namespace Valkyrie {
	class Recorder {
	public:
		Recorder() {};
		virtual ~Recorder() {};

		virtual void recordDrawCommand(Vulkan::CommandBuffer& command) = 0;
	private:

	};
}

#endif