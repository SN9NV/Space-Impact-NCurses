#ifndef RUSH00_GAMELOOP_HPP
#define RUSH00_GAMELOOP_HPP

#include <ncurses.h>
#include <zconf.h>

#include "actions.hpp"
#include "obstacles.hpp"

#include "LinkedList.hpp"
#include "Zorg.hpp"
#include "ShipOne.hpp"

void	gameLoop(void);
void	gameOver(int x, int y);
void 	drawPlayer(Player &player);
void 	drawBullets(LinkedList<Bullet> &bulletList);
void 	drawBullets(Bullet **bullet);
void 	addBullet(Bullet **bullet, Bullet *newBullet);
void 	updateBullets(Bullet **bullet);
void	drawEnemies(Enemy **enemy);
void 	addEnemy(Enemy **enemy, Enemy *newEnemy);
void 	updateEnemies(Enemy **enemy, Bullet **bullets, unsigned int &score);
bool 	updatePlayerCollision(Player &player, Bullet **bullet, Enemy **enemy, unsigned int &lives);


#endif //RUSH00_GAMELOOP_HPP
