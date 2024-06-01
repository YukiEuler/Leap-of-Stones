#ifndef COIN_H
#define COIN_H

#include <godot_cpp/classes/area3d.hpp>

namespace godot {

class Coin : public Area3D {
	GDCLASS(Coin, Area3D)

private:

protected:
	static void _bind_methods();

public:
	Coin();
	~Coin();

	void _on_area_3d_body_entered(Node* body);
	void _process(double delta) override;
};

}

#endif