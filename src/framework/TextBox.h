#pragma once

#include "pch.h"
#include "widget.h"

namespace ui
{
	struct TextSyle
	{
		sf::Font font;
		Color textColor;
		unsigned int size;
	};

	class TextBox : public ui::Widget
	{
	public:

		virtual ~TextBox() = default;

		TextBox(std::string InitContentText, sf::Vector2i Size, sf::Vector2i Position);

		void SetStyle(TextSyle &NewTextStyle);

		virtual void Draw(RenderContext& owner) const override;

		virtual InputEventState ProcessInput(const InputEvent& event);

		void SetText(std::string NewText) { TxtBox.setString(NewText); };

		void SetPosition(Vector2f NewPosition) { TxtBox.setPosition(NewPosition); };

		Text GetText() { return TxtBox; }

	private:

		void Initialize();

		void LoadDefaultFont();

		sf::Font GeneralFont;
		std::string ContentText;
		Text TxtBox;

		TextSyle DefaultTextStyle;

	};
}
