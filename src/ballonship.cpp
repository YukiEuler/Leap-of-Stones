#include "ballonship.h"
#include "player.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/path_follow3d.hpp>

using namespace godot;

void BallonShip::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_area_3d_body_entered", "body"), &BallonShip::_on_area_3d_body_entered);
    ClassDB::bind_method(D_METHOD("_on_area_3d_body_exited", "body"), &BallonShip::_on_area_3d_body_exited);
}

BallonShip::BallonShip() {
	// Initialize any variables here.
	if (Engine::get_singleton()->is_editor_hint()){
		set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
	}
	connect("body_entered", Callable(this, "_on_area_3d_body_entered"));
    connect("body_exited", Callable(this, "_on_area_3d_body_exited"));
    move = 0;
}

BallonShip::~BallonShip() {
	// Add your cleanup here.
}

void BallonShip::_on_area_3d_body_entered(Node* body) {
    if (body->is_in_group("player")){
        move = 1;
    }
}

void BallonShip::_on_area_3d_body_exited(Node* body){
    if (body->is_in_group("player")){
        move = 0;
    }
}

void BallonShip::_process(double delta) {
    if (move){
        Node* node = get_node_internal("%PathFollow3D");
        if (node){
            PathFollow3D* path = dynamic_cast<PathFollow3D*>(node);
            if (path){
                if (path->get_progress_ratio() < 0.99){
                    path->set_progress_ratio(path->get_progress_ratio() + 0.001);
                }
            }
        }
    }
}
