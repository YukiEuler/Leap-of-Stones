#include "teleporter.h"
#include "player.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void Teleporter::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_area_3d_entered", "body"), &Teleporter::_on_area_3d_entered);
}

Teleporter::Teleporter() {
	// Initialize any variables here.
	if (Engine::get_singleton()->is_editor_hint()){
		set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
	}
	connect("body_entered", Callable(this, "_on_area_3d_entered"));
}

Teleporter::~Teleporter() {
	// Add your cleanup here.
}

void Teleporter::_on_area_3d_entered(Node* body) {
    UtilityFunctions::print("Halo");
    if (body->is_in_group("player")){
        Player* player = dynamic_cast<Player*>(body);
        if (player){
            player->set_position(Vector3(1.373803, 0.9, -4.457439));
        }
    }
}
