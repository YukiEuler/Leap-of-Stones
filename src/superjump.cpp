#include "superjump.h"
#include "player.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void SuperJump::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_enter_super_jump", "body"), &SuperJump::_enter_super_jump);
    ClassDB::bind_method(D_METHOD("_exit_super_jump", "body"), &SuperJump::_exit_super_jump);
}

SuperJump::SuperJump() {
	// Initialize any variables here.
	if (Engine::get_singleton()->is_editor_hint()){
		set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
	}
	connect("body_entered", Callable(this, "_enter_super_jump"));
    connect("body_exited", Callable(this, "_exit_super_jump"));
}

SuperJump::~SuperJump() {
	// Add your cleanup here.
}

void SuperJump::_enter_super_jump(Node* body) {
    if (body->is_in_group("player")){
        Player* player = dynamic_cast<Player*>(body);
        if (player){
            player->set_jump(JUMP_BOOST);
        }
    }
}

void SuperJump::_exit_super_jump(Node* body){
    if (body->is_in_group("player")){
        Player* player = dynamic_cast<Player*>(body);
        if (player){
            player->set_jump(JUMP_NORMAL);
        }
    }
}
