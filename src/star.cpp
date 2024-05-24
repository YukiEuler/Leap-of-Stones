#include "star.h"
#include "player.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void Star::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_area_3d_body_entered", "body"), &Star::_on_area_3d_body_entered);
}

Star::Star() {
	// Initialize any variables here.
	if (Engine::get_singleton()->is_editor_hint()){
		set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
	}
	connect("body_entered", Callable(this, "_on_area_3d_body_entered"));
}

Star::~Star() {
	// Add your cleanup here.
}

void Star::_on_area_3d_body_entered(Node* body) {
    if (body->is_in_group("Player")) {
        Player* player = dynamic_cast<Player*>(body);
        if (player) {
            player->increment_point();
            this->queue_free();
        }
    }
}
