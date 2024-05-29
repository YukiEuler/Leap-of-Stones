extends SpringArm3D

const MAX_ZOOM = 4
const MIN_ZOOM = 2
const SPEED_ZOOM: float = 0.2
var mouse_sense = 0.05
var disable_cam:bool = false
@onready var cam = $Camera3D


func _ready():
	set_as_top_level(true)
	Input.set_mouse_mode(Input.MOUSE_MODE_CAPTURED)
	

func _input(event):
	#if disable_cam != true:
	if event is InputEventMouseButton:
		if event.is_pressed():
			if event.button_index == MOUSE_BUTTON_WHEEL_UP:
				if spring_length >MIN_ZOOM:
					spring_length -= SPEED_ZOOM
			elif event.button_index ==  MOUSE_BUTTON_WHEEL_DOWN:
				if spring_length < MAX_ZOOM:
					spring_length += SPEED_ZOOM
	if event is InputEventMouseMotion:
		rotation.x -= event.relative.y*0.005
		rotation.y -= event.relative.x*0.005
		rotation.x = clamp(rotation.x, deg_to_rad(-85), deg_to_rad(85))
