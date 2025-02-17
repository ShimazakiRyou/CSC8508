#include "NetworkPlayer.h"
#include "NetworkedGame.h"

using namespace NCL;
using namespace CSC8508;

NetworkPlayer::NetworkPlayer(NetworkedGame* game, int num)	
{
	this->game = game;
	playerNum  = num;
}

NetworkPlayer::~NetworkPlayer()	{

}

void NetworkPlayer::OnCollisionBegin(BoundsComponent* otherObject) {
	if (game) {
		if (dynamic_cast<NetworkPlayer*>(otherObject))
		{
			game->OnPlayerCollision(this, (NetworkPlayer*)otherObject);
		}
	}
}