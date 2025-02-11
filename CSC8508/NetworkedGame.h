#pragma once
#include "TutorialGame.h"
#include "NetworkBase.h"
#include "NetworkObject.h"
#include "EventListener.h"


namespace NCL {
	namespace CSC8508 {
		class GameServer;
		class GameClient;
		class NetworkPlayer;
		enum Prefab { Player, EnemyA };

		class NetworkedGame : 
			public TutorialGame,
			public PacketReceiver, 
			public EventListener<NetworkEvent>, 
			public EventListener<ClientConnectedEvent> {
		public:
			NetworkedGame();
			~NetworkedGame();

			void StartAsServer();
			void StartAsClient(char a, char b, char c, char d);

			void UpdateGame(float dt) override;

			void SpawnPlayerClient(int ownerId, int objectId, Prefab prefab);
			void SpawnPlayerServer(int ownerId, Prefab prefab);


			void StartLevel();
			void ReceivePacket(int type, GamePacket* payload, int source) override;

			void OnEvent(ClientConnectedEvent* e) override;
			void OnEvent(NetworkEvent* e) override;

			void OnPlayerCollision(NetworkPlayer* a, NetworkPlayer* b);

		protected:
			void UpdateAsServer(float dt);
			void UpdateAsClient(float dt);

			void StartClientCallBack();
			void StartServerCallBack();

			void StartOfflineCallBack();

			void SendSpawnPacketsOnClientConnect(int clientId);
			void BroadcastSnapshot(bool deltaFrame);
			void BroadcastOwnedObjects(bool deltaFrame);
			void UpdateMinimumState();
			//std::map<int, int> stateIDs;

			GameServer* thisServer;
			GameClient* thisClient;
			float timeToNextPacket;
			int packetsToSnapshot;

			int nextObjectId;

			vector<GameObject*> ownedObjects;

			GameObject* GetPlayerPrefab(NetworkSpawnData* spawnPacket = nullptr);
			std::vector<int> playerStates;


		};
	}
}

