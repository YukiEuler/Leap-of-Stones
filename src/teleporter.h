#ifndef TELEPORTER_H
#define TELEPORTER_H

#include <godot_cpp/classes/area3d.hpp>

namespace godot {

class Teleporter : public Area3D {
	GDCLASS(Teleporter, Area3D)

private:
	

protected:
	static void _bind_methods();

public:
	Teleporter();
	~Teleporter();

	void _on_area_3d_entered(Node* body);
};

}

#endif