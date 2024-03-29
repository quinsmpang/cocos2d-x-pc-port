extern CC_DLL const char* ccETC1ASPositionTextureGray_frag = STRINGIFY(
\n#ifdef GL_ES\n
    precision mediump float;
\n#endif\n

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

void main()
{
    vec4 texColor = texture2D(CC_Texture0, v_texCoord);
    texColor.a = v_fragmentColor.a * texture2D(CC_Texture1, v_texCoord).r;
    texColor.rgb = texColor.rgb * texColor.a;
    
    gl_FragColor.xyz = vec3(0.2126*texColor.r + 0.7152*texColor.g + 0.0722*texColor.b);
    gl_FragColor.a = texColor.a;
}
);
