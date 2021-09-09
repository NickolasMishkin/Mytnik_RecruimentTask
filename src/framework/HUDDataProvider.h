#pragma once

class HUDDataProvider
{
public:

	HUDDataProvider() = default;
	virtual ~HUDDataProvider() {};

	void virtual OnHeroHealthChange(float CurrentHP) = 0;
	void virtual OnBossHealthChange(float CurrentHP) = 0;
	void virtual OnButtonChange() = 0;
};