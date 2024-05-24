#include "timelabel.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

void TimeLabel::_bind_methods() {
}

TimeLabel::TimeLabel() {
	// Initialize any variables here.
	if (Engine::get_singleton()->is_editor_hint()){
		set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
	}
	time_passed = 0.0;
}

TimeLabel::~TimeLabel() {
	// Add your cleanup here.
}

void TimeLabel::_process(double delta) {
    TimeLabel::show_time();
	time_passed += delta;
}

std::string formatter(int x){
    if (x < 10){
        return "0" + std::to_string(x);
    } else {
        return std::to_string(x);
    }
}
void TimeLabel::show_time(){
    int time_second = time_passed;
    std::string time = formatter(time_second / 60) + ":" + formatter(time_second % 60);
    this->set_text(time.c_str());
}