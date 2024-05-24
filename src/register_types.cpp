#include "register_types.h"

#include "gdexample.h"
#include "movementtest.h"
#include "star.h"
#include "player.h"
#include "timelabel.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<GDExample>();
}

void initialize_movement_test(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<MovementTest>();
}

void initialize_star(ModuleInitializationLevel p_level){
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	ClassDB::register_class<Star>();
}

void initialize_player(ModuleInitializationLevel p_level){
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	ClassDB::register_class<Player>();
}

void initialize_timelabel(ModuleInitializationLevel p_level){
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	ClassDB::register_class<TimeLabel>();
}

void initialize_types(ModuleInitializationLevel p_level){
    initialize_example_module(p_level);
    initialize_movement_test(p_level);
	initialize_star(p_level);
	initialize_player(p_level);
	initialize_timelabel(p_level);
}

void uninitialize_types(ModuleInitializationLevel p_level){
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_types);
	init_obj.register_terminator(uninitialize_types);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}