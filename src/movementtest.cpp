#include "movementtest.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

void MovementTest::_bind_methods() {
}

MovementTest::MovementTest() {
	// Initialize any variables here.
	if (Engine::get_singleton()->is_editor_hint()){
		set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
	}
	time_passed = 0.0;
}

MovementTest::~MovementTest() {
	// Add your cleanup here.
}

void MovementTest::_process(double delta) {
	time_passed += delta;
	Vector3 new_position = Vector3(time_passed, 0, 0);

	set_position(new_position);
}