#ifndef SUPERJUMP_H
#define SUPERJUMP_H

#define JUMP_NORMAL 5
#define JUMP_BOOST 12

#include <godot_cpp/classes/area3d.hpp>

namespace godot {

class SuperJump : public Area3D {
	GDCLASS(SuperJump, Area3D)

private:
	

protected:
	static void _bind_methods();

public:
	SuperJump();
	~SuperJump();

	void _enter_super_jump(Node* body);
    void _exit_super_jump(Node* body);
};

}

#endif