#include "pch.h"
#include "ProgressBar.h"

InputEventState ui::ProgressBar::ProcessInput(const InputEvent& event)
{
	return InputEventState();
}

ui::ProgressBar::ProgressBar(Vector2f InitPosition, Vector2f InitSize)
	:PositionOnViewport(InitPosition)
	,Size(InitSize)
	,Widget(static_cast<int>(InitPosition.x), static_cast<int>(InitPosition.y), static_cast<int>(InitSize.x), static_cast<int>(InitSize.y))
{
	Initialize();
}

void ui::ProgressBar::Update(float CurrentValue)
{
	Vector2f step = { Box.getSize().x / (max - min) * (max - min - CurrentValue), Box.getSize().y };
	
	if (CurrentValue >= min && CurrentValue <= max)
	{
		Box.setSize(step);
	}
}

void ui::ProgressBar::Initialize()
{
	BGImage.loadFromFile("Assets/Images/ProgressBar.png");
	BGTexture.loadFromImage(BGImage);
	Box.setSize(static_cast<Vector2f>(BGImage.getSize()));
	ProgressBg.setTexture(BGTexture);
	ProgressBg.setColor(Color::Red);
	Box.setPosition({ PositionOnViewport.x + ProgressBg.getLocalBounds().width,PositionOnViewport.y + ProgressBg.getLocalBounds().height });
	ProgressBg.setPosition(PositionOnViewport);
	Box.setFillColor(Color::Green);
	Box.setRotation(180);
}

void ui::ProgressBar::Draw(RenderContext& Owner) const
{
	Owner.draw(ProgressBg);
	Owner.draw(Box);
}
