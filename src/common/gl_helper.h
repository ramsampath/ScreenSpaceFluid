

#ifndef GL_HELPER
	#define GL_HELPER

	#include "common_defs.h"

	#include <gl/glee.h>
	#include <gl/glext.h>	

	#ifdef _MSC_VER						// Windows
		#ifdef USE_SHADOWS
			#include <gl/glee.h>
			#include <gl/glext.h>	
		#endif			
		#include <gl/glut.h>
	#else								// Linux
		#ifdef USE_SHADOWS
			#include "GLee.h"
		#endif
		#include <GL/glext.h>	
		#include <GL/glut.h>	
	#endif
	
	#include "image.h"
	#include "mtime.h"

	extern void checkOpenGL ();
	extern void drawText ( int x, int y, char* msg);
	extern void drawGrid ();
	extern void measureFPS ();

	extern mint::Time	tm_last;
	extern int			tm_cnt;
	extern float		tm_fps;
	

	extern void disableShadows ();
	extern void checkFrameBuffers ();

	extern GLuint glSphere;
	extern float  glRadius;
	extern void setSphereRadius ( float f );
	extern void drawSphere ();

	#ifdef USE_SHADOWS
		extern void setShadowLight ( float fx, float fy, float fz, float tx, float ty, float tz, float fov );
		extern void setShadowLightColor ( float dr, float dg, float db, float sr, float sg, float sb );
		
		extern void createFrameBuffer ();
		extern void createShadowTextures ();
		extern void computeLightMatrix ( int n, int tx, int ty );
		extern void renderDepthMap_Clear ( float wx, float wy );
		extern void renderDepthMap_FrameBuffer ( int n, float wx, float wy );
		extern void renderShadowStage ( int n, float* vmat );
		extern void renderShadows ( float* vmat );
		extern void drawScene ( float* view_mat, bool bShaders );		// provided by user

		extern float light_proj[16];
		extern float light_x, light_y, light_z;
		extern float light_tox, light_toy, light_toz;
		extern float light_mfov;

		extern GLuint		shadow1_id;
		extern GLuint		shadow2_id;
	#endif


#endif