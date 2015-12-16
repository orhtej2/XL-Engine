#pragma once

#include "graphicsDeviceGL.h"
#include "../samplerState.h"

class TextureGL
{
    public:
        TextureGL(TextureHandle handle, bool dynamic);
        virtual ~TextureGL();

		void bind(u32 slot);

		bool createRGBA(u32 width, u32 height, const u32* data, const SamplerState& initSamplerState);
		void update(const u32* data);

		void setSamplerState(const SamplerState& state);

		TextureHandle getHandle() { return m_handle; }
		
		//clear
		static void clear(u32 slot);

	private:
		void setGLSamplerState(const SamplerState& state);

		bool m_dynamic;
		u32 m_glID;
		u32 m_width;
		u32 m_height;

		TextureHandle m_handle;
};