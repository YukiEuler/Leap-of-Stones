#include "coin.h"
#include "player.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/animation_player.hpp>

using namespace godot;

void Coin::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_area_3d_body_entered", "body"), &Coin::_on_area_3d_body_entered);
}

Coin::Coin() {
	// Initialize any variables here.
	if (Engine::get_singleton()->is_editor_hint()){
		set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
	}
	connect("body_entered", Callable(this, "_on_area_3d_body_entered"));
}

Coin::~Coin() {
	// Add your cleanup here.
}

void Coin::_process(double delta){
    Node* node = get_node_internal("%Muter");
    if (node){
        AnimationPlayer* animasi = dynamic_cast<AnimationPlayer*>(node);
        if (animasi){
            animasi->play("muter");
        }
    }
}

void Coin::_on_area_3d_body_entered(Node* body) {
    if (body->is_in_group("player")) {
        Player* player = dynamic_cast<Player*>(body);
        if (player) {
            player->increment_point();
            this->queue_free();
        }
    }
}
