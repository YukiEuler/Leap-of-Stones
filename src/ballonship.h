#ifndef BALLONSHIP_H
#define BALLONSHIP_H

#include <godot_cpp/classes/node3d.hpp>
#include "player.h"

namespace godot {

class BallonShip : public Node3D {
	GDCLASS(BallonShip, Node3D)

private:
	bool move;

protected:
	static void _bind_methods();

public:
	BallonShip();
	~BallonShip();

	void _process(double delta) override;
	void _on_area_3d_body_entered(Node* body);
	void _on_area_3d_body_exited(Node* body);
};

}

#endif