/*
 * Area.cpp
 *
 *  Created on: Oct 23, 2015
 *      Author: monty
 */
#include "Vec2.h"
#include "Area.h"

Area::Area( const Vec2& aPos, const Vec2& aDelta):
pos(aPos), delta(aDelta)
{
}

bool Area::contains(const Vec2& p ) const {
	return ( pos.x <= p.x ) &&
		 ( p.x <= pos.x + delta.x) &&
		  ( pos.y <= p.y ) &&
		   ( p.y <= pos.y + delta.y );
}

Area::~Area() {
}

