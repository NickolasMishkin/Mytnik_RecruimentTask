#pragma once

namespace ui
{
	class IQuickSlot
	{
	public:

		IQuickSlot() = default;
		virtual ~IQuickSlot() {};

		void virtual OnPressed() = 0;
	};
}