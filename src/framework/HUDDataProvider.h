#pragma once

namespace ui
{
	class HUDDataProvider : public ui::IButton
	{
	public:

		HUDDataProvider() = default;
		virtual ~HUDDataProvider() {};

		void virtual OnHeroHealthChange(float CurrentHP) = 0;
		void virtual OnBossHealthChange(float CurrentHP) = 0;
		void virtual OnClicked() = 0;
	};
}