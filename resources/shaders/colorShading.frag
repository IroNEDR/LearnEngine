#version 460

// use keyword flat to disable interpolation
in vec2 fragmentPosition;
in vec4 fragmentColor;
in vec2 fragmentUV;
out vec4 color;

uniform float time;
uniform sampler2D textureSampler;

void main() {

    vec4 textureColor = texture(textureSampler, fragmentUV);

    color = vec4(fragmentColor.x *( cos(fragmentPosition.x + time) + 1.0) *0.5,
                 fragmentColor.y *( cos(fragmentPosition.y + time) + 1.0) *0.5,
                 fragmentColor.z *( cos(fragmentPosition.x * 0.4 + time) + 1.0) *0.5,
                 fragmentColor.a
                ) * textureColor;
}