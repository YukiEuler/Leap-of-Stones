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
	int jump;
	bool end_game;

protected:
	static void _bind_methods();

public:
	Player();
	~Player();

	int get_point();

	void set_point(int point);

	int get_jump();

	void set_jump(int jump);

	void increment_point();

	bool get_end_game();

	void set_end_game(bool value);
};

}

#endif