#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
//
// Buffer Definitions: 
//
// cbuffer LightProperties
// {
//
//   float4 EyePosition;                // Offset:    0 Size:    16
//   float4 GlobalAmbient;              // Offset:   16 Size:    16
//   int LightNumber;                   // Offset:   32 Size:     4 [unused]
//   
//   struct Light
//   {
//       
//       float4 Position;               // Offset:   48
//       float4 Direction;              // Offset:   64
//       float4 Color;                  // Offset:   80
//       int LightType;                 // Offset:   96
//       bool Enabled;                  // Offset:  100
//       float minDistance;             // Offset:  104
//       float maxDistance;             // Offset:  108
//       float intensity;               // Offset:  112
//       float minSpotAngle;            // Offset:  116
//       float maxSpotAngle;            // Offset:  120
//       float spotTightness;           // Offset:  124
//
//   } Lights[200];                     // Offset:   48 Size: 16000
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// Sampler                           sampler      NA          NA    0        1
// Texture[0]                        texture  float4          2d    0        1
// Texture[1]                        texture  float4          2d    1        1
// Texture[2]                        texture  float4          2d    2        1
// Texture[3]                        texture  float4          2d    3        1
// LightProperties                   cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// TEXCOORD                 0   xy          0     NONE   float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_TARGET                0   xyzw        0   TARGET   float   xyzw
//
ps_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer cb0[1003], dynamicIndexed
dcl_sampler s0, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t1
dcl_resource_texture2d (float,float,float,float) t2
dcl_resource_texture2d (float,float,float,float) t3
dcl_input_ps linear v0.xy
dcl_output o0.xyzw
dcl_temps 12
mul r0.xy, v0.xyxx, l(1.000000, -1.000000, 0.000000, 0.000000)
sample_indexable(texture2d)(float,float,float,float) r1.xyzw, r0.xyxx, t0.xyzw, s0
sample_indexable(texture2d)(float,float,float,float) r2.xyzw, r0.xyxx, t1.xyzw, s0
sample_indexable(texture2d)(float,float,float,float) r3.xyzw, r0.xyxx, t2.xyzw, s0
sample_indexable(texture2d)(float,float,float,float) r0.xyz, r0.xyxx, t3.xyzw, s0
add r4.xyzw, -r1.xyzw, cb0[0].xyzw
dp4 r0.w, r4.xyzw, r4.xyzw
rsq r0.w, r0.w
mul r4.xyz, r0.wwww, r4.xyzx
mov r5.xyzw, l(0,0,0,0)
mov r6.xyzw, l(0,0,0,0)
mov r0.w, l(0)
loop 
  ige r1.w, r0.w, l(200)
  breakc_nz r1.w
  imul null, r1.w, r0.w, l(5)
  if_z cb0[r1.w + 6].y
    iadd r4.w, r0.w, l(1)
    mov r0.w, r4.w
    continue 
  endif 
  switch cb0[r1.w + 6].x
    case l(0)
    dp3_sat r4.w, r0.xyzx, -cb0[r1.w + 4].xyzx
    mul r7.xyzw, r4.wwww, cb0[r1.w + 5].xyzw
    dp3 r4.w, cb0[r1.w + 4].xyzx, r0.xyzx
    add r4.w, r4.w, r4.w
    mad r9.xyz, r0.xyzx, -r4.wwww, cb0[r1.w + 4].xyzx
    dp3 r4.w, r9.xyzx, r9.xyzx
    rsq r4.w, r4.w
    mul r9.xyz, r4.wwww, r9.xyzx
    dp3_sat r4.w, r9.xyzx, r4.xyzx
    log r4.w, r4.w
    mul r4.w, r3.w, r4.w
    exp r4.w, r4.w
    mul r8.xyzw, r4.wwww, cb0[r1.w + 5].xyzw
    break 
    case l(1)
    add r9.xyz, -r1.xyzx, cb0[r1.w + 3].xyzx
    dp3 r4.w, r9.xyzx, r9.xyzx
    sqrt r9.w, r4.w
    ge r10.x, cb0[r1.w + 6].z, r9.w
    if_nz r10.x
      mov r10.xy, l(1.000000,0,0,0)
    else 
      ge r10.y, r9.w, cb0[r1.w + 6].w
      if_nz r10.y
        mov r7.xyzw, l(0,0,0,0)
        mov r8.xyzw, l(0,0,0,0)
        mov r10.x, l(0)
      else 
        add r10.z, -cb0[r1.w + 6].z, cb0[r1.w + 6].w
        add r9.w, r9.w, -cb0[r1.w + 6].z
        div r10.z, l(1.000000, 1.000000, 1.000000, 1.000000), r10.z
        mul_sat r9.w, r9.w, r10.z
        mad r10.z, r9.w, l(-2.000000), l(3.000000)
        mul r9.w, r9.w, r9.w
        mad r10.x, -r10.z, r9.w, l(1.000000)
      endif 
    endif 
    if_z r10.y
      rsq r4.w, r4.w
      mul r9.xyz, r4.wwww, r9.xyzx
      dp3_sat r4.w, r0.xyzx, r9.xyzx
      mul r11.xyzw, r4.wwww, cb0[r1.w + 5].xyzw
      mul r11.xyzw, r10.xxxx, r11.xyzw
      mul r7.xyzw, r11.xyzw, cb0[r1.w + 7].xxxx
      dp3 r4.w, -r9.xyzx, r0.xyzx
      add r4.w, r4.w, r4.w
      mad r9.xyz, r0.xyzx, -r4.wwww, -r9.xyzx
      dp3 r4.w, r9.xyzx, r9.xyzx
      rsq r4.w, r4.w
      mul r9.xyz, r4.wwww, r9.xyzx
      dp3_sat r4.w, r9.xyzx, r4.xyzx
      log r4.w, r4.w
      mul r4.w, r3.w, r4.w
      exp r4.w, r4.w
      mul r9.xyzw, r4.wwww, cb0[r1.w + 5].xyzw
      mul r9.xyzw, r10.xxxx, r9.xyzw
      mul r8.xyzw, r9.xyzw, cb0[r1.w + 7].xxxx
    endif 
    break 
    case l(2)
    add r9.xyz, r1.xyzx, -cb0[r1.w + 3].xyzx
    dp3 r4.w, r9.xyzx, r9.xyzx
    rsq r4.w, r4.w
    mul r9.xyz, r4.wwww, r9.xyzx
    dp3 r4.w, cb0[r1.w + 4].xyzx, r9.xyzx
    sincos null, r9.w, cb0[r1.w + 7].y
    ge r10.x, r4.w, r9.w
    if_nz r10.x
      mov r10.xy, l(1.000000,0,0,0)
    else 
      sincos null, r10.z, cb0[r1.w + 7].z
      lt r10.w, r10.z, r4.w
      lt r11.x, r4.w, r9.w
      and r10.w, r10.w, r11.x
      if_nz r10.w
        add r10.w, r4.w, -r10.z
        add r9.w, r9.w, -r10.z
        div r9.w, r10.w, r9.w
        log r9.w, r9.w
        mul r9.w, r9.w, cb0[r1.w + 7].w
        exp r10.x, r9.w
        mov r10.y, l(0)
      else 
        ge r10.y, r10.z, r4.w
        mov r7.xyzw, l(0,0,0,0)
        mov r8.xyzw, l(0,0,0,0)
        mov r10.x, l(0)
      endif 
    endif 
    if_z r10.y
      dp3_sat r4.w, r0.xyzx, -r9.xyzx
      mul r11.xyzw, r4.wwww, cb0[r1.w + 5].xyzw
      mul r11.xyzw, r10.xxxx, r11.xyzw
      mul r7.xyzw, r11.xyzw, cb0[r1.w + 7].xxxx
      dp3 r4.w, r9.xyzx, r0.xyzx
      add r4.w, r4.w, r4.w
      mad r9.xyz, r0.xyzx, -r4.wwww, r9.xyzx
      dp3 r4.w, r9.xyzx, r9.xyzx
      rsq r4.w, r4.w
      mul r9.xyz, r4.wwww, r9.xyzx
      dp3_sat r4.w, r9.xyzx, r4.xyzx
      log r4.w, r4.w
      mul r4.w, r3.w, r4.w
      exp r4.w, r4.w
      mul r9.xyzw, r4.wwww, cb0[r1.w + 5].xyzw
      mul r9.xyzw, r10.xxxx, r9.xyzw
      mul r8.xyzw, r9.xyzw, cb0[r1.w + 7].xxxx
    endif 
    break 
    default 
    mov r7.xyzw, l(0,0,0,0)
    mov r8.xyzw, l(0,0,0,0)
    break 
  endswitch 
  add r5.xyzw, r5.xyzw, r7.xyzw
  add r6.xyzw, r6.xyzw, r8.xyzw
  iadd r0.w, r0.w, l(1)
