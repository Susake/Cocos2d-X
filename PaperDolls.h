/***************************************************************************
 *
 *  Copyright (c) 2015 by Susake All rights reserved
 *
 *  File:     PaperDolls.h
 *  Content:  2D纸娃娃换装
 *
 ***************************************************************************/
#ifndef _PARPERDOLLS_H
#define _PARPERDOLLS_H

#include "Common.h"

/**
 * 主角状态值
 */
#define STAND 	1						//站立
#define WALK 	2						//行走
#define JUMP 	3						//跳跃
#define ATTACK1 4						//攻击1
#define ATTACK2 5						//攻击2
#define ATTACK3	6						//攻击3
#define JUMPATTACK 7					//跳攻

#define PARPERDOLLS_RIGHT 1				//左
#define PARPERDOLLS_LEFT -1				//右

/**
 * 主角部位值
 */
#define BODY	1						//身体
#define WEAPON	2						//武器

class PaperDolls {
public :
	/*****************************************************************
	** function:	PaperDolls
	** content:
	** 				构造函数初始化主角的位置，自动从服务器获取主角的纸娃娃
	**
	** position_x--		表示主角的初始位置x
	** position_y--		表示主角的初始位置y
	*****************************************************************/
	PaperDolls(int position_x, int position_y);
	~PaperDolls();
public :
	/*****************************************************************
	** function:	playPaperDolls
	** content:
	** 				根据主角状态值播放想要状态的动画
	**
	** state--		表示主角的状态值
	*****************************************************************/
	void playPaperDolls(int state);
	/*****************************************************************
	** function:	movePaperDolls
	** content:
	** 				移动
	**
	** change_x--		表示主角移动x距离
	** change_y--		表示主角移动y距离
	*****************************************************************/
	void movePaperDolls(int change_x, int change_y);
	/*****************************************************************
	** function:	changePaperDolls
	** content:
	** 				移动
	**
	** part--		表示替换的部位
	** id--			表示现有替换成id装备
	*****************************************************************/
	void changePaperDolls(int part, int id);
	/*****************************************************************
	** function:	directionPaperDolls
	** content:
	** 				方向
	**
	** direction--	表示转换的方向
	*****************************************************************/
	void directionPaperDolls(int direction);
public :
	int m_state;//主角状态
	int stand_num;//帧数
	int m_num;
	int m_direction;//主角移动方向
    Sprite *ani;
	Animation *stand, *walk, *atk1, *atk2, *atk3, *jump, *jumpatk;
	Animation *stand_cache;
	int x, y;
};

#endif
