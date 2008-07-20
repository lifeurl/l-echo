// stair.cpp

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



#include <echo_debug.h>
#include <echo_error.h>
#include <echo_math.h>
#include <echo_gfx.h>

#include <grid.h>
#include <stair.h>

stair::stair() : grid()
{
	init(NULL, NULL, NULL, 0);
}

stair::stair(grid_info_t* my_info, grid* my_prev, grid* my_next, float my_angle) : grid(0)
{
	init(my_info, my_prev, my_next, my_angle);
}

void stair::init(grid_info_t* my_info, grid* my_prev, grid* my_next, float my_angle)
{
	angle = my_angle;
	//ECHO_PRINT("stair angle 1: %f\n", angle);
	grid::init(my_info, my_prev, my_next);
}

void stair::init_to_null()
{
	grid::init_to_null();
	angle = 0;
}

#ifdef ARM9
	#define SET_ID(id)	gfx_set_polyID(id)
#else
	#define SET_ID(id)
#endif

void stair::draw(vector3f angle)
{
	draw_goal(angle);
	
	gfx_push_matrix();
	gfx_translatef(ginfo->pos.x, ginfo->pos.y, ginfo->pos.z);
	gfx_rotatef(this->angle, 0, 1, 0);
	
	SET_ID(16);
	draw_rect(0.5f, -0.333f, -0.333f, 0.5f, -0.5f, -0.333f
		, -0.5f, -0.5f, -0.333f, -0.5f, -0.333f, -0.333f);
	SET_ID(17);
	draw_rect(0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.333f
		, -0.5f, -0.5f, -0.333f, -0.5f, -0.5f, -0.5f);
	SET_ID(18);
	draw_rect(0.5f, -0.166f, -0.166f, 0.5f, -0.333f, -0.166f
		, -0.5f, -0.333f, -0.166f, -0.5f, -0.166f, -0.166f);
	SET_ID(16);
	draw_rect(0.5f, -0.333f, -0.333f, 0.5f, -0.333f, -0.166f
		, -0.5f, -0.333f, -0.166f, -0.5f, -0.333f, -0.333f);
	SET_ID(17);
	draw_rect(0.5f, 0, 0, 0.5f, -0.166f, 0
		, -0.5f, -0.166f, 0, -0.5f, 0, 0);
	SET_ID(18);
	draw_rect(0.5f, -0.166f, -0.166f, 0.5f, -0.166f, 0
		, -0.5f, -0.166f, 0, -0.5f, -0.166f, -0.166f);
	SET_ID(16);
	draw_rect(0.5f, 0.166f, 0.166f, 0.5f, 0, 0.166f
		, -0.5f, 0, 0.166f, -0.5f, 0.166f, 0.166f);
	SET_ID(17);
	draw_rect(0.5f, 0, 0, 0.5f, 0, 0.166f
		, -0.5f, 0, 0.166f, -0.5f, 0, 0);
	SET_ID(18);
	draw_rect(0.5f, 0.333f, 0.333f, 0.5f, 0.166f, 0.333f
		, -0.5f, 0.166f, 0.333f, -0.5f, 0.333f, 0.333f);
	SET_ID(16);
	draw_rect(0.5f, 0.166f, 0.166f, 0.5f, 0.166f, 0.333f
		, -0.5f, 0.166f, 0.333f, -0.5f, 0.166f, 0.166f);
	SET_ID(17);
	draw_rect(0.5f, 0.5f, 0.5f, 0.5f, 0.333f, 0.5f
		, -0.5f, 0.333f, 0.5f, -0.5f, 0.5f, 0.5f);
	SET_ID(18);
	draw_rect(0.5f, 0.333f, 0.333f, 0.5f, 0.333f, 0.5f
		, -0.5f, 0.333f, 0.5f, -0.5f, 0.333f, 0.333f);
	
	/*
	float each = -2 * 0.166f;
#ifdef ARM9
	unsigned int id = get_polyID(angle);
	if(id == 0)
		id = 1;
#endif
	while(each <= 0.5f)
	{
#ifdef ARM9
		gfx_set_polyID(id);
#endif
		draw_rect(0.5f, each, each, 0.5f, each - 0.166f, each
			, -0.5f, each - 0.166f, each, -0.5f, each, each);
#ifdef ARM9
		gfx_set_polyID(id - 1);
#endif
		draw_rect(0.5f, each - 0.166f, each - 0.166f, 0.5f, each - 0.166f, each
			, -0.5f, each - 0.166f, each, -0.5f, each - 0.166f, each - 0.166f);
		
		each += 0.166f;
	}
	// */
	gfx_pop_matrix();
}

