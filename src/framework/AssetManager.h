#pragma once

#include "pch.h"
#include <map>

//I didn't have time to integrate it into the layout, but it worked during testing. 
namespace ui
{
	class AssetManager
	{
	public:
		
		AssetManager() {};
		~AssetManager() = default;
		
		void LoadTexture(std::string Name,std::string Path);
		sf::Texture &GetTexture(std::string Name);

		void LoadFont(std::string Name, std::string Path);
		sf::Font &GetFont(std::string Name);

	private:
	
		std::map<std::string, sf::Texture> Textures;
		std::map<std::string, sf::Font> Fonts;
	};
}

