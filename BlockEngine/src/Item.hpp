//
//  Item.hpp
//  BlockEngine
//
//  Created by Eric Schmitt on 3/2/17.
//  Copyright © 2017 Eric Schmitt. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp

#include "ItemType.hpp"
#include "Utilities.hpp"

class Item
{
public:
	Item(ItemType itemType);
    virtual ~Item();

protected:
	ItemType itemType;

};

#endif /* Item_hpp */