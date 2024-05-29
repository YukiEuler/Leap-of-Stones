extends CharacterBody3D
const ANGULAR_MOVEMENT : int= 10
var speed
var speed_boost: int = 5
var speed_normal: int = 2
var jump_boost: int = 5
var jump_normal: int= 5
var gravity = ProjectSettings.get_setting("physics/3d/default_gravity")
var jump_speed

var velo = Vector3.ZERO
var snap_vec = Vector3.DOWN

@onready var spring_arm = $SpringArm3D
@onready var model = $Player
@onready var animasi = $Player/AnimationPlayer

func _ready():
	speed = speed_normal
	jump_speed = jump_normal
	
func _input(event):
	if Input.is_action_just_pressed("ui_cancel"):
		get_tree().quit()

func _physics_process(delta):
	var move_dir = Vector3.ZERO
	move_dir.x = Input.get_action_strength("kanan")- Input.get_action_strength("kiri")
	move_dir.z = Input.get_action_strength("bawah")- Input.get_action_strength("atas")
	if Input.is_action_pressed("speed_boost"):
		speed = speed_boost
	else:
		speed = speed_normal
	move_dir = move_dir.rotated(Vector3.UP, spring_arm.rotation.y).normalized()
	velo.x = move_dir.x * speed
	velo.z = move_dir.z * speed
	velo.y -= gravity * delta
	#var just_land = is_on_floor() and snap_vec == Vector3.ZERO

	var just_land :bool= is_on_floor() and snap_vec == Vector3.ZERO
	var is_jump: bool = is_on_floor() and Input.is_action_just_pressed("lompat")

	if is_jump:
		velo.y = jump_speed
		snap_vec = Vector3.ZERO
	elif just_land:
		jump_speed = jump_normal
		snap_vec = Vector3.DOWN


	set_velocity(velo)
	set_up_direction(Vector3.UP)
	set_floor_stop_on_slope_enabled(true)
	move_and_slide()
	velo = velocity
	if is_on_floor() == false:
		animasi.play("Jump")
	else:
		if velo.length() > 0.2:# jalan
			model.rotation.y = lerp_angle(model.rotation.y, atan2(velocity.x, velocity.z), delta * ANGULAR_MOVEMENT)
			#animasi.play("Walking")
			animasi.play("Run")
		else:#berhenti
			animasi.play("Idle")
			animasi.speed_scale = 1
			
func _process(_delta):
	spring_arm.position = position

	#

