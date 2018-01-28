//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

//#include "enemyBulletManager.h"
//
//EnemyBulletManager::EnemyBulletManager()
//{
//}
//
//bool EnemyBulletManager::initialize(EnemyManager *enemyList, Entity *play)
//{
//	player = play;
//}
//
//void EnemyBulletManager::update(float frameTime)
//{
//	for (hunter = enemyList->begin(); hunter != enemyList->end(); hunter++)
//	{
//		if ((*hunter)->getBullet() && (GetTickCount() - (*hunter)->getTimer() > hunterShipNS::FIRE_RATE) && (*hunter)->getAlive())
//		{
//			(*hunter)->setTimer(GetTickCount());
//			bulletList->push_back(new EnemyBullet());
//			initialize(gamePtr, textureM, *hunter);
//		}
//	}
//
//	for (bullet = bulletList->begin(); bullet != bulletList->end(); bullet++)
//	{
//		(*bullet)->update(frameTime);
//	}
//}
//
//void EnemyBulletManager::collisions()
//{
//	VECTOR2 collisionVector;
//	bullet = bulletList->begin();
//	while (bullet != bulletList->end())
//	{
//		if ((bulletShip)->collidesWith(**bullet, collisionVector))
//		{
//			//(bulletShip)->damage(BULLET);
//			(*bullet)->setVisible(false);
//			(*bullet)->setActive(false);
//		}
//		else if ((laserShip)->collidesWith(**bullet, collisionVector))
//		{
//			//(laserShip)->damage(BULLET);
//			(*bullet)->setVisible(false);
//			(*bullet)->setActive(false);
//		}
//		if (!(*bullet)->getActive())
//			bullet = bulletList->erase(bullet);
//		else
//			bullet++;
//	}
//}
//
//void EnemyBulletManager::render()
//{
//	for (bullet = bulletList->begin(); bullet != bulletList->end(); bullet++)
//	{
//		(*bullet)->draw();
//	}
//}