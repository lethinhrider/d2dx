/*
	This file is part of D2DX.

	Copyright (C) 2021  Bolrog

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

namespace d2dx
{
	MIDL_INTERFACE("7F374C16-390A-4247-889F-8867E4C7B894")
		ITextureCachePolicy abstract : public IUnknown
	{
	public:
		virtual void OnNewFrame() = 0;

		virtual int32_t Find(
			_In_ uint32_t contentKey,
			_In_ int32_t lastIndex) = 0;
		
		virtual int32_t Insert(
			_In_ uint32_t contentKey,
			_Out_ bool& evicted) = 0;
	};
}