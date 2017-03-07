//
//  PhysicsManager.hpp
//  BlockEngine
//
//  Created by Eric Schmitt on 3/2/17.
//  Copyright © 2017 Eric Schmitt. All rights reserved.
//

#ifndef PhysicsManager_hpp
#define PhysicsManager_hpp

#include "PhysicsObject.hpp"
#include "Grid.hpp"
#include <vector>

using namespace std;

class PhysicsManager 
{
public:
	PhysicsManager(Grid* grid);
    ~PhysicsManager();

	void Update(float dt);
	void Draw(sf::RenderWindow& window);

	void AddPhysicsObject(PhysicsObject* physicsObject);
	void ClearPhyiscsObjects();
    
private:
	Grid* grid;
	vector<PhysicsObject*> physicsObjects;

	void DetectAndResolveGridCollisions(PhysicsObject* physicsObject);
	
};

#endif /* PhysicsManager_hpp */
