#include "pch.h"
#include "AssetManager.h"

void ui::AssetManager::LoadTexture(std::string Name, std::string Path)
{
	sf::Texture texture;
	if (texture.loadFromFile(Path))
	{
		this->Textures[Name] = texture;
	}
}

sf::Texture& ui::AssetManager::GetTexture(std::string Name)
{
	return this->Textures.at(Name);
}

void ui::AssetManager::LoadFont(std::string Name, std::string Path)
{
	sf::Font font;
	if (font.loadFromFile(Path))
	{
		this->Fonts[Name] = font;
	}
}

sf::Font& ui::AssetManager::GetFont(std::string Name)
{
	return this->Fonts.at(Name);
}
