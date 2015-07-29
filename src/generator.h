#ifndef GENERATOR_H
#define GENERATOR_H

#define MAX_BULLETS 120

extern HeroTrain heroTrain;
extern VillainTrain villainTrain;
extern Projectile *bullets[ MAX_BULLETS ];
extern int mapPos;
extern int quit;

void shoot();

#endif
