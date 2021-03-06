#include "ResourceManager.hpp"
#include "ResourceLoader.hpp"
#include "OutputManager.hpp"
#include "Utilities.hpp"

ResourceManager::~ResourceManager()
{
	WriteLine("Deleting textures");
	for (map<string, sf::Texture*>::iterator textureItor = textureMap->begin(); textureItor != textureMap->end(); textureItor++)
	{
		delete (*textureItor).second;
	}
	textureMap->clear();
	delete textureMap;

	WriteLine("Deleting sounds");
	for (map<string, sf::SoundBuffer*>::iterator soundItor = soundMap->begin(); soundItor != soundMap->end(); soundItor++)
	{
		delete (*soundItor).second;
	}
	soundMap->clear();
	delete soundMap;

	WriteLine("Deleting fonts");
	for (map<string, sf::Font*>::iterator fontItor = fontMap->begin(); fontItor != fontMap->end(); fontItor++)
	{
		delete (*fontItor).second;
	}
	fontMap->clear();
	delete fontMap;
}

////////////////////////////////////////////////////////////////////////

void ResourceManager::LoadAll(string resourceFilePath)
{
	ResourceLoader loader(resourceFilePath);

	loader.Run();

	textureMap = loader.GetTextureMap();
	soundMap = loader.GetSoundMap();
	fontMap = loader.GetFontMap();
}

////////////////////////////////////////////////////////////////////////

const sf::Texture* ResourceManager::GetTexture(string texture)
{
	return (*textureMap)[texture];
}

////////////////////////////////////////////////////////////////////////

const sf::SoundBuffer* ResourceManager::GetSound(string sound)
{
	return (*soundMap)[sound];
}

////////////////////////////////////////////////////////////////////////

const sf::Font* ResourceManager::GetFont(string font)
{
	return (*fontMap)[font];
}

////////////////////////////////////////////////////////////////////////

vector<string> ResourceManager::GetTextureNames(string filter = "")
{
	vector<string> textureNames;

	for (map<string, sf::Texture*>::iterator textureItor = textureMap->begin(); textureItor != textureMap->end(); textureItor++)
	{
		if (StringContains((*textureItor).first, filter))
		{
			textureNames.push_back((*textureItor).first);
		}
	}

	return textureNames;
}
