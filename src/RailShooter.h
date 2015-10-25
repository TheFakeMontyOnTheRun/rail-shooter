#ifndef GENERATOR_H
#define GENERATOR_H

extern HeroTrain heroTrain;
extern VillainTrain villainTrain;
extern std::vector<std::shared_ptr<Bullet>> bullets;
extern int mapPos;
extern bool quit;

void shoot();
void fireBullet(int xPos, int yPos, int xSpeed, int ySpeed);

#endif
