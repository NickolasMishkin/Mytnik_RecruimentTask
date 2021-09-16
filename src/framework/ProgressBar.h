#pragma once

#include "pch.h"
#include "widget.h"

namespace ui
{
	class ProgressBar : public ui::Widget 
	{
	public:

		virtual ~ProgressBar() = default;

		virtual InputEventState ProcessInput(const InputEvent& event) override;

		ProgressBar(Vector2f InitPosition, Vector2f InitSize);
		
		void Update(float CurrentValue);

		void SetMaxValue(float NewMaxValue) { max = NewMaxValue; };
		void SetMinValue(float NewMinValue) { min = NewMinValue; };

		virtual void Draw(RenderContext& InitOwner) const override;
		
		void SetTexture(Texture& NewTexture) { BGTexture = NewTexture; };

	private:

		void Initialize();

	private:

		float min = 0.f;
		float max = 1.f;

		sf::Image BGImage;
		Texture BGTexture;
		sf::Sprite ProgressBg;
		sf::RectangleShape Box;

		Vector2f PositionOnViewport;
		Vector2f Size;
		Vector2f Step;

	};
}
