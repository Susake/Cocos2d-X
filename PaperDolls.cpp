#include "PaperDolls.h"

PaperDolls::PaperDolls(int position_x, int position_y) {
	ani = Sprite::create("Susake.png");
	ani->setAnchorPoint(Vec2(0.5f, 0.0f));
	x = position_x; y = position_y;
	ani->setPosition(ccp(x, y));
	stand = Animation::create();
	walk = Animation::create();
	atk1 = Animation::create();
	atk2 = Animation::create();
	atk3 = Animation::create();
	jump = Animation::create();
	jumpatk = Animation::create();

	//站立(默认)
	m_state = STAND;
	//移动方向(默认)
	m_direction = PARPERDOLLS_RIGHT;

    int m_num = 2;
	int state_num[20] = {4, 8, 10, 11, 9, 8, 6};
	int state[][11] = {{176, 177, 178, 179, 0, 0, 0, 0, 0, 0, 0},
			{180, 181, 182, 183, 184, 185, 186, 187, 0, 0, 0},
			{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
			{10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
			{33, 34, 35, 36, 37, 38, 39, 40, 41, 0},
			{125, 126, 127, 128, 129, 130, 131, 132, 0, 0},
			{133, 134, 135, 136, 137, 138, 0, 0, 0, 0}};

    for(int v = 0; v < m_num; v++) {
        for(int i = 0; i < state_num[v]; ++i) {
            char str[100];
            //...
            Image* skin = new Image();
            sprintf(str, "Character/skin/%d.png", state[v][i]);
            skin->initWithImageFile(str);
            memset(str, 0, sizeof(str));
            //...
            Image* lshoes = new Image();
            sprintf(str, "Character/lshoes/%d.png", state[v][i]);
            lshoes->initWithImageFile(str);
            memset(str, 0, sizeof(str));
            //...
            Image* rshoes = new Image();
            sprintf(str, "Character/rshoes/%d.png", state[v][i]);
            rshoes->initWithImageFile(str);
            memset(str, 0, sizeof(str));
            //...
            Image* hair = new Image();
            sprintf(str, "Character/hair/%d.png", state[v][i]);
            hair->initWithImageFile(str);
            memset(str, 0, sizeof(str));
            //...
            Image* lpants = new Image();
            sprintf(str, "Character/lpants/%d.png", state[v][i]);
            lpants->initWithImageFile(str);
            memset(str, 0, sizeof(str));
            //...
            Image* rpants = new Image();
            sprintf(str, "Character/rpants/%d.png", state[v][i]);
            rpants->initWithImageFile(str);
            memset(str, 0, sizeof(str));
            //...
            Image* coat = new Image();
            sprintf(str, "Character/coat/%d.png", state[v][i]);
            coat->initWithImageFile(str);
            memset(str, 0, sizeof(str));
            //...
            Image* weapon = new Image();
            sprintf(str, "Character/weapon/1000/%d.png", state[v][i]);
            weapon->initWithImageFile(str);
            memset(str, 0, sizeof(str));
            //...
            Image* weaponh = new Image();
            sprintf(str, "Character/weaponh/1000/%d.png", state[v][i]);
            weaponh->initWithImageFile(str);
            memset(str, 0, sizeof(str));
            //...
            unsigned char *skinData = skin->getData();
            unsigned char *lshoesData = lshoes->getData();
            unsigned char *rshoesData = rshoes->getData();
            unsigned char *hairData = hair->getData();
            unsigned char *lpantsData = lpants->getData();
            unsigned char *rpantsData = rpants->getData();
            unsigned char *coatData = coat->getData();
            unsigned char *weaponData = weapon->getData();
            unsigned char *weaponhData = weaponh->getData();
            int iIndex = 0;
            for(int i = 0; i < skin->getHeight(); ++i) {
                for(int j = 0; j < skin->getWidth(); ++j) {
                	if(i >= 200 && i <= 400) {
                		int iBPos = iIndex;
						unsigned int skinB = skinData[iIndex];
						unsigned int lshoesB = lshoesData[iIndex];
						unsigned int rshoesB = rshoesData[iIndex];
						unsigned int hairB = hairData[iIndex];
						unsigned int lpantsB = lpantsData[iIndex];
						unsigned int rpantsB = rpantsData[iIndex];
						unsigned int coatB = coatData[iIndex];
						unsigned int weaponB = weaponData[iIndex];
						unsigned int weaponhB = weaponhData[iIndex];
                    	iIndex ++;
                    	unsigned int skinG = skinData[iIndex];
                        unsigned int lshoesG = lshoesData[iIndex];
                        unsigned int rshoesG = rshoesData[iIndex];
                        unsigned int hairG = hairData[iIndex];
                        unsigned int lpantsG = lpantsData[iIndex];
                        unsigned int rpantsG = rpantsData[iIndex];
                        unsigned int coatG = coatData[iIndex];
                        unsigned int weaponG = weaponData[iIndex];
                        unsigned int weaponhG = weaponhData[iIndex];
                        iIndex ++;
                        unsigned int skinR = skinData[iIndex];
                        unsigned int lshoesR = lshoesData[iIndex];
                        unsigned int rshoesR = rshoesData[iIndex];
                        unsigned int hairR = hairData[iIndex];
                        unsigned int lpantsR = lpantsData[iIndex];
                        unsigned int rpantsR = rpantsData[iIndex];
                        unsigned int coatR = coatData[iIndex];
                        unsigned int weaponR = weaponData[iIndex];
                        unsigned int weaponhR = weaponhData[iIndex];
                        iIndex ++;
                        unsigned int skinA = skinData[iIndex];
                        unsigned int lshoesA = lshoesData[iIndex];
                        unsigned int rshoesA = rshoesData[iIndex];
                        unsigned int hairA = hairData[iIndex];
                        unsigned int lpantsA = lpantsData[iIndex];
                        unsigned int rpantsA = rpantsData[iIndex];
                        unsigned int coatA = coatData[iIndex];
                        unsigned int weaponA = weaponData[iIndex];
                        unsigned int weaponhA = weaponhData[iIndex];
                        iIndex ++;
                        //...
                        skinB = lshoesB*(lshoesA/255.f) + ((255.f-lshoesA)/255.f)*skinB;
                        skinG = lshoesG*(lshoesA/255.f) + ((255.f-lshoesA)/255.f)*skinG;
                        skinR = lshoesR*(lshoesA/255.f) + ((255.f-lshoesA)/255.f)*skinR;
                        skinA =((lshoesA/255.f)*(lshoesA/255.f)+((255.f-lshoesA)/255.f)*(skinA/255.f))*255.f;
                        //...
                        skinB = rshoesB*(rshoesA/255.f) + ((255.f-rshoesA)/255.f)*skinB;
                        skinG = rshoesG*(rshoesA/255.f) + ((255.f-rshoesA)/255.f)*skinG;
                        skinR = rshoesR*(rshoesA/255.f) + ((255.f-rshoesA)/255.f)*skinR;
                        skinA =((rshoesA/255.f)*(rshoesA/255.f)+((255.f-rshoesA)/255.f)*(skinA/255.f))*255.f;
                        //...
                        skinB = hairB*(hairA/255.f) + ((255.f-hairA)/255.f)*skinB;
                        skinG = hairG*(hairA/255.f) + ((255.f-hairA)/255.f)*skinG;
                        skinR = hairR*(hairA/255.f) + ((255.f-hairA)/255.f)*skinR;
                        skinA =((hairA/255.f)*(hairA/255.f)+((255.f-hairA)/255.f)*(skinA/255.f))*255.f;
                        //...
                        skinB = lpantsB*(lpantsA/255.f) + ((255.f-lpantsA)/255.f)*skinB;
                        skinG = lpantsG*(lpantsA/255.f) + ((255.f-lpantsA)/255.f)*skinG;
                        skinR = lpantsR*(lpantsA/255.f) + ((255.f-lpantsA)/255.f)*skinR;
                        skinA =((lpantsA/255.f)*(lpantsA/255.f)+((255.f-lpantsA)/255.f)*(skinA/255.f))*255.f;
                        //...
                        skinB = rpantsB*(rpantsA/255.f) + ((255.f-rpantsA)/255.f)*skinB;
                        skinG = rpantsG*(rpantsA/255.f) + ((255.f-rpantsA)/255.f)*skinG;
                        skinR = rpantsR*(rpantsA/255.f) + ((255.f-rpantsA)/255.f)*skinR;
                        skinA =((rpantsA/255.f)*(rpantsA/255.f)+((255.f-rpantsA)/255.f)*(skinA/255.f))*255.f;
                        //...
                        skinB = coatB*(coatA/255.f) + ((255.f-coatA)/255.f)*skinB;
                        skinG = coatG*(coatA/255.f) + ((255.f-coatA)/255.f)*skinG;
                        skinR = coatR*(coatA/255.f) + ((255.f-coatA)/255.f)*skinR;
                        skinA =((coatA/255.f)*(coatA/255.f)+((255.f-coatA)/255.f)*(skinA/255.f))*255.f;
                        //...
                        skinB = weaponB*(weaponA/255.f) + ((255.f-weaponA)/255.f)*skinB;
                        skinG = weaponG*(weaponA/255.f) + ((255.f-weaponA)/255.f)*skinG;
                        skinR = weaponR*(weaponA/255.f) + ((255.f-weaponA)/255.f)*skinR;
                        skinA =((weaponA/255.f)*(weaponA/255.f)+((255.f-weaponA)/255.f)*(skinA/255.f))*255.f;
                        //...
                        skinB = weaponhB*(weaponhA/255.f) + ((255.f-weaponhA)/255.f)*skinB;
                        skinG = weaponhG*(weaponhA/255.f) + ((255.f-weaponhA)/255.f)*skinG;
                        skinR = weaponhR*(weaponhA/255.f) + ((255.f-weaponhA)/255.f)*skinR;
                        skinA =((weaponhA/255.f)*(weaponhA/255.f)+((255.f-weaponhA)/255.f)*(skinA/255.f))*255.f;
                        //...
                        skinData[iBPos] = (unsigned char)skinB;
                        skinData[iBPos + 1] = (unsigned char)skinG;
                        skinData[iBPos + 2] = (unsigned char)skinR;
                        skinData[iBPos + 3] = (unsigned char)skinA;
                	}
                	else {
                		iIndex += 3;
                	}
                }
            }

            //...
            char keystr[100];
            sprintf(keystr, "Susake%d-%d", v, i);
            Texture2D *texture = new Texture2D;
            texture = TextureCache::sharedTextureCache()->addUIImage(skin, keystr);
            memset(keystr, 0, sizeof(keystr));
            float w = texture->getContentSize().width;
            float h = texture->getContentSize().height;
            if(v == 0)
                stand->addSpriteFrameWithTexture(texture, CCRectMake(0, 0, w, h));
            else if(v == 1)
                walk->addSpriteFrameWithTexture(texture, CCRectMake(0, 0, w, h));
            else if(v == 2)
            	atk1->addSpriteFrameWithTexture(texture, CCRectMake(0, 0, w, h));
            else if(v == 3)
            	atk2->addSpriteFrameWithTexture(texture, CCRectMake(0, 0, w, h));
            else if(v == 4)
            	atk3->addSpriteFrameWithTexture(texture, CCRectMake(0, 0, w, h));
            else if(v == 5)
            	jump->addSpriteFrameWithTexture(texture, CCRectMake(0, 0, w, h));
            else if(v == 6)
            	jumpatk->addSpriteFrameWithTexture(texture, CCRectMake(0, 0, w, h));

            //别跟我说那些没用的，我只知道数据释放了没有...
            memset(skinData, 0, sizeof(skinData));
            memset(lshoesData, 0, sizeof(lshoesData));
            memset(rshoesData, 0, sizeof(rshoesData));
            memset(hairData, 0, sizeof(hairData));
            memset(lpantsData, 0, sizeof(lpantsData));
            memset(rpantsData, 0, sizeof(rpantsData));
            memset(coatData, 0, sizeof(coatData));
            memset(weaponData, 0, sizeof(weaponData));
            memset(weaponhData, 0, sizeof(weaponhData));
            skin->release();
            lshoes->release();
            rshoes->release();
            hair->release();
            lpants->release();
            rpants->release();
            coat->release();
            weapon->release();
            weaponh->release();
            texture->release();
        }
        if(v == 0) {
            stand->setDelayPerUnit(1.0f / state_num[v]);
            stand->setRestoreOriginalFrame(true);
        }
        else if(v == 1) {
            walk->setDelayPerUnit(1.0f / state_num[v]);
            walk->setRestoreOriginalFrame(true);
        }
        else if(v == 2) {
        	atk1->setDelayPerUnit(1.0f / state_num[v]);
        	atk1->setRestoreOriginalFrame(true);
        }
        else if(v == 3) {
        	atk2->setDelayPerUnit(1.0f / state_num[v]);
        	atk2->setRestoreOriginalFrame(true);
        }
        else if(v == 4) {
        	atk3->setDelayPerUnit(1.0f / state_num[v]);
        	atk3->setRestoreOriginalFrame(true);
        }
        else if(v == 5) {
        	jump->setDelayPerUnit(1.0f / state_num[v]);
        	jump->setRestoreOriginalFrame(true);
        }
        else if(v == 6) {
        	jumpatk->setDelayPerUnit(1.0f / state_num[v]);
        	jumpatk->setRestoreOriginalFrame(true);
        }
    }
    //(站立)默认
    ani->runAction(RepeatForever::create(Animate::create(stand)));
    stand->retain();
    walk->retain();
    atk1->retain();
    atk2->retain();
    atk3->retain();
    jump->retain();
    jumpatk->retain();
}

void PaperDolls::playPaperDolls(int state) {
	if(state == STAND) {
		if(m_state != STAND) {
			m_state = STAND;
			ani->stopAllActions();
			ani->runAction(RepeatForever::create(Animate::create(stand)));
		}
	}
	else if(state == WALK) {
		if(m_state != WALK) {
			m_state = WALK;
			ani->stopAllActions();
			ani->runAction(RepeatForever::create(Animate::create(walk)));
		}
	}
	else if(state == JUMP) {
			if(m_state != JUMP) {
				m_state = JUMP;
				ani->stopAllActions();
				ani->runAction(RepeatForever::create(Animate::create(jump)));
			}
		}
	else if(state == ATTACK1) {
			if(m_state != ATTACK1) {
				m_state = ATTACK1;
				ani->stopAllActions();
				ani->runAction(RepeatForever::create(Animate::create(atk1)));
			}
		}
	else if(state == ATTACK2) {
			if(m_state != ATTACK2) {
				m_state = ATTACK2;
				ani->stopAllActions();
				ani->runAction(RepeatForever::create(Animate::create(atk2)));
			}
		}
	else if(state == ATTACK3) {
			if(m_state != ATTACK3) {
				m_state = ATTACK3;
				ani->stopAllActions();
				ani->runAction(RepeatForever::create(Animate::create(atk3)));
			}
		}
	else if(state == JUMPATTACK) {
				if(m_state != JUMPATTACK) {
					m_state = JUMPATTACK;
					ani->stopAllActions();
					ani->runAction(RepeatForever::create(Animate::create(jumpatk)));
				}
			}
}

void PaperDolls::movePaperDolls(int change_x, int change_y) {
	if(ani) {
		x += change_x; y += change_y;
		ani->setPosition(ccp(x, y));
	}
}

void PaperDolls::directionPaperDolls(int direction) {

	if(ani) {
		if(direction == PARPERDOLLS_LEFT && m_direction != PARPERDOLLS_LEFT) {
			m_direction = PARPERDOLLS_LEFT;
			ani->setFlipX(true);
			x -= 20;
			ani->setPosition(ccp(x, y));
		}
		else if(direction == PARPERDOLLS_RIGHT && m_direction != PARPERDOLLS_RIGHT) {
			m_direction = PARPERDOLLS_RIGHT;
			ani->setFlipX(false);
			x += 20;
			ani->setPosition(ccp(x, y));
		}
	}
}

void PaperDolls::changePaperDolls(int part, int id) {
	//if(ani)
		//ani->setFlipX(true);
}

PaperDolls::~PaperDolls() {
	//...
}
