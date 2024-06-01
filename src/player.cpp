#include "player.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/label.hpp>

using namespace godot;

void Player::_bind_methods() {
    ClassDB::bind_method(D_METHOD("increment_point"), &Player::increment_point);
}

Player::Player() {
	// Initialize any variables here.
	if (Engine::get_singleton()->is_editor_hint()){
		set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
	}
	point = 0;
	speed = NORMAL_SPEED;
	off_menu = false;
}

Player::~Player() {
	// Add your cleanup here.
}

int Player:: get_point(){
	return this->point;
}

void Player:: set_point(int point){
	this->point = point;
	Node* node = get_node_internal("Player/PlayerUI/Skor");
	if (node){
		Label* label = dynamic_cast<Label*>(node);	
		if (label){
			std::string text = std::to_string(point) + "/10";
			label->set_text(text.c_str());
		}
	}
}

int Player:: get_jump(){
	return this->jump;
}

void Player:: set_jump(int jump){
	this->jump = jump;
}

void Player:: increment_point(){
	set_point(get_point() + 1);
}