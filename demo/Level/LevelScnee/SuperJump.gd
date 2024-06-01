extends Area3D


# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass


func _on_body_entered(body):
	pass


func _on_body_exited(body):
	pass


func _enter_super_jump(body):
	if body.is_in_group("player"):
		body.jump_speed = 12


func _exit_super_jump(body):
	if body.is_in_group("player"):
		body.jump_speed = 5
