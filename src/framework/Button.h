#pragma once

#include "TextBox.h"
#include "pch.h"
#include "InterfaceButton.h"
#include "QuickSlotInterface.h"
#include <iostream>
#include "widget.h"



namespace ui
{
	namespace state
	{
		enum
		{
			Normal = 0,
			Hovered = 1,
			Clicked = 2
		};
	};

	struct ButtonStyle
	{
		Texture TextureNormal;
		Texture TextureHovered;
		Texture TextureClicked;

		Color ColorNormal;
		Color ColorHovered;
		Color ColorClicked;
	};


	class Button : public ui::Widget
	{
	public:

		Button(Vector2f InitSize, Vector2f InitPosition, std::string InitContentText, RenderContext& InitOwner);

		Button(Vector2f InitSize, Vector2f InitPosition, std::string InitContentText, RenderContext& InitOwner, IQuickSlot& InitInterface, bool bIsQuickSlot, sf::Keyboard::Key InitKey);

		Button(Vector2f InitSize, Vector2f InitPosition, std::string InitContentText, RenderContext& InitOwner, IButton& InitInterface);

		virtual void Draw(RenderContext& InitOwner) const override;

		virtual InputEventState ProcessInput(const InputEvent& event);

		bool IsHovered();

		bool IsPressed(InputEvent& m_Event);

		bool IsClicked(InputEvent &m_Event);

		void SetPosition(Vector2f NewPosition);

		void SetSize(Vector2f NewSize) { Size = NewSize; };

		void SetText(std::string NewText) { ContentTextBox.SetText(NewText); };

		void SetStyle(ButtonStyle& NewStyle) { Style = NewStyle; };

		void Update(InputEvent& m_Event);

		void SetDefaultStyle();

		void OnPressed();
	private:

		void Initialize();

		void OnClicked();
		void OnHoverIn();
		void OnHoverOut();

	private:

		sf::RectangleShape Border;

		sf::Uint32 ButtonState;

		TextBox ContentTextBox;

		Vector2f Size;

		Vector2f PositionOnViewport;

		ButtonStyle Style;

		IButton* ButtonInterface;

		IQuickSlot* QuickSlotInterface;

		RenderContext* Owner;

		bool bIsQuickSlot = false;

		sf::Keyboard::Key Key;
	};
}