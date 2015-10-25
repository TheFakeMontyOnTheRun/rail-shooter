/*
 * Area.h
 *
 *  Created on: Oct 23, 2015
 *      Author: monty
 */

#ifndef SRC_AREA_H_
#define SRC_AREA_H_

class Area {
public:
	Vec2 pos{ 0, 0 };
	Vec2 delta{ 1, 1 };
	bool contains( const Vec2& p ) const;
	Area( const Vec2& pos, const Vec2& delta );

	virtual ~Area();
};

#endif /* SRC_AREA_H_ */
