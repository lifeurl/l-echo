// echo_gfx.h

/*
    This file is part of L-Echo.

    L-Echo is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    L-Echo is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with L-Echo.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <grid.h>
#include <echo_char_joints.h>
#include <echo_math.h>

void draw_line(float x1, float y1, float z1, float x2, float y2, float z2);
void draw_line(vector3f p1, vector3f p2);
void draw_rect(vector3f p1, vector3f p2, vector3f p3, vector3f p4);
void draw_rect(float x1, float y1, float z1
		, float x2, float y2, float z2
		, float x3, float y3, float z3
		, float x4, float y4, float z4);
#ifdef ARM9
#include <nds.h>
void draw_rectv16(v16 x1, v16 y1, v16 z1
		, v16 x2, v16 y2, v16 z2
		, v16 x3, v16 y3, v16 z3
		, v16 x4, v16 y4, v16 z4);
#endif
void draw_head();
void draw_body();
void draw_lower_body();
void draw_limb();
void draw_hole(vector3f pos);
void draw_launcher(vector3f pos);
void draw_goal_gfx(vector3f* pos);
void draw_character(echo_char_joints* joints);
void draw_stairs();
void draw_left_hand();
void draw_right_hand();
void draw_foot();
void draw_sphere_point1();
void draw_sphere_pointzero75();

void gfx_identity();
void gfx_push_matrix();
void gfx_pop_matrix();
void gfx_rotatef(float angle, float x, float y, float z);
void gfx_translatef(float x, float y, float z);
void gfx_color3f(float r, float g, float b);

#ifndef ARM9
void gfx_outline_start();
void gfx_outline_mid();
void gfx_outline_end();
#else
void gfx_set_polyID(unsigned int polyID);
#endif