endloop 
mov_sat r5.xyzw, r5.xyzw
mov_sat r6.xyzw, r6.xyzw
mul r0.xyzw, r2.xyzw, r5.xyzw
mov r3.w, l(1.000000)
mul r1.xyzw, r6.xyzw, r3.xyzw
mov r2.x, l(0)
mov r2.w, r0.w
mad r2.xyzw, cb0[1].xyzw, l(0.010000, 0.010000, 0.010000, 0.010000), r2.xxxw
mov r0.w, r1.w
add r0.xyzw, r0.xyzw, r2.xyzw
mov r1.w, l(1.000000)
add o0.xyzw, r0.xyzw, r1.xyzw
ret 
// Approximately 154 instruction slots used
#endif

const BYTE g_LightningPassPixelShader[] =
{
     68,  88,  66,  67, 107, 255, 
    190, 243, 106, 104, 104,  58, 
    210, 178, 224,  94, 166, 149, 
     62, 103,   1,   0,   0,   0, 
    196,  21,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    180,   4,   0,   0, 232,   4, 
      0,   0,  28,   5,   0,   0, 
     40,  21,   0,   0,  82,  68, 
     69,  70, 120,   4,   0,   0, 
      1,   0,   0,   0,  64,   1, 
      0,   0,   6,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
    255, 255,   0,   1,   0,   0, 
     68,   4,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    252,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   4,   1,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     12,   0,   0,   0,  15,   1, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  12,   0,   0,   0, 
     26,   1,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   2,   0,   0,   0, 
      1,   0,   0,   0,  12,   0, 
      0,   0,  37,   1,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     12,   0,   0,   0,  48,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     83,  97, 109, 112, 108, 101, 
    114,   0,  84, 101, 120, 116, 
    117, 114, 101,  91,  48,  93, 
      0,  84, 101, 120, 116, 117, 
    114, 101,  91,  49,  93,   0, 
     84, 101, 120, 116, 117, 114, 
    101,  91,  50,  93,   0,  84, 
    101, 120, 116, 117, 114, 101, 
     91,  51,  93,   0,  76, 105, 
    103, 104, 116,  80, 114, 111, 
    112, 101, 114, 116, 105, 101, 
    115,   0,  48,   1,   0,   0, 
      4,   0,   0,   0,  88,   1, 
      0,   0, 176,  62,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 248,   1,   0,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
     12,   2,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     48,   2,   0,   0,  16,   0, 
      0,   0,  16,   0,   0,   0, 
      2,   0,   0,   0,  12,   2, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  62,   2, 
      0,   0,  32,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,  80,   2,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 116,   2,   0,   0, 
     48,   0,   0,   0, 128,  62, 
      0,   0,   2,   0,   0,   0, 
     32,   4,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     69, 121, 101,  80, 111, 115, 
    105, 116, 105, 111, 110,   0, 
    102, 108, 111,  97, 116,  52, 
      0, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   4,   2, 
      0,   0,  71, 108, 111,  98, 
     97, 108,  65, 109,  98, 105, 
    101, 110, 116,   0,  76, 105, 
    103, 104, 116,  78, 117, 109, 
     98, 101, 114,   0, 105, 110, 
    116,   0, 171, 171,   0,   0, 
      2,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     74,   2,   0,   0,  76, 105, 
    103, 104, 116, 115,   0,  76, 
    105, 103, 104, 116,   0,  80, 
    111, 115, 105, 116, 105, 111, 
    110,   0, 171, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      4,   2,   0,   0,  68, 105, 
    114, 101,  99, 116, 105, 111, 
    110,   0,  67, 111, 108, 111, 
    114,   0,  76, 105, 103, 104, 
    116,  84, 121, 112, 101,   0, 
    171, 171,   0,   0,   2,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  74,   2, 
      0,   0,  69, 110,  97,  98, 
    108, 101, 100,   0,  98, 111, 
    111, 108,   0, 171, 171, 171, 
      0,   0,   1,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 248,   2,   0,   0, 
    109, 105, 110,  68, 105, 115, 
    116,  97, 110,  99, 101,   0, 
    102, 108, 111,  97, 116,   0, 
    171, 171,   0,   0,   3,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  48,   3, 
      0,   0, 109,  97, 120,  68, 
    105, 115, 116,  97, 110,  99, 
    101,   0, 105, 110, 116, 101, 
    110, 115, 105, 116, 121,   0, 
    109, 105, 110,  83, 112, 111, 
    116,  65, 110, 103, 108, 101, 
      0, 109,  97, 120,  83, 112, 
    111, 116,  65, 110, 103, 108, 
    101,   0, 115, 112, 111, 116, 
     84, 105, 103, 104, 116, 110, 
    101, 115, 115,   0, 171, 171, 
    129,   2,   0,   0, 140,   2, 
      0,   0,   0,   0,   0,   0, 
    176,   2,   0,   0, 140,   2, 
      0,   0,  16,   0,   0,   0, 
    186,   2,   0,   0, 140,   2, 
      0,   0,  32,   0,   0,   0, 
    192,   2,   0,   0, 204,   2, 
      0,   0,  48,   0,   0,   0, 
    240,   2,   0,   0,   0,   3, 
      0,   0,  52,   0,   0,   0, 
     36,   3,   0,   0,  56,   3, 
      0,   0,  56,   0,   0,   0, 
     92,   3,   0,   0,  56,   3, 
      0,   0,  60,   0,   0,   0, 
    104,   3,   0,   0,  56,   3, 
      0,   0,  64,   0,   0,   0, 
    114,   3,   0,   0,  56,   3, 
      0,   0,  68,   0,   0,   0, 
    127,   3,   0,   0,  56,   3, 
      0,   0,  72,   0,   0,   0, 
    140,   3,   0,   0,  56,   3, 
      0,   0,  76,   0,   0,   0, 
      5,   0,   0,   0,   1,   0, 
     20,   0, 200,   0,  11,   0, 
    156,   3,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 123,   2,   0,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  54, 
     46,  51,  46,  57,  54,  48, 
     48,  46,  49,  54,  51,  56, 
     52,   0, 171, 171,  73,  83, 
     71,  78,  44,   0,   0,   0, 
      1,   0,   0,   0,   8,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   3,   3, 
      0,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0, 171, 
    171, 171,  79,  83,  71,  78, 
     44,   0,   0,   0,   1,   0, 
      0,   0,   8,   0,   0,   0, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     83,  86,  95,  84,  65,  82, 
     71,  69,  84,   0, 171, 171, 
     83,  72,  69,  88,   4,  16, 
      0,   0,  80,   0,   0,   0, 
      1,   4,   0,   0, 106,   8, 
      0,   1,  89,   8,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0, 235,   3,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   0,   0,   0,   0, 
     85,  85,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      1,   0,   0,   0,  85,  85, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   2,   0, 
      0,   0,  85,  85,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   3,   0,   0,   0, 
     85,  85,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      0,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      0,   0,   0,   0, 104,   0, 
      0,   2,  12,   0,   0,   0, 
     56,   0,   0,  10,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  16,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128, 191,   0,   0,   0,   0, 
      0,   0,   0,   0,  69,   0, 
      0, 139, 194,   0,   0, 128, 
     67,  85,  21,   0, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     69,   0,   0, 139, 194,   0, 
      0, 128,  67,  85,  21,   0, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     16,   0,   1,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  69,   0,   0, 139, 
    194,   0,   0, 128,  67,  85, 
     21,   0, 242,   0,  16,   0, 
      3,   0,   0,   0,  70,   0, 
     16,   0,   0,   0,   0,   0, 
     70, 126,  16,   0,   2,   0, 
      0,   0,   0,  96,  16,   0, 
      0,   0,   0,   0,  69,   0, 
      0, 139, 194,   0,   0, 128, 
     67,  85,  21,   0, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0,  70, 126,  16,   0, 
      3,   0,   0,   0,   0,  96, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   0,   9, 242,   0, 
     16,   0,   4,   0,   0,   0, 
     70,  14,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     17,   0,   0,   7, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   4,   0, 
      0,   0,  70,  14,  16,   0, 
      4,   0,   0,   0,  68,   0, 
      0,   5, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   4,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      4,   0,   0,   0,  54,   0, 
      0,   8, 242,   0,  16,   0, 
      5,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   8, 242,   0, 
     16,   0,   6,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  54,   0,   0,   5, 
    130,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  48,   0, 
      0,   1,  33,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0, 200,   0,   0,   0, 
      3,   0,   4,   3,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     38,   0,   0,   8,   0, 208, 
      0,   0, 130,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   5,   0, 
      0,   0,  31,   0,   0,   6, 
     26, 128,  32,   6,   0,   0, 
      0,   0,   6,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  30,   0,   0,   7, 
    130,   0,  16,   0,   4,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   1,   0,   0,   0, 
     54,   0,   0,   5, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   4,   0, 
      0,   0,   7,   0,   0,   1, 
     21,   0,   0,   1,  76,   0, 
      0,   6,  10, 128,  32,   6, 
      0,   0,   0,   0,   6,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,   6,   0, 
      0,   3,   1,  64,   0,   0, 
      0,   0,   0,   0,  16,  32, 
      0,  11, 130,   0,  16,   0, 
      4,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     70, 130,  32, 134,  65,   0, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,  10, 242,   0, 
     16,   0,   7,   0,   0,   0, 
    246,  15,  16,   0,   4,   0, 
      0,   0,  70, 142,  32,   6, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  16,   0, 
      0,  10, 130,   0,  16,   0, 
      4,   0,   0,   0,  70, 130, 
     32,   6,   0,   0,   0,   0, 
      4,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   7, 
    130,   0,  16,   0,   4,   0, 
      0,   0,  58,   0,  16,   0, 
      4,   0,   0,   0,  58,   0, 
     16,   0,   4,   0,   0,   0, 
     50,   0,   0,  13, 114,   0, 
     16,   0,   9,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0, 246,  15,  16, 128, 
     65,   0,   0,   0,   4,   0, 
      0,   0,  70, 130,  32,   6, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  16,   0, 
      0,   7, 130,   0,  16,   0, 
      4,   0,   0,   0,  70,   2, 
     16,   0,   9,   0,   0,   0, 
     70,   2,  16,   0,   9,   0, 
      0,   0,  68,   0,   0,   5, 
    130,   0,  16,   0,   4,   0, 
      0,   0,  58,   0,  16,   0, 
      4,   0,   0,   0,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      9,   0,   0,   0, 246,  15, 
     16,   0,   4,   0,   0,   0, 
     70,   2,  16,   0,   9,   0, 
      0,   0,  16,  32,   0,   7, 
    130,   0,  16,   0,   4,   0, 
      0,   0,  70,   2,  16,   0, 
      9,   0,   0,   0,  70,   2, 
     16,   0,   4,   0,   0,   0, 
     47,   0,   0,   5, 130,   0, 
     16,   0,   4,   0,   0,   0, 
     58,   0,  16,   0,   4,   0, 
      0,   0,  56,   0,   0,   7, 
    130,   0,  16,   0,   4,   0, 
      0,   0,  58,   0,  16,   0, 
      3,   0,   0,   0,  58,   0, 
     16,   0,   4,   0,   0,   0, 
     25,   0,   0,   5, 130,   0, 
     16,   0,   4,   0,   0,   0, 
     58,   0,  16,   0,   4,   0, 
      0,   0,  56,   0,   0,  10, 
    242,   0,  16,   0,   8,   0, 
      0,   0, 246,  15,  16,   0, 
      4,   0,   0,   0,  70, 142, 
     32,   6,   0,   0,   0,   0, 
      5,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
      2,   0,   0,   1,   6,   0, 
      0,   3,   1,  64,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,  11, 114,   0,  16,   0, 
      9,   0,   0,   0,  70,   2, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,  70, 130, 
     32,   6,   0,   0,   0,   0, 
      3,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     16,   0,   0,   7, 130,   0, 
     16,   0,   4,   0,   0,   0, 
     70,   2,  16,   0,   9,   0, 
      0,   0,  70,   2,  16,   0, 
      9,   0,   0,   0,  75,   0, 
      0,   5, 130,   0,  16,   0, 
      9,   0,   0,   0,  58,   0, 
     16,   0,   4,   0,   0,   0, 
     29,   0,   0,  10,  18,   0, 
     16,   0,  10,   0,   0,   0, 
     42, 128,  32,   6,   0,   0, 
      0,   0,   6,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      9,   0,   0,   0,  31,   0, 
      4,   3,  10,   0,  16,   0, 
     10,   0,   0,   0,  54,   0, 
      0,   8,  50,   0,  16,   0, 
     10,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     18,   0,   0,   1,  29,   0, 
      0,  10,  34,   0,  16,   0, 
     10,   0,   0,   0,  58,   0, 
     16,   0,   9,   0,   0,   0, 
     58, 128,  32,   6,   0,   0, 
      0,   0,   6,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  31,   0,   4,   3, 
     26,   0,  16,   0,  10,   0, 
      0,   0,  54,   0,   0,   8, 
    242,   0,  16,   0,   7,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   8, 242,   0,  16,   0, 
      8,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   5,  18,   0, 
     16,   0,  10,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  18,   0,   0,   1, 
      0,   0,   0,  14,  66,   0, 
     16,   0,  10,   0,   0,   0, 
     42, 128,  32, 134,  65,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     58, 128,  32,   6,   0,   0, 
      0,   0,   6,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,   0,   0,   0,  11, 
    130,   0,  16,   0,   9,   0, 
      0,   0,  58,   0,  16,   0, 
      9,   0,   0,   0,  42, 128, 
     32, 134,  65,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  14,   0, 
      0,  10,  66,   0,  16,   0, 
     10,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
     42,   0,  16,   0,  10,   0, 
      0,   0,  56,  32,   0,   7, 
    130,   0,  16,   0,   9,   0, 
      0,   0,  58,   0,  16,   0, 
      9,   0,   0,   0,  42,   0, 
     16,   0,  10,   0,   0,   0, 
     50,   0,   0,   9,  66,   0, 
     16,   0,  10,   0,   0,   0, 
     58,   0,  16,   0,   9,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0, 192,   1,  64, 
      0,   0,   0,   0,  64,  64, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   9,   0,   0,   0, 
     58,   0,  16,   0,   9,   0, 
      0,   0,  58,   0,  16,   0, 
      9,   0,   0,   0,  50,   0, 
      0,  10,  18,   0,  16,   0, 
     10,   0,   0,   0,  42,   0, 
     16, 128,  65,   0,   0,   0, 
     10,   0,   0,   0,  58,   0, 
     16,   0,   9,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  21,   0,   0,   1, 
     21,   0,   0,   1,  31,   0, 
      0,   3,  26,   0,  16,   0, 
     10,   0,   0,   0,  68,   0, 
      0,   5, 130,   0,  16,   0, 
      4,   0,   0,   0,  58,   0, 
     16,   0,   4,   0,   0,   0, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   9,   0,   0,   0, 
    246,  15,  16,   0,   4,   0, 
      0,   0,  70,   2,  16,   0, 
      9,   0,   0,   0,  16,  32, 
      0,   7, 130,   0,  16,   0, 
      4,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   9,   0, 
      0,   0,  56,   0,   0,  10, 
    242,   0,  16,   0,  11,   0, 
      0,   0, 246,  15,  16,   0, 
      4,   0,   0,   0,  70, 142, 
     32,   6,   0,   0,   0,   0, 
      5,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   7, 242,   0, 
     16,   0,  11,   0,   0,   0, 
      6,   0,  16,   0,  10,   0, 
      0,   0,  70,  14,  16,   0, 
     11,   0,   0,   0,  56,   0, 
      0,  10, 242,   0,  16,   0, 
      7,   0,   0,   0,  70,  14, 
     16,   0,  11,   0,   0,   0, 
      6, 128,  32,   6,   0,   0, 
      0,   0,   7,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  16,   0,   0,   8, 
    130,   0,  16,   0,   4,   0, 
      0,   0,  70,   2,  16, 128, 
     65,   0,   0,   0,   9,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   7, 130,   0,  16,   0, 
      4,   0,   0,   0,  58,   0, 
     16,   0,   4,   0,   0,   0, 
     58,   0,  16,   0,   4,   0, 
      0,   0,  50,   0,   0,  11, 
    114,   0,  16,   0,   9,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0, 246,  15, 
     16, 128,  65,   0,   0,   0, 
      4,   0,   0,   0,  70,   2, 
     16, 128,  65,   0,   0,   0, 
      9,   0,   0,   0,  16,   0, 
      0,   7, 130,   0,  16,   0, 
      4,   0,   0,   0,  70,   2, 
     16,   0,   9,   0,   0,   0, 
     70,   2,  16,   0,   9,   0, 
      0,   0,  68,   0,   0,   5, 
    130,   0,  16,   0,   4,   0, 
      0,   0,  58,   0,  16,   0, 
      4,   0,   0,   0,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      9,   0,   0,   0, 246,  15, 
     16,   0,   4,   0,   0,   0, 
     70,   2,  16,   0,   9,   0, 
      0,   0,  16,  32,   0,   7, 
    130,   0,  16,   0,   4,   0, 
      0,   0,  70,   2,  16,   0, 
      9,   0,   0,   0,  70,   2, 
     16,   0,   4,   0,   0,   0, 
     47,   0,   0,   5, 130,   0, 
     16,   0,   4,   0,   0,   0, 
     58,   0,  16,   0,   4,   0, 
      0,   0,  56,   0,   0,   7, 
    130,   0,  16,   0,   4,   0, 
      0,   0,  58,   0,  16,   0, 
      3,   0,   0,   0,  58,   0, 
     16,   0,   4,   0,   0,   0, 
     25,   0,   0,   5, 130,   0, 
     16,   0,   4,   0,   0,   0, 
     58,   0,  16,   0,   4,   0, 
      0,   0,  56,   0,   0,  10, 
    242,   0,  16,   0,   9,   0, 
      0,   0, 246,  15,  16,   0, 
      4,   0,   0,   0,  70, 142, 
     32,   6,   0,   0,   0,   0, 
      5,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   7, 242,   0, 
     16,   0,   9,   0,   0,   0, 
      6,   0,  16,   0,  10,   0, 
      0,   0,  70,  14,  16,   0, 
      9,   0,   0,   0,  56,   0, 
      0,  10, 242,   0,  16,   0, 
      8,   0,   0,   0,  70,  14, 
     16,   0,   9,   0,   0,   0, 
      6, 128,  32,   6,   0,   0, 
      0,   0,   7,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  21,   0,   0,   1, 
      2,   0,   0,   1,   6,   0, 
      0,   3,   1,  64,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,  11, 114,   0,  16,   0, 
      9,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70, 130,  32, 134,  65,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     16,   0,   0,   7, 130,   0, 
     16,   0,   4,   0,   0,   0, 
     70,   2,  16,   0,   9,   0, 
      0,   0,  70,   2,  16,   0, 
      9,   0,   0,   0,  68,   0, 
      0,   5, 130,   0,  16,   0, 
      4,   0,   0,   0,  58,   0, 
     16,   0,   4,   0,   0,   0, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   9,   0,   0,   0, 
    246,  15,  16,   0,   4,   0, 
      0,   0,  70,   2,  16,   0, 
      9,   0,   0,   0,  16,   0, 
      0,  10, 130,   0,  16,   0, 
      4,   0,   0,   0,  70, 130, 
     32,   6,   0,   0,   0,   0, 
      4,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   9,   0, 
      0,   0,  77,   0,   0,   9, 
      0, 208,   0,   0, 130,   0, 
     16,   0,   9,   0,   0,   0, 
     26, 128,  32,   6,   0,   0, 
      0,   0,   7,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  29,   0,   0,   7, 
     18,   0,  16,   0,  10,   0, 
      0,   0,  58,   0,  16,   0, 
      4,   0,   0,   0,  58,   0, 
     16,   0,   9,   0,   0,   0, 
     31,   0,   4,   3,  10,   0, 
     16,   0,  10,   0,   0,   0, 
     54,   0,   0,   8,  50,   0, 
     16,   0,  10,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128,  63,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  18,   0,   0,   1, 
     77,   0,   0,   9,   0, 208, 
      0,   0,  66,   0,  16,   0, 
     10,   0,   0,   0,  42, 128, 
     32,   6,   0,   0,   0,   0, 
      7,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     49,   0,   0,   7, 130,   0, 
     16,   0,  10,   0,   0,   0, 
     42,   0,  16,   0,  10,   0, 
      0,   0,  58,   0,  16,   0, 
      4,   0,   0,   0,  49,   0, 
      0,   7,  18,   0,  16,   0, 
     11,   0,   0,   0,  58,   0, 
     16,   0,   4,   0,   0,   0, 
     58,   0,  16,   0,   9,   0, 
      0,   0,   1,   0,   0,   7, 
    130,   0,  16,   0,  10,   0, 
      0,   0,  58,   0,  16,   0, 
     10,   0,   0,   0,  10,   0, 
     16,   0,  11,   0,   0,   0, 
     31,   0,   4,   3,  58,   0, 
     16,   0,  10,   0,   0,   0, 
      0,   0,   0,   8, 130,   0, 
     16,   0,  10,   0,   0,   0, 
     58,   0,  16,   0,   4,   0, 
      0,   0,  42,   0,  16, 128, 
     65,   0,   0,   0,  10,   0, 
      0,   0,   0,   0,   0,   8, 
    130,   0,  16,   0,   9,   0, 
      0,   0,  58,   0,  16,   0, 
      9,   0,   0,   0,  42,   0, 
     16, 128,  65,   0,   0,   0, 
     10,   0,   0,   0,  14,   0, 
      0,   7, 130,   0,  16,   0, 
      9,   0,   0,   0,  58,   0, 
     16,   0,  10,   0,   0,   0, 
     58,   0,  16,   0,   9,   0, 
      0,   0,  47,   0,   0,   5, 
    130,   0,  16,   0,   9,   0, 
      0,   0,  58,   0,  16,   0, 
      9,   0,   0,   0,  56,   0, 
      0,  10, 130,   0,  16,   0, 
      9,   0,   0,   0,  58,   0, 
     16,   0,   9,   0,   0,   0, 
     58, 128,  32,   6,   0,   0, 
      0,   0,   7,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  25,   0,   0,   5, 
     18,   0,  16,   0,  10,   0, 
      0,   0,  58,   0,  16,   0, 
      9,   0,   0,   0,  54,   0, 
      0,   5,  34,   0,  16,   0, 
     10,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     18,   0,   0,   1,  29,   0, 
      0,   7,  34,   0,  16,   0, 
     10,   0,   0,   0,  42,   0, 
     16,   0,  10,   0,   0,   0, 
     58,   0,  16,   0,   4,   0, 
      0,   0,  54,   0,   0,   8, 
    242,   0,  16,   0,   7,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   8, 242,   0,  16,   0, 
      8,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   5,  18,   0, 
     16,   0,  10,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  21,   0,   0,   1, 
     21,   0,   0,   1,  31,   0, 
      0,   3,  26,   0,  16,   0, 
     10,   0,   0,   0,  16,  32, 
      0,   8, 130,   0,  16,   0, 
      4,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16, 128,  65,   0, 
      0,   0,   9,   0,   0,   0, 
     56,   0,   0,  10, 242,   0, 
     16,   0,  11,   0,   0,   0, 
    246,  15,  16,   0,   4,   0, 
      0,   0,  70, 142,  32,   6, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   7, 242,   0,  16,   0, 
     11,   0,   0,   0,   6,   0, 
     16,   0,  10,   0,   0,   0, 
     70,  14,  16,   0,  11,   0, 
      0,   0,  56,   0,   0,  10, 
    242,   0,  16,   0,   7,   0, 
      0,   0,  70,  14,  16,   0, 
     11,   0,   0,   0,   6, 128, 
     32,   6,   0,   0,   0,   0, 
      7,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     16,   0,   0,   7, 130,   0, 
     16,   0,   4,   0,   0,   0, 
     70,   2,  16,   0,   9,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   7, 130,   0,  16,   0, 
      4,   0,   0,   0,  58,   0, 
     16,   0,   4,   0,   0,   0, 
     58,   0,  16,   0,   4,   0, 
      0,   0,  50,   0,   0,  10, 
    114,   0,  16,   0,   9,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0, 246,  15, 
     16, 128,  65,   0,   0,   0, 
      4,   0,   0,   0,  70,   2, 
     16,   0,   9,   0,   0,   0, 
     16,   0,   0,   7, 130,   0, 
     16,   0,   4,   0,   0,   0, 
     70,   2,  16,   0,   9,   0, 
      0,   0,  70,   2,  16,   0, 
      9,   0,   0,   0,  68,   0, 
      0,   5, 130,   0,  16,   0, 
      4,   0,   0,   0,  58,   0, 
     16,   0,   4,   0,   0,   0, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   9,   0,   0,   0, 
    246,  15,  16,   0,   4,   0, 
      0,   0,  70,   2,  16,   0, 
      9,   0,   0,   0,  16,  32, 
      0,   7, 130,   0,  16,   0, 
      4,   0,   0,   0,  70,   2, 
     16,   0,   9,   0,   0,   0, 
     70,   2,  16,   0,   4,   0, 
      0,   0,  47,   0,   0,   5, 
    130,   0,  16,   0,   4,   0, 
      0,   0,  58,   0,  16,   0, 
      4,   0,   0,   0,  56,   0, 
      0,   7, 130,   0,  16,   0, 
      4,   0,   0,   0,  58,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16,   0,   4,   0, 
      0,   0,  25,   0,   0,   5, 
    130,   0,  16,   0,   4,   0, 
      0,   0,  58,   0,  16,   0, 
      4,   0,   0,   0,  56,   0, 
      0,  10, 242,   0,  16,   0, 
      9,   0,   0,   0, 246,  15, 
     16,   0,   4,   0,   0,   0, 
     70, 142,  32,   6,   0,   0, 
      0,   0,   5,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   7, 
    242,   0,  16,   0,   9,   0, 
      0,   0,   6,   0,  16,   0, 
     10,   0,   0,   0,  70,  14, 
     16,   0,   9,   0,   0,   0, 
     56,   0,   0,  10, 242,   0, 
     16,   0,   8,   0,   0,   0, 
     70,  14,  16,   0,   9,   0, 
      0,   0,   6, 128,  32,   6, 
      0,   0,   0,   0,   7,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  21,   0, 
      0,   1,   2,   0,   0,   1, 
     10,   0,   0,   1,  54,   0, 
      0,   8, 242,   0,  16,   0, 
      7,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   8, 242,   0, 
     16,   0,   8,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   1, 
     23,   0,   0,   1,   0,   0, 
      0,   7, 242,   0,  16,   0, 
      5,   0,   0,   0,  70,  14, 
     16,   0,   5,   0,   0,   0, 
     70,  14,  16,   0,   7,   0, 
      0,   0,   0,   0,   0,   7, 
    242,   0,  16,   0,   6,   0, 
      0,   0,  70,  14,  16,   0, 
      6,   0,   0,   0,  70,  14, 
     16,   0,   8,   0,   0,   0, 
     30,   0,   0,   7, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      1,   0,   0,   0,  22,   0, 
      0,   1,  54,  32,   0,   5, 
    242,   0,  16,   0,   5,   0, 
      0,   0,  70,  14,  16,   0, 
      5,   0,   0,   0,  54,  32, 
      0,   5, 242,   0,  16,   0, 
      6,   0,   0,   0,  70,  14, 
     16,   0,   6,   0,   0,   0, 
     56,   0,   0,   7, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      5,   0,   0,   0,  54,   0, 
      0,   5, 130,   0,  16,   0, 
      3,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     56,   0,   0,   7, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   6,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  54,   0, 
      0,   5,  18,   0,  16,   0, 
      2,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   5, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  50,   0,   0,  13, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
     10, 215,  35,  60,  10, 215, 
     35,  60,  10, 215,  35,  60, 
     10, 215,  35,  60,   6,  12, 
     16,   0,   2,   0,   0,   0, 
     54,   0,   0,   5, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,   0,   0,   0,   7, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     54,   0,   0,   5, 130,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,   0,   0,   0,   7, 
    242,  32,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 148,   0,   0,   0, 
    154,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,  90,   0, 
      0,   0,   4,   0,   0,   0, 
      1,   0,   0,   0,  12,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  22,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0
};
