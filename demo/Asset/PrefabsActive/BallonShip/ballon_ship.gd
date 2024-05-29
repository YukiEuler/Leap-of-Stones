extends Node3D

var move = false

@onready var path = %PathFollow3D

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass

func _physics_process(delta):
	if move:
		if path.progress_ratio < 0.99:
			path.progress_ratio += 0.0005


func _on_area_3d_body_entered(body):
	if body.is_in_group("player"):
		move = true


func _on_area_3d_body_exited(body):
	pass # Replace with function body.
