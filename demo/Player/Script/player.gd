extends CharacterBody3D

var point = 0
var SPEED = 0.0

var off_menu: bool = true
const NORMAL_SPEED = 5.0

const ANGULAR_MOVEMENT = 10

var gravity = ProjectSettings.get_setting("physics/3d/default_gravity")
@onready var health_bar = $PlayerUI/Skor
@onready var player_UI = $PlayerUI
@onready var model = $Model

func  _ready():
	SPEED = NORMAL_SPEED
	player_UI.visible = true

func _process(_delta):
	pass

func _input(_event):
	pass
	#if Input.is_action_just_pressed("ui_cancel") and off_menu == true:
		#player_UI.visible = false
		#off_menu = false
	#elif Input.is_action_just_pressed("ui_cancel") and off_menu == false:
		#player_UI.visible = true
		#off_menu = true

func _physics_process(delta):
	if off_menu:
		pass
	# Add Gravity
	if not is_on_floor():
		velocity.y -= gravity * delta

	# Get the input direction and handle the movement/deceleration.
	var input_dir = Input.get_vector("left", "right", "up", "down")
	var direction = (transform.basis * Vector3(input_dir.x, 0, input_dir.y)).normalized()
	
	if direction:
		velocity.x = direction.x * SPEED
		velocity.z = direction.z * SPEED
	else:
		velocity.x = move_toward(velocity.x, 0, SPEED)
		velocity.z = move_toward(velocity.z, 0, SPEED)
		
	model_rotation(delta)	
	move_and_slide()

func model_rotation(delta):
	#rotation model
	if velocity.x != 0.0 or velocity.z != 0.0 and off_menu == true:
		model.rotation.y = lerp_angle(model.rotation.y, atan2(velocity.x, velocity.z), delta * ANGULAR_MOVEMENT)

