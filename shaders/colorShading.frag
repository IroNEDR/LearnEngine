#version 460

// use keyword flat to disable interpolation
// flat in vec4 fragmentColor;
in vec2 fragmentPosition;
in vec4 fragmentColor;
in vec2 fragmentUV;
out vec4 color;

uniform float time;
uniform sampler2D mySampler;

void main() {
    // color = fragmentColor + vec4(1.0 * (cos(time)+1.0)*0.5,
    //                             1.0 * (cos(time+2.0) +1.0)*0.5,
    //                             1.0 * (sin(time+1.0)+1.0)*0.5,
    //                             0.0 );

    vec4 textureColor = texture(mySampler, fragmentUV);
    // color = textureColor * fragmentColor;
    color = vec4(fragmentColor.x *( cos(fragmentPosition.x + time) + 1.0) *0.5,
                 fragmentColor.y *( cos(fragmentPosition.y + time) + 1.0) *0.5,
                 fragmentColor.z *( cos(fragmentPosition.x * 0.4 + time) + 1.0) *0.5,
                 fragmentColor.a
                ) * textureColor;
}