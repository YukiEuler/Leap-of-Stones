#ifndef STAR_H
#define STAR_H

#include <godot_cpp/classes/rigid_body3d.hpp>

namespace godot {

class Star : public RigidBody3D {
	GDCLASS(Star, RigidBody3D)

private:

protected:
	static void _bind_methods();

public:
	Star();
	~Star();

	void _on_area_3d_body_entered(Node* body);
};

}

#endif