#ifndef MOVEMENTTEST_H
#define MOVEMENTTEST_H

#include <godot_cpp/classes/sprite3d.hpp>

namespace godot {

class MovementTest : public Sprite3D {
	GDCLASS(MovementTest, Sprite3D)

private:
	double time_passed;

protected:
	static void _bind_methods();

public:
	MovementTest();
	~MovementTest();

	void _process(double delta) override;
};

}

#endif