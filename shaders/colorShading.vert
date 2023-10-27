#version 460

in vec2 vertexPosition;
in vec4 vertexColor;
in vec2 vertexUV;

// use keyword flat to disable interpolation
// flat out vec4 fragmentColor;
out vec2 fragmentPosition;
out vec4 fragmentColor;
out vec2 fragmentUV;

void main() {
    gl_Position.xy = vertexPosition;
    gl_Position.z = 0.0;

    // indicate that the coordinates are normalized
    gl_Position.w = 1.0;

    fragmentPosition = vertexPosition;
    fragmentColor = vertexColor;
    fragmentUV = vec2(vertexUV.x, 1.0 - vertexUV.y);
}