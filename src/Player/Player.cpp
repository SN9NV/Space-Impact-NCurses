#include "Player.hpp"

Player::Player() {
}

Player::Player(const Player &src) {
}

Player::~Player() {
}

Player &operator=(const Player &rhs) {
	this->_hp = rhs._hp;
	this->_maxHp = rhs._maxHp;
	this->_damage = rhs._damage;
	this->_player = rhs._player;

	return *this;
}

void Player::moveDown() {
	this->_loc.y -= 1;
}

void Player::moveUp() {
	this->_loc.y += 1;
}

bool Player::takeDamage(unsigned int amount) {
	this->_hp -= amount;
	if (this->_hp == 0) {
		this->die();
		return true;
	}
	return false;
}

void Player::die() {
	delete(this);
}

Bullet* Player::fire() {
	return new Bullet(this->_damage, this->_bVelocity, this->_gunLoc);
}

loc Player::getLoc() {
	return this->_loc;
}

std::string* Player::getSprite() {
	return this->_sprite;
}

unsigned int Player::getLength(){
	return this->_length;
}

unsigned int Player::getHeight() {
	return this->_height;
}

bool Player::isCollided(Bullet &bullet) {
	for(unsigned int i = 0; i < this->_height; i++) {
		for (int j = 0; j < this->_length; ++j) {
			if (this->_loc.y + i == bullet.getLoc().y && this->_loc.x + j == bullet.getLoc().x) {
				this->takeDamage(1);
				return true;
			}
		}
	}
	return false;
}

bool Player::isCollided(Enemy &enemy){
	for(unsigned int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; ++j) {
			if (isPointOnShape(enemy.getLoc().x + j, enemy.getLoc().y + i) || isPointInShape(enemy.getLoc().x + j, enemy.getLoc().y + i)){
				this->takeDamage(1);
				return true;
			}
		}
	}
	return false;
}

bool Player::isPointOnShape(int x, int y) {
	if (x == this->_loc.x || x == this->_loc.x + this->_length - 1)
		if (y < this->_loc.y && y > this->_loc.y + this->_height - 1)
			return true;

	if (y == this->_loc.y || y == this->_loc.y + this->_height - 1)
		if (x < this->_loc.x && x > this->_loc.x + this->_length - 1)
			return true;
}

bool Player::isPointInShape(int x, int y) {
	bool inX = false;
	bool inY = false;
	if (x > this->_loc.x && x < this->_loc.x + 1)
		inX = true;

	if (y < this->_loc.y && y > this->_loc.y + 1)
		inY = true;

	return (inX && inY);
}