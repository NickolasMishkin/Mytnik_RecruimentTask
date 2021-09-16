#include "pch.h"
#include "TextBox.h"

namespace ui
{
	TextBox::TextBox(std::string InitContentText, sf::Vector2i Size, sf::Vector2i Position)
		: ContentText(InitContentText)
		,Widget(Position.x, Position.y, Size.x, Size.y)
	{
		Initialize();
	}

	void TextBox::Initialize()
	{
		LoadDefaultFont();
		DefaultTextStyle = { GeneralFont, Color::Black, 20 };
		SetStyle(DefaultTextStyle);
		TxtBox.setString(ContentText);
	}

	void TextBox::Draw(RenderContext& owner) const
	{
		owner.draw(TxtBox);
	}

	void TextBox::SetStyle(TextSyle &NewTextStyle)
	{
		TxtBox.setCharacterSize(NewTextStyle.size);
		TxtBox.setFillColor(NewTextStyle.textColor);
		TxtBox.setFont(NewTextStyle.font);
	}

	InputEventState TextBox::ProcessInput(const InputEvent& event)
	{
		return InputEventState();
	}

	void TextBox::LoadDefaultFont()
	{
		GeneralFont.loadFromFile("Assets/Font/General_font.ttf");
	}
}