/*
	This file is part of D2DX.

	D2DX is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	D2DX is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with D2DX.  If not, see <https://www.gnu.org/licenses/>.
*/
#pragma once

#include "Buffer.h"

namespace d2dx
{
	class TextureProcessor final
	{
	public:
		TextureProcessor();
		~TextureProcessor();

		void CopyPixels(
			int32_t srcWidth,
			int32_t srcHeight,
			_In_reads_(srcPitch * srcHeight) const uint8_t* __restrict srcPixels,
			uint32_t srcPitch,
			_Out_writes_all_(dstPitch * srcHeight) uint8_t* __restrict dstPixels,
			uint32_t dstPitch);

		void ConvertToRGBA(
			int32_t width,
			int32_t height,
			_In_reads_(width * height) const uint8_t* __restrict srcPixels,
			_In_reads_(256) const uint32_t* __restrict palette,
			_Out_writes_all_(width * height) uint32_t* __restrict dstPixels);
		
		void ConvertChromaKeyedToRGBA(
			int32_t width,
			int32_t height,
			_In_reads_(width* height) const uint8_t* __restrict srcPixels,
			_In_reads_(256) const uint32_t* __restrict palette,
			_Out_writes_all_(dstPitch * height) uint32_t* __restrict dstPixels,
			uint32_t dstPitch);

		void Dilate(
			int32_t width,
			int32_t height,
			_Inout_updates_all_(width * height) uint32_t* __restrict pixels);
		
		void DilateFloorTile(
			int32_t width,
			int32_t height,
			_In_reads_(width * height) const uint32_t* __restrict srcPixels,
			_Out_writes_all_(width * height) uint32_t* __restrict dstPixels);

		void CopyPixels(
			int32_t width,
			int32_t height,
			_In_reads_(width * height) const uint32_t* __restrict srcPixels,
			_Out_writes_all_(width * height) uint32_t* __restrict dstPixels);
		
		void CopyAlpha(
			int32_t width,
			int32_t height,
			_In_reads_(width * height) const uint32_t* __restrict srcPixels,
			_Inout_updates_all_(width * height) uint32_t* __restrict dstPixels);
	};
}