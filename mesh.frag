#version 440 core 
out vec4 fColor;
in vec4 outColor;
in vec2 texcoord;
in float e_id;
in vec3 norf;
in vec3 dirf;
in float f_i_marked1;
in float f_i_marked2;
uniform vec2 iResolution;

uniform sampler2D ourTexture;
uniform sampler2D Faces_Vertices;
uniform sampler2D Face_colors;
uniform sampler2D Faces_Index;

struct Pickup_intera{
	float is_pick;
};
uniform Pickup_intera p_intera;
uniform vec2 iMouse;
vec4 trans_code(float a)
{
    //a=a*10000;
    vec4 re;
    re.w=mod(a,256);
    re.z=mod(floor(a/256),256);
    re.y=mod(floor(a/(256*256)),256);
    re.x=mod(floor(a/(256*256*256)),256);
    return re;
}
vec3  chuli_f_i_marked()
{
    float lambda1=-(f_i_marked1-2)*3.0/2.0+(f_i_marked2-4)/2.0;
    float lambda2=(f_i_marked1-2)*2-(f_i_marked2-4);
    vec3 re;
    re.x=lambda1;re.y=lambda2;re.z=1-lambda1-lambda2;
    return re; 

}
void set_fColor(vec2 uv,vec2 coord_uv)
{
	float a=length(texcoord);
	a=sign(a);
	vec4 temp_color1=max(-dot(norf,dirf),0)*texture(ourTexture,texcoord);
	vec4 temp_fColor=temp_color1*a+(1-a)*outColor;

	fColor=(1-p_intera.is_pick)*temp_fColor+p_intera.is_pick*(trans_code(e_id)/256.0);
	
}

void main()
{
	vec2 uv=gl_FragCoord.xy/iResolution.xy;
	vec2 coord_uv=iMouse.xy/iResolution.xy;
	coord_uv.y=1-coord_uv.y;
	set_fColor(uv,coord_uv);
	
}
//0 1 2 -> 0
// 0 2 1 -> 1
// 1 0 2 -> 2
// 1 2 0 -> 3
//2 0 1-> 4
//2 1 0 -> 5
