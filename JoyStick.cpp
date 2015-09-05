#include "JoyStick.h"

Scene* JoyStick::createScene() {
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = JoyStick::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool JoyStick::init() {
	//设备分辨率
	visibleSize = Director::getInstance()->getVisibleSize();
	//摇杆
	joystickbg = Sprite::create("JoyStick/joystickBG.png");
	joystickbg->setPosition(Vec2(joystickbg->getContentSize().width / 2, joystickbg->getContentSize().height / 2));
	joystickbg->setVisible(false);
	this->addChild(joystickbg, 4);
	joystick_r = joystickbg->getContentSize().width / 2;joystick_x = center_x = joystickbg->getContentSize().width / 2;joystick_y = center_y = joystickbg->getContentSize().height / 2;
	joystickbtn = Sprite::create("JoyStick/joystick.png");
	joystickbtn->setPosition(Vec2(joystick_x, joystick_y));
	this->addChild(joystickbtn, 4);

	return true;
}
/***************************************************************************
 *
 *  Copyright (c) Susake  All rights reserved
 *
 *  Content:  八方向摇杆操作部分
 *
 ***************************************************************************/
void JoyStick::upKey() {
}
void JoyStick::rightUpKey() {
}
void JoyStick::rightKey() {
}
void JoyStick::rightDownKey() {
}
void JoyStick::downKey() {
}
void JoyStick::leftDownKey() {
}
void JoyStick::leftKey() {
}
void JoyStick::leftUpKey() {
}
void JoyStick::withoutKey() {
}
/***************************************************************************
 *
 *  Copyright (c) Susake  All rights reserved
 *
 *  Content:  触摸操作部分
 *
 ***************************************************************************/
//设备多点触碰
void JoyStick::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event){
	for( auto &item: touches)
	{
		auto touch = item;
		auto location = touch->getLocation();
		//触摸在摇杆范围内
		Rect rect = joystickbg->boundingBox();
		if(rect.containsPoint(location)) {
			joyStickBegin();
		}
	}
}
void JoyStick::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event) {
	for( auto &item: touches)
	{
		auto touch = item;
		auto location = touch->getLocation();
		//摇杆操作
		if(is_move) {
			joyStickMove(location);
		}
	}
}
void JoyStick::onTouchesEnded(const std::vector<Touch*>& touches, Event  *event) {
	//摇杆处理
	joyStickEnd();
}
void JoyStick::onTouchesCancelled(const std::vector<Touch*>& touches, Event  *event) {onTouchesEnded(touches, event);}
/***************************************************************************
 *
 *  Copyright (c) Susake  All rights reserved
 *
 *  Content:  其他功能
 *
 ***************************************************************************/
//逐帧更新
void JoyStick::update(float dt){
	if(joystick_directoin == JOYSTICK) {
		withoutKey();
	}
	//上
	else if(joystick_directoin == JOYSTICK_UP) {
		upKey();
	}
	//右上
	else if(joystick_directoin == JOYSTICK_RIGHT_UP) {
		rightUpKey();
	}
	//右
	else if(joystick_directoin == JOYSTICK_RIGHT) {
		rightKey();
	}
	//右下
	else if(joystick_directoin == JOYSTICK_RIGHT_DOWN) {
		rightDownKey();
	}
	//下
	else if(joystick_directoin == JOYSTICK_DOWN) {
		downKey();
	}
	//左下
	else if(joystick_directoin == JOYSTICK_LEFT_DOWN) {
		leftDownKey();
	}
	//左
	else if(joystick_directoin == JOYSTICK_LEFT) {
		leftKey();
	}
	//左上
	else if(joystick_directoin == JOYSTICK_LEFT_UP) {
		leftUpKey();
	}
}
void JoyStick::joyStickBegin() {
	is_move = true;
}
void JoyStick::joyStickMove(Point location) {
	float x = location.x - center_x, y = location.y - center_y;
	float angle = atan2(y, x) * 180 / PI;
	if(angle >= 67.5f && angle < 112.5f) {
		joystick_directoin = JOYSTICK_UP;
		CCLog("JOYSTICK_UP");
	}
	else if(angle >= 22.5f && angle < 67.5f) {
		joystick_directoin = JOYSTICK_RIGHT_UP;
		CCLog("JOYSTICK_RIGHT_UP");
	}
	else if(angle >= -22.5f && angle < 22.5f) {
		joystick_directoin = JOYSTICK_RIGHT;
		CCLog("JOYSTICK_RIGHT");
	}
	else if(angle >= -67.5f && angle < -22.5f) {
		joystick_directoin = JOYSTICK_RIGHT_DOWN;
		CCLog("JOYSTICK_RIGHT_DOWN");
	}
	else if(angle >= -112.5f && angle < -67.5f) {
		joystick_directoin = JOYSTICK_DOWN;
		CCLog("JOYSTICK_DOWN");
	}
	else if(angle >= -157.5f && angle < -112.5f) {
		joystick_directoin = JOYSTICK_LEFT_DOWN;
		CCLog("JOYSTICK_LEFT_DOWN");
	}
	else if(angle > -180.0f && angle < -157.5f || angle > 157.0f && angle < 180.0f) {
		joystick_directoin = JOYSTICK_LEFT;
		CCLog("JOYSTICK_LEFT");
	}
	else if(angle >= -112.5f && angle < 157.0f) {
		joystick_directoin = JOYSTICK_LEFT_UP;
		CCLog("JOYSTICK_LEFT_UP");
	}
	float distance = sqrt(pow((center_x - location.x),2) + pow((center_y - location.y),2));
	float deltX = (location.x - center_x) * (joystick_r / distance);
	float deltY = (location.y - center_y) * (joystick_r / distance);
	if(distance >= joystick_r) {
		joystickbtn->setPosition(Vec2(center_x + deltX, center_y + deltY));
	}
	else {
		joystickbtn->setPosition(Vec2(location.x, location.y));
	}
}
void JoyStick::joyStickEnd() {
	is_move = false;
	joystick_x = center_x; joystick_y = center_y;
	joystickbtn->setPosition(Vec2(joystick_x, joystick_y));
	joystickbg->setVisible(false);
	joystick_directoin = JOYSTICK;
}
