/*
 * Copyright 2007,2010 Vijay Kiran Kamuju
 * Copyright 2007 David ADAM
 * Copyright 2010 Christian Costa
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __D3DRMDEFS_H__
#define __D3DRMDEFS_H__

#include <stddef.h>
#include <d3dtypes.h>

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct _D3DRMVECTOR4D
{
    D3DVALUE x;
    D3DVALUE y;
    D3DVALUE z;
    D3DVALUE w;
} D3DRMVECTOR4D, *LPD3DRMVECTOR4D;

typedef D3DVALUE D3DRMMATRIX4D[4][4];

typedef struct _D3DRMQUATERNION {
    D3DVALUE s;
    D3DVECTOR v;
} D3DRMQUATERNION, *LPD3DRMQUATERNION;

typedef struct _D3DRMRAY {
    D3DVECTOR dvDir;
    D3DVECTOR dvPos;
} D3DRMRAY, *LPD3DRMRAY;

typedef struct _D3DRMBOX {
    D3DVECTOR min;
    D3DVECTOR max;
} D3DRMBOX, *LPD3DRMBOX;

typedef void (*D3DRMWRAPCALLBACK)(D3DVECTOR *vec, int *u, int *v, D3DVECTOR *a, D3DVECTOR *b, void *ctx);

typedef enum _D3DRMLIGHTTYPE {
    D3DRMLIGHT_AMBIENT,
    D3DRMLIGHT_POINT,
    D3DRMLIGHT_SPOT,
    D3DRMLIGHT_DIRECTIONAL,
    D3DRMLIGHT_PARALLELPOINT
} D3DRMLIGHTTYPE, *LPD3DRMLIGHTTYPE;

typedef enum _D3DRMSHADEMODE {
    D3DRMSHADE_FLAT     = 0,
    D3DRMSHADE_GOURAUD  = 1,
    D3DRMSHADE_PHONG    = 2,
    D3DRMSHADE_MASK     = 7,
    D3DRMSHADE_MAX                   = 8
} D3DRMSHADEMODE, *LPD3DRMSHADEMODE;

typedef enum _D3DRMLIGHTMODE {
    D3DRMLIGHT_OFF                   = 0 * D3DRMSHADE_MAX,
    D3DRMLIGHT_ON                    = 1 * D3DRMSHADE_MAX,
    D3DRMLIGHT_MASK     = 7 * D3DRMSHADE_MAX,
    D3DRMLIGHT_MAX                   = 8 * D3DRMSHADE_MAX
} D3DRMLIGHTMODE, *LPD3DRMLIGHTMODE;

typedef enum _D3DRMFILLMODE {
    D3DRMFILL_POINTS    = 0 * D3DRMLIGHT_MAX,
    D3DRMFILL_WIREFRAME	= 1 * D3DRMLIGHT_MAX,
    D3DRMFILL_SOLID     = 2 * D3DRMLIGHT_MAX,
    D3DRMFILL_MASK                   = 7 * D3DRMLIGHT_MAX,
    D3DRMFILL_MAX                    = 8 * D3DRMLIGHT_MAX
} D3DRMFILLMODE, *LPD3DRMFILLMODE;

typedef DWORD D3DRMRENDERQUALITY, *LPD3DRMRENDERQUALITY;

#define D3DRMRENDER_WIREFRAME   (D3DRMSHADE_FLAT+D3DRMLIGHT_OFF+D3DRMFILL_WIREFRAME)
#define D3DRMRENDER_UNLITFLAT   (D3DRMSHADE_FLAT+D3DRMLIGHT_OFF+D3DRMFILL_SOLID)
#define D3DRMRENDER_FLAT                     (D3DRMSHADE_FLAT+D3DRMLIGHT_ON+D3DRMFILL_SOLID)
#define D3DRMRENDER_GOURAUD     (D3DRMSHADE_GOURAUD+D3DRMLIGHT_ON+D3DRMFILL_SOLID)
#define D3DRMRENDER_PHONG                    (D3DRMSHADE_PHONG+D3DRMLIGHT_ON+D3DRMFILL_SOLID)

#define D3DRMRENDERMODE_BLENDEDTRANSPARENCY                    1
#define D3DRMRENDERMODE_SORTEDTRANSPARENCY                     2
#define D3DRMRENDERMODE_LIGHTINMODELSPACE                      8
#define D3DRMRENDERMODE_VIEWDEPENDENTSPECULAR    16
#define D3DRMRENDERMODE_DISABLESORTEDALPHAZWRITE 32

typedef enum _D3DRMTEXTUREQUALITY {
    D3DRMTEXTURE_NEAREST,
    D3DRMTEXTURE_LINEAR,
    D3DRMTEXTURE_MIPNEAREST,
    D3DRMTEXTURE_MIPLINEAR,
    D3DRMTEXTURE_LINEARMIPNEAREST,
    D3DRMTEXTURE_LINEARMIPLINEAR
} D3DRMTEXTUREQUALITY, *LPD3DRMTEXTUREQUALITY;

#define D3DRMTEXTURE_FORCERESIDENT                       0x00000001
#define D3DRMTEXTURE_STATIC                                           0x00000002
#define D3DRMTEXTURE_DOWNSAMPLEPOINT                     0x00000004
#define D3DRMTEXTURE_DOWNSAMPLEBILINEAR	    0x00000008
#define D3DRMTEXTURE_DOWNSAMPLEREDUCEDEPTH  0x00000010
#define D3DRMTEXTURE_DOWNSAMPLENONE                      0x00000020
#define D3DRMTEXTURE_CHANGEDPIXELS                       0x00000040
#define D3DRMTEXTURE_CHANGEDPALETTE                      0x00000080
#define D3DRMTEXTURE_INVALIDATEONLY                      0x00000100

#define D3DRMSHADOW_TRUEALPHA                                         0x00000001

typedef enum _D3DRMCOMBINETYPE {
    D3DRMCOMBINE_REPLACE,
    D3DRMCOMBINE_BEFORE,
    D3DRMCOMBINE_AFTER
} D3DRMCOMBINETYPE, *LPD3DRMCOMBINETYPE;

typedef D3DCOLORMODEL D3DRMCOLORMODEL, *LPD3DRMCOLORMODEL;

typedef enum _D3DRMPALETTEFLAGS
{
    D3DRMPALETTE_FREE,
    D3DRMPALETTE_READONLY,
    D3DRMPALETTE_RESERVED
} D3DRMPALETTEFLAGS, *LPD3DRMPALETTEFLAGS;

typedef struct _D3DRMPALETTEENTRY {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char flags;
} D3DRMPALETTEENTRY, *LPD3DRMPALETTEENTRY;

typedef struct _D3DRMIMAGE {
    int width;
    int height;
    int aspectx;
    int aspecty;
    int depth;
    int rgb;
    int bytes_per_line;
    void* buffer1;
    void* buffer2;
    ULONG red_mask;
    ULONG green_mask;
    ULONG blue_mask;
    ULONG alpha_mask;
    int palette_size;
    D3DRMPALETTEENTRY* palette;
} D3DRMIMAGE, *LPD3DRMIMAGE;

typedef enum _D3DRMWRAPTYPE {
    D3DRMWRAP_FLAT,
    D3DRMWRAP_CYLINDER,
    D3DRMWRAP_SPHERE,
    D3DRMWRAP_CHROME,
    D3DRMWRAP_SHEET,
    D3DRMWRAP_BOX
} D3DRMWRAPTYPE, *LPD3DRMWRAPTYPE;

#define D3DRMWIREFRAME_CULL                                       1
#define D3DRMWIREFRAME_HIDDENLINE                    2

typedef enum _D3DRMPROJECTIONTYPE
{
    D3DRMPROJECT_PERSPECTIVE,
    D3DRMPROJECT_ORTHOGRAPHIC,
    D3DRMPROJECT_RIGHTHANDPERSPECTIVE,
    D3DRMPROJECT_RIGHTHANDORTHOGRAPHIC
} D3DRMPROJECTIONTYPE, *LPD3DRMPROJECTIONTYPE;

#define D3DRMOPTIONS_LEFTHANDED  0x00000001
#define D3DRMOPTIONS_RIGHTHANDED 0x00000002

typedef enum _D3DRMXOFFORMAT {
    D3DRMXOF_BINARY,
    D3DRMXOF_COMPRESSED,
    D3DRMXOF_TEXT
} D3DRMXOFFORMAT, *LPD3DRMXOFFORMAT;

typedef DWORD D3DRMSAVEOPTIONS;
#define D3DRMXOFSAVE_NORMALS                                       1
#define D3DRMXOFSAVE_TEXTURECOORDINATES  2
#define D3DRMXOFSAVE_MATERIALS                        4
#define D3DRMXOFSAVE_TEXTURENAMES                     8
#define D3DRMXOFSAVE_ALL                                          15
#define D3DRMXOFSAVE_TEMPLATES                       16
#define D3DRMXOFSAVE_TEXTURETOPOLOGY    32

typedef enum _D3DRMCOLORSOURCE {
    D3DRMCOLOR_FROMFACE,
    D3DRMCOLOR_FROMVERTEX
} D3DRMCOLORSOURCE, *LPD3DRMCOLORSOURCE;

typedef enum _D3DRMFRAMECONSTRAINT {
    D3DRMCONSTRAIN_Z,
    D3DRMCONSTRAIN_Y,
    D3DRMCONSTRAIN_X
} D3DRMFRAMECONSTRAINT, *LPD3DRMFRAMECONSTRAINT;

typedef enum _D3DRMMATERIALMODE {
    D3DRMMATERIAL_FROMMESH,
    D3DRMMATERIAL_FROMPARENT,
    D3DRMMATERIAL_FROMFRAME
} D3DRMMATERIALMODE, *LPD3DRMMATERIALMODE;

typedef enum _D3DRMFOGMODE {
    D3DRMFOG_LINEAR,
    D3DRMFOG_EXPONENTIAL,
    D3DRMFOG_EXPONENTIALSQUARED
} D3DRMFOGMODE, *LPD3DRMFOGMODE;

typedef enum _D3DRMZBUFFERMODE {
    D3DRMZBUFFER_FROMPARENT,
    D3DRMZBUFFER_ENABLE,
    D3DRMZBUFFER_DISABLE
} D3DRMZBUFFERMODE, *LPD3DRMZBUFFERMODE;

typedef enum _D3DRMSORTMODE {
    D3DRMSORT_FROMPARENT,
    D3DRMSORT_NONE,
    D3DRMSORT_FRONTTOBACK,
    D3DRMSORT_BACKTOFRONT
} D3DRMSORTMODE, *LPD3DRMSORTMODE;

typedef struct _D3DRMMATERIALOVERRIDE {
    DWORD                      dwSize;
    DWORD                      dwFlags;
    D3DCOLORVALUE dcDiffuse;
    D3DCOLORVALUE dcAmbient;
    D3DCOLORVALUE dcEmissive;
    D3DCOLORVALUE dcSpecular;
    D3DVALUE                   dvPower;
    IUnknown *lpD3DRMTex;
} D3DRMMATERIALOVERRIDE, *LPD3DRMMATERIALOVERRIDE;

#define D3DRMMATERIALOVERRIDE_DIFFUSE_ALPHAONLY     0x00000001
#define D3DRMMATERIALOVERRIDE_DIFFUSE_RGBONLY                    0x00000002
#define D3DRMMATERIALOVERRIDE_DIFFUSE                                         0x00000003
#define D3DRMMATERIALOVERRIDE_AMBIENT                                         0x00000004
#define D3DRMMATERIALOVERRIDE_EMISSIVE                                        0x00000008
#define D3DRMMATERIALOVERRIDE_SPECULAR                                        0x00000010
#define D3DRMMATERIALOVERRIDE_POWER                                           0x00000020
#define D3DRMMATERIALOVERRIDE_TEXTURE                                         0x00000040
#define D3DRMMATERIALOVERRIDE_DIFFUSE_ALPHAMULTIPLY 0x00000080
#define D3DRMMATERIALOVERRIDE_ALL                                                          0x000000FF

#define D3DRMFPTF_ALPHA                                                                                 0x00000001
#define D3DRMFPTF_NOALPHA                                                                               0x00000002
#define D3DRMFPTF_PALETTIZED                                                                            0x00000004
#define D3DRMFPTF_NOTPALETTIZED                                                            0x00000008

#define D3DRMSTATECHANGE_UPDATEONLY                                          0x000000001
#define D3DRMSTATECHANGE_VOLATILE                                                         0x000000002
#define D3DRMSTATECHANGE_NONVOLATILE                                         0x000000004
#define D3DRMSTATECHANGE_RENDER                                                           0x000000020
#define D3DRMSTATECHANGE_LIGHT                                                            0x000000040

#define D3DRMDEVICE_NOZBUFFER                        0x00000001

#define D3DRMCALLBACK_PREORDER		0
#define D3DRMCALLBACK_POSTORDER		1

#define D3DRMRAYPICK_ONLYBOUNDINGBOXES                       0x01
#define D3DRMRAYPICK_IGNOREFURTHERPRIMITIVES    0x02
#define D3DRMRAYPICK_INTERPOLATEUV                                        0x04
#define D3DRMRAYPICK_INTERPOLATECOLOR                        0x08
#define D3DRMRAYPICK_INTERPOLATENORMAL                       0x10

#define D3DRMADDFACES_VERTICESONLY                                        1

#define D3DRMGENERATENORMALS_PRECOMPACT                      1
#define D3DRMGENERATENORMALS_USECREASEANGLE     2

#define D3DRMMESHBUILDER_DIRECTPARENT                        1
#define D3DRMMESHBUILDER_ROOTMESH                                         2

#define D3DRMMESHBUILDER_RENDERENABLE   0x00000001
#define D3DRMMESHBUILDER_PICKENABLE     0x00000002

#define D3DRMADDMESHBUILDER_DONTCOPYAPPDATA     1
#define D3DRMADDMESHBUILDER_FLATTENSUBMESHES    2
#define D3DRMADDMESHBUILDER_NOSUBMESHES                      4

#define D3DRMMESHBUILDERAGE_GEOMETRY    0x00000001
#define D3DRMMESHBUILDERAGE_MATERIALS   0x00000002
#define D3DRMMESHBUILDERAGE_TEXTURES    0x00000004

#define D3DRMFVF_TYPE                                                          0x00000001
#define D3DRMFVF_NORMAL                                           0x00000002
#define D3DRMFVF_COLOR                                                         0x00000004
#define D3DRMFVF_TEXTURECOORDS                       0x00000008

#define D3DRMVERTEX_STRIP                                         0x00000001
#define D3DRMVERTEX_FAN                                           0x00000002
#define D3DRMVERTEX_LIST                                          0x00000004

#define D3DRMCLEAR_TARGET                                         0x00000001
#define D3DRMCLEAR_ZBUFFER                                        0x00000002
#define D3DRMCLEAR_DIRTYRECTS                        0x00000004
#define D3DRMCLEAR_ALL                                                         (D3DRMCLEAR_TARGET | D3DRMCLEAR_ZBUFFER | D3DRMCLEAR_DIRTYRECTS)

#define D3DRMFOGMETHOD_VERTEX                        0x00000001
#define D3DRMFOGMETHOD_TABLE                                      0x00000002
#define D3DRMFOGMETHOD_ANY                                        0x00000004

#define D3DRMFRAME_RENDERENABLE                      0x00000001
#define D3DRMFRAME_PICKENABLE                        0x00000002

typedef DWORD D3DRMANIMATIONOPTIONS;
#define D3DRMANIMATION_OPEN                                       0x00000001
#define D3DRMANIMATION_CLOSED                        0x00000002
#define D3DRMANIMATION_LINEARPOSITION   0x00000004
#define D3DRMANIMATION_SPLINEPOSITION   0x00000008
#define D3DRMANIMATION_SCALEANDROTATION 0x00000010
#define D3DRMANIMATION_POSITION                      0x00000020

typedef DWORD D3DRMINTERPOLATIONOPTIONS;
#define D3DRMINTERPOLATION_OPEN                      0x0001
#define D3DRMINTERPOLATION_CLOSED                    0x0002
#define D3DRMINTERPOLATION_NEAREST                   0x0100
#define D3DRMINTERPOLATION_LINEAR                    0x0004
#define D3DRMINTERPOLATION_SPLINE                    0x0008
#define D3DRMINTERPOLATION_VERTEXCOLOR  0x0040
#define D3DRMINTERPOLATION_SLERPNORMALS 0x0080

typedef DWORD D3DRMLOADOPTIONS;

#define D3DRMLOAD_FROMFILE                                       __MSABI_LONG(0x000)
#define D3DRMLOAD_FROMRESOURCE                      __MSABI_LONG(0x001)
#define D3DRMLOAD_FROMMEMORY                        __MSABI_LONG(0x002)
#define D3DRMLOAD_FROMSTREAM                        __MSABI_LONG(0x004)
#define D3DRMLOAD_FROMURL                                        __MSABI_LONG(0x008)

#define D3DRMLOAD_BYNAME                                         __MSABI_LONG(0x010)
#define D3DRMLOAD_BYPOSITION                        __MSABI_LONG(0x020)
#define D3DRMLOAD_BYGUID                                         __MSABI_LONG(0x040)
#define D3DRMLOAD_FIRST                                          __MSABI_LONG(0x080)

#define D3DRMLOAD_INSTANCEBYREFERENCE  __MSABI_LONG(0x100)
#define D3DRMLOAD_INSTANCEBYCOPYING    __MSABI_LONG(0x200)

#define D3DRMLOAD_ASYNCHRONOUS                      __MSABI_LONG(0x400)

typedef struct _D3DRMLOADRESOURCE
{
    HMODULE hModule;
    const char *lpName;
    const char *lpType;
} D3DRMLOADRESOURCE, *LPD3DRMLOADRESOURCE;

typedef struct _D3DRMLOADMEMORY
{
    void *lpMemory;
    DWORD dSize;
} D3DRMLOADMEMORY, *LPD3DRMLOADMEMORY;

#define D3DRMPMESHSTATUS_VALID                                      0x01
#define D3DRMPMESHSTATUS_INTERRUPTED                   0x02
#define D3DRMPMESHSTATUS_BASEMESHCOMPLETE 0x04
#define D3DRMPMESHSTATUS_COMPLETE                      0x08
#define D3DRMPMESHSTATUS_RENDERABLE                    0x10

#define D3DRMPMESHEVENT_BASEMESH                       0x01
#define D3DRMPMESHEVENT_COMPLETE                       0x02

typedef struct _D3DRMPMESHLOADSTATUS {
    DWORD dwSize;
    DWORD dwPMeshSize;
    DWORD dwBaseMeshSize;
    DWORD dwBytesLoaded;
    DWORD dwVerticesLoaded;
    DWORD dwFacesLoaded;
    HRESULT dwLoadResult;
    DWORD dwFlags;
} D3DRMPMESHLOADSTATUS, *LPD3DRMPMESHLOADSTATUS;

typedef enum _D3DRMUSERVISUALREASON {
    D3DRMUSERVISUAL_CANSEE,
    D3DRMUSERVISUAL_RENDER
} D3DRMUSERVISUALREASON, *LPD3DRMUSERVISUALREASON;

typedef struct _D3DRMANIMATIONKEY
{
    DWORD dwSize;
    DWORD dwKeyType;
    D3DVALUE dvTime;
    DWORD dwID;
#if !defined(__cplusplus) || !defined(D3D_OVERLOADS)
    union
    {
	D3DRMQUATERNION dqRotateKey;
	D3DVECTOR dvScaleKey;
	D3DVECTOR dvPositionKey;
    } DUMMYUNIONNAME;
#else
    D3DVALUE dvK[4];
#endif
} D3DRMANIMATIONKEY;
typedef D3DRMANIMATIONKEY *LPD3DRMANIMATIONKEY;

#define D3DRMANIMATION_ROTATEKEY   0x01
#define D3DRMANIMATION_SCALEKEY    0x02
#define D3DRMANIMATION_POSITIONKEY 0x03

typedef DWORD D3DRMMAPPING, D3DRMMAPPINGFLAG, *LPD3DRMMAPPING;
static const D3DRMMAPPINGFLAG D3DRMMAP_WRAPU                     = 1;
static const D3DRMMAPPINGFLAG D3DRMMAP_WRAPV                     = 2;
static const D3DRMMAPPINGFLAG D3DRMMAP_PERSPCORRECT = 4;

typedef struct _D3DRMVERTEX {
    D3DVECTOR position;
    D3DVECTOR normal;
    D3DVALUE  tu;
    D3DVALUE  tv;
    D3DCOLOR  color;
} D3DRMVERTEX, *LPD3DRMVERTEX;

typedef LONG D3DRMGROUPINDEX;
static const D3DRMGROUPINDEX D3DRMGROUP_ALLGROUPS = -1;

void WINAPI D3DRMMatrixFromQuaternion(D3DRMMATRIX4D m, D3DRMQUATERNION *q);

D3DRMQUATERNION * WINAPI D3DRMQuaternionFromRotation(D3DRMQUATERNION *x, D3DVECTOR *axis, D3DVALUE theta);
D3DRMQUATERNION * WINAPI D3DRMQuaternionMultiply(D3DRMQUATERNION *ret, D3DRMQUATERNION *x, D3DRMQUATERNION *y);
D3DRMQUATERNION * WINAPI D3DRMQuaternionSlerp(D3DRMQUATERNION *ret,
                     D3DRMQUATERNION *x, D3DRMQUATERNION *y, D3DVALUE alpha);

D3DVECTOR * WINAPI D3DRMVectorAdd(D3DVECTOR *ret, D3DVECTOR *x, D3DVECTOR *y);
D3DVECTOR * WINAPI D3DRMVectorCrossProduct(D3DVECTOR *ret, D3DVECTOR *x, D3DVECTOR *y);
D3DVALUE WINAPI D3DRMVectorDotProduct(D3DVECTOR *x, D3DVECTOR *y);
D3DVECTOR * WINAPI D3DRMVectorNormalize(D3DVECTOR *x);

#define D3DRMVectorNormalise D3DRMVectorNormalize

D3DVALUE WINAPI D3DRMVectorModulus(D3DVECTOR *x);
D3DVECTOR * WINAPI D3DRMVectorRandom(D3DVECTOR *ret);
D3DVECTOR * WINAPI D3DRMVectorRotate(D3DVECTOR *ret, D3DVECTOR *x, D3DVECTOR *axis, D3DVALUE theta);
D3DVECTOR * WINAPI D3DRMVectorReflect(D3DVECTOR *ret, D3DVECTOR *ray, D3DVECTOR *normal);
D3DVECTOR * WINAPI D3DRMVectorScale(D3DVECTOR *ret, D3DVECTOR *x, D3DVALUE scale);
D3DVECTOR * WINAPI D3DRMVectorSubtract(D3DVECTOR *ret, D3DVECTOR *x, D3DVECTOR *y);

D3DCOLOR WINAPI D3DRMCreateColorRGB(D3DVALUE, D3DVALUE, D3DVALUE);
D3DCOLOR WINAPI D3DRMCreateColorRGBA(D3DVALUE, D3DVALUE, D3DVALUE, D3DVALUE);
D3DVALUE WINAPI D3DRMColorGetAlpha(D3DCOLOR);
D3DVALUE WINAPI D3DRMColorGetBlue(D3DCOLOR);
D3DVALUE WINAPI D3DRMColorGetGreen(D3DCOLOR);
D3DVALUE WINAPI D3DRMColorGetRed(D3DCOLOR);

#if defined(__cplusplus)
}
#endif

#endif
