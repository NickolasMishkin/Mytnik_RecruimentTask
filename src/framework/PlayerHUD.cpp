#include "pch.h"
#include "PlayerHUD.h"
#include <iostream>

namespace ui
{
	PlayerHUD::PlayerHUD(int posX, int posY, int width, int height, RenderContext& Owner)
		: Widget(posX, posY, width, height)
		, HealthBarCharacter({ 100.f,100.f }, { 300.f,100 })
		, HealthBarBoss({ 100.f,300.f }, { 300.f,100 })
		, QuickSlot1({ 100,100 }, { 625,800 }, "1", Owner, *this, true,sf::Keyboard::Num1)
		, QuickSlot2({ 100,100 }, { 750,800 }, "2", Owner, *this, true, sf::Keyboard::Num2)
		, QuickSlot3({ 100,100 }, { 875,800 }, "3", Owner, *this, true, sf::Keyboard::Num3)
	{
	}
	InputEventState PlayerHUD::ProcessInput(const InputEvent& event)
	{
		return InputEventState();
	}

	void PlayerHUD::Draw(RenderContext& Owner) const
	{
		HealthBarCharacter.Draw(Owner);

		HealthBarBoss.Draw(Owner);

		QuickSlot1.Draw(Owner);
		QuickSlot2.Draw(Owner);
		QuickSlot3.Draw(Owner);
	}
	void PlayerHUD::OnPressed()
	{
		std::cout << "Pressed" << std::endl;
	}
	void PlayerHUD::Update(InputEvent& m_event)
	{
		HealthBarCharacter.Update(static_cast<float>(1));
		HealthBarBoss.Update(static_cast<float>(0));
		QuickSlot1.Update(m_event);
		QuickSlot2.Update(m_event);
		QuickSlot3.Update(m_event);

	}
}