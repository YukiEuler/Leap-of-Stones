shader_type spatial;


uniform sampler2D caustics_texture : source_color ;
uniform sampler2D color_gradient : source_color ;
uniform sampler2D distort_noise : source_color ;

uniform float flow_speed = 0.3;
uniform float vignette_size = 0.3;
uniform float vignette_blend = 0.1;
uniform float distort_strength = 0.1;
uniform float disc_speed = 0.5;

const float CIRCLE_CONSTANT = 6.283185307;

vec2 polar_coordinates(vec2 uv, vec2 center, float zoom, float repeat)
{
	vec2 dir = uv - center;
	highp float radius = length(dir) * 2.0;
	highp float angle = atan(dir.y, dir.x) / CIRCLE_CONSTANT;
	return mod(vec2(radius * zoom, angle * repeat), 1.0);
}

void vertex(){
	float dn = texture(distort_noise, UV + TIME * 0.1).r;
	VERTEX.y += dn * 0.1;
}

void fragment(){
	// Polar UVs + Noise for caustics
	vec2 base_uv = UV;
	float dn = texture(distort_noise, UV + TIME * 0.1).r;
	base_uv += dn * distort_strength;
	base_uv -= distort_strength / 2.0;
	highp vec2 polar_uv = polar_coordinates(base_uv, vec2(0.5), 1.0, 1.0);
	polar_uv.x -= TIME * flow_speed;
	float caus = texture(caustics_texture, polar_uv).r;
	
	// Fade out caustics
	float cd = distance(UV, vec2(0.5));
	float vign = 1.0 - smoothstep(vignette_size, vignette_size + vignette_blend, cd);
	
	// Color the caustics
	float grad_uv = caus * vign;
	vec3 color = texture(color_gradient, vec2(grad_uv)).rgb;
	
	// Center discs
	float global_disc = 0.0;
	for (int i = 0; i < 20; i++){
		float offset = float(i) * 0.2;
		float radius_disc = 0.8;
		float loop = fract((TIME + offset) * disc_speed) * radius_disc;
		float disc = smoothstep(cd, cd + 0.01, loop);
		float fade = abs(loop - radius_disc);
		fade = pow(fade, 5.0);
		disc *= fade;
		disc = clamp(disc, 0.0, 1.0);
		global_disc += disc;
	}
	global_disc *= 0.6;
	
	ALBEDO = color + global_disc;
}