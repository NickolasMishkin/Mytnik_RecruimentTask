#pragma once

#include "pch.h"
#include "widget.h"
#include "Button.h"
#include "ProgressBar.h"
#include "InterfaceButton.h"
#include <iostream>

namespace ui
{
	class PlayerHUD : public ui::Widget, public ui::IQuickSlot
	{
	public:

		PlayerHUD(int posX, int posY, int width, int height, RenderContext& Owner);

		virtual InputEventState ProcessInput(const InputEvent& event) override;

		virtual void Draw(RenderContext& Owner) const override;

		virtual void OnPressed() override;

		void Update(InputEvent& m_event);

	private:

		void Initialize();

		Button QuickSlot1;
		Button QuickSlot2;
		Button QuickSlot3;

		ProgressBar HealthBarCharacter;
		ProgressBar HealthBarBoss;
	};
}
