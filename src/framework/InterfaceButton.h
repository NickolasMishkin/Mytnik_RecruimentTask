#pragma once
#include "pch.h"

namespace ui
{
	class IButton
	{
	public:

		IButton() = default;
		virtual ~IButton() {};

		void virtual OnClicked() = 0;
		void virtual OnHoverIn() = 0;
		void virtual OnHoverOut() = 0;
	};
}