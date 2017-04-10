#include "ResourcePath.hpp"
#include "ResourceManager.hpp"
#include "ScreenManager.hpp"
#include "EventManager.hpp"
#include "HomeScreen.hpp"

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(960, 540), "BlockEngine");
	window.setVerticalSyncEnabled(true);

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// Load resources
	ResourceManager::GetInstance().LoadAll("ResourceFile.txt");
    
	// Create screen manager
    ScreenManager screenManager;
    screenManager.AddScreen(new HomeScreen());
    
	// Create time keeping variables
	sf::Clock clock;
    sf::Time dt;

	for (int i = 0; i < 1000; i++)
	{
		int x = Random(0, 100);
		if (x == 0)
		{
			int y = 0;
		}
		else if (x == 100)
		{
			int y = 0;
		}
	}

    // Start the game loop
    while (window.isOpen())
    {
        // Calculate dt
        dt = clock.restart();

		// Clear events
		EventManager::GetInstance().ClearEvents();
        
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window or escape pressed: exit
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }

			EventManager::GetInstance().HandleEvent(event);
        }

        // Clear screen
        window.clear();
        
        // Handle input, update, and draw screens
        screenManager.HandleInput(window);
        screenManager.Update(dt.asSeconds());
        screenManager.Draw(window);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
