#ifndef PLAYER_H
#define PLAYER_H

#define NORMAL_SPEED 5.0
#define ANGULAR_MOVEMENT 10

#include <godot_cpp/classes/character_body3d.hpp>

namespace godot {

class Player : public CharacterBody3D {
	GDCLASS(Player, CharacterBody3D)

private:
	int point;
	int speed;
	bool off_menu;

protected:
	static void _bind_methods();

public:
	Player();
	~Player();

	int get_point();

	void set_point(int point);

	void increment_point();
};

}

#endif