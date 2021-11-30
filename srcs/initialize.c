#include "../so_long.h"

void	initialize(t_test *test)
{
	test->mlx = NULL;
	test->win = NULL;
	test->param.map = NULL;
	test->param.height = 0;
	test->param.height_with_wall = 0;
 	test->param.width = 0;
	test->param.width_with_x = 0;
	test->param.rendered = 0;
	test->player.pos_i = 0;
	test->player.lastpos_i = 0;
	test->player.pos_j = 0;
	test->player.lastpos_j = 0;
	test->player.pos_x = 0;
	test->player.pos_y = 0;
	test->player.steps = 0;
	test->player.lock_pos = 0;
	test->collec.amount = 0;
	test->collec.count = 0;
	test->collec.exit = 0;
	test->collec.random = 0;
	test->data.img = NULL;
	test->data.addr = NULL;
	test->all.wall.img = NULL;
	test->all.wall.addr = NULL;
	test->all.floor.img = NULL;
	test->all.floor.addr = NULL; 
	test->all.floor_half_left.img = NULL;
	test->all.floor_half_left.addr = NULL;   
	test->all.floor_half_right.img = NULL;
	test->all.floor_half_right.addr = NULL;  
	test->all.box.img = NULL;
	test->all.box.addr = NULL;   
	test->all.pot.img = NULL;
	test->all.pot.addr = NULL;   
	test->all.cardboard.img = NULL;
	test->all.cardboard.addr = NULL; 
	test->all.dresser_downleft.img = NULL;
	test->all.dresser_downleft.addr = NULL;  
	test->all.dresser_downright.img = NULL;
	test->all.dresser_downright.addr = NULL; 
	test->all.dresser_topleft.img = NULL;
	test->all.dresser_topleft.addr = NULL;   
	test->all.dresser_topright.img = NULL;
	test->all.dresser_topright.addr = NULL;
	test->all.spike.img = NULL;
	test->all.spike.addr = NULL;
	// test->all.hole_left.img = NULL;
	// test->all.hole_left.addr = NULL;
	// test->all.hole_right.img = NULL;
	// test->all.hole_right.addr = NULL;
	test->collec.newspaper.img = NULL;
	test->collec.newspaper.addr = NULL;
	test->collec.wanted.img = NULL;
	test->collec.wanted.addr = NULL;
	test->all.exit_half_left.img = NULL;
	test->all.exit_half_left.addr = NULL;
	test->all.exit_half_right.img = NULL;
	test->all.exit_half_right.addr = NULL;
	// test->all.trapdoor_left.img = NULL;
	// test->all.trapdoor_left.addr = NULL;
	// test->all.trapdoor_right.img = NULL;
	// test->all.trapdoor_right.addr = NULL; 
	test->player.frontside.img = NULL;
	test->player.frontside.addr = NULL;
	test->player.backside.img = NULL;
	test->player.backside.addr = NULL;
	test->player.rightside.img = NULL;
	test->player.rightside.addr = NULL;
	test->player.leftside.img = NULL;
	test->player.leftside.addr = NULL;
	test->button.time = 0;
	test->dialog_box.keep = 0;
	test->dialog_box.right.img = NULL;
	test->dialog_box.right.addr = NULL;
	test->dialog_box.mid.img = NULL;
	test->dialog_box.mid.addr = NULL;
	test->dialog_box.left.img = NULL;
	test->dialog_box.left.addr = NULL;
	test->life.lives = 3;
	test->life.full_heart.img = NULL;
	test->life.full_heart.addr = NULL;
	test->life.empty_heart.img = NULL;
	test->life.empty_heart.addr = NULL;
}
