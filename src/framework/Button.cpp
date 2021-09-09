#include "pch.h"
#include "Button.h"

ui::Button::Button(Vector2f InitSize, Vector2f InitPosition, std::string InitContentText, RenderContext& InitOwner)
	: Size(InitSize)
	, PositionOnViewport(InitPosition)
	, Owner(&InitOwner)
	, ContentTextBox(InitContentText,static_cast<sf::Vector2i>(InitSize), static_cast<sf::Vector2i>(InitPosition))
	, Widget(static_cast<int>(InitPosition.x), static_cast<int>(InitPosition.y), static_cast<int>(InitSize.x), static_cast<int>(InitSize.y))
{
	Initialize();
}



ui::Button::Button(Vector2f InitSize, Vector2f InitPosition, std::string InitContentText, RenderContext& InitOwner, IButton& InitInterface)
	:Button(InitSize, InitPosition, InitContentText, InitOwner)
{
	this->ButtonInterface = &InitInterface;
}

ui::Button::Button(Vector2f InitSize, Vector2f InitPosition, std::string InitContentText, RenderContext& InitOwner, IQuickSlot& InitInterface, bool bInitIsQuickSlot, sf::Keyboard::Key InitKey)
	: Button(InitSize, InitPosition, InitContentText, InitOwner)
{
	QuickSlotInterface = &InitInterface;
	bIsQuickSlot = bInitIsQuickSlot;
	Key = InitKey;
}

void ui::Button::Draw(RenderContext& InitOwner) const
{
	InitOwner.draw(Border);
	ContentTextBox.Draw(InitOwner);
}

InputEventState ui::Button::ProcessInput(const InputEvent& event)
{
	return InputEventState();
}

void ui::Button::Initialize()
{
	Border.setSize(Size);
	SetPosition(PositionOnViewport);
	SetDefaultStyle();
}

bool ui::Button::IsHovered()
{
	int MousePosX = sf::Mouse::getPosition(*Owner).x;
	int MousePosY = sf::Mouse::getPosition(*Owner).y;

	float LBtnPosX = PositionOnViewport.x;
	float LBtnPosY = PositionOnViewport.y;
	
	float BtnPosWidth = PositionOnViewport.x + Border.getLocalBounds().width;
	float BtnPosHeight = PositionOnViewport.y + Border.getLocalBounds().height;

	if (MousePosX < BtnPosWidth && MousePosX > LBtnPosX && MousePosY < BtnPosHeight && MousePosY > LBtnPosY)
	{
		return true;
	}

	return false;
}

bool ui::Button::IsPressed(InputEvent& m_Event)
{
	
	if (m_Event.type == sf::Event::KeyReleased && m_Event.key.code == Key)
	{
		return true;
	}
	else return false;
}

bool ui::Button::IsClicked(InputEvent& m_Event)
{
	if (IsHovered())
	{
		if (m_Event.type == sf::Event::MouseButtonReleased && m_Event.mouseButton.button == sf::Mouse::Left)
		{
			ButtonState = state::Clicked;
			return true;
		}
		else ButtonState = state::Hovered;
	}
	else ButtonState = state::Normal;

	return false;
}

void ui::Button::SetPosition(Vector2f NewPosition)
{
	PositionOnViewport = NewPosition;
	Border.setPosition(NewPosition);
	auto TextLocalBounds = ContentTextBox.GetText().getLocalBounds();
	ContentTextBox.SetPosition({NewPosition.x + Border.getLocalBounds().width / 2 - TextLocalBounds.width / 2, NewPosition.y + Border.getLocalBounds().height / 2 - TextLocalBounds.height / 2});
}

void ui::Button::Update(InputEvent& m_Event)
{
	if (bIsQuickSlot==false)
	{
		IsClicked(m_Event);

		switch (ButtonState)
		{
		case state::Normal:
		{
			OnHoverOut();
		}
		break;

		case state::Hovered:
		{
			OnHoverIn();
		}
		break;

		case state::Clicked:
		{
			OnClicked();
		}
		break;
		}
	}
	else
	{

		if (IsPressed(m_Event))
		{
			OnPressed();
		}
	}
}

void ui::Button::OnPressed()
{
	if (QuickSlotInterface != nullptr)
	QuickSlotInterface->OnPressed();
}

void ui::Button::OnClicked()
{
	//setTexture(&Style.TextureClicked);

	Border.setFillColor(Style.ColorClicked);
	if (ButtonInterface != nullptr)
	ButtonInterface->OnClicked();
}

void ui::Button::OnHoverIn()
{
	//setTexture(&Style.TextureHovered);

	Border.setFillColor(Style.ColorHovered);
	if(ButtonInterface !=nullptr)
	ButtonInterface->OnHoverIn();
}

void ui::Button::OnHoverOut()
{
	//setTexture(&Style.TextureNormal);

	Border.setFillColor(Style.ColorNormal);
	if(ButtonInterface !=nullptr)
	ButtonInterface->OnHoverOut();
}

void ui::Button::SetDefaultStyle()
{
	Style.ColorNormal = Color::White;
	Style.ColorHovered = Color::Yellow;
	Style.ColorClicked = Color::Green;	

	/*
	Style.TextureClicked =
	Style.TextureHovered =
	Style.TextureNormal =
	setTextureRect(sf::IntRect(static_cast<sf::Vector2i>(PositionOnViewport) - static_cast<sf::Vector2i>(Size) / 2, static_cast<sf::Vector2i>(Size)));*/
}


