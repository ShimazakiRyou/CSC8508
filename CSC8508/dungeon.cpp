#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

struct Room {
    int id;
    std::string type;
    std::vector<int> connections;
    int x, y;
};

class MapGenerator {
public:
    std::vector<Room> rooms;

    void GenerateMap(int roomCount) {
        srand(time(0));

        for (int i = 0; i < roomCount; i++) {
            Room newRoom;
            newRoom.id = i;
            newRoom.type = GetRandomRoomType();
            newRoom.x = (i % 5) * 10;  // make 5 rooms per row
            newRoom.y = (i / 5) * 10;
            rooms.push_back(newRoom);
        }

        ConnectRooms();  // ensure all rooms are connected
    }

    void PrintMap() {
        for (const auto& room : rooms) {
            std::cout << "Room ID: " << room.id << " Type: " << room.type
                << " Position: (" << room.x << "," << room.y << ") Connected to: ";
            for (int conn : room.connections) {
                std::cout << conn << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::string GetRandomRoomType() {
        std::vector<std::string> roomTypes = { "hallway", "storage", "office", "control" };
        return roomTypes[rand() % roomTypes.size()];
    }

    void ConnectRooms() {
        for (size_t i = 0; i < rooms.size(); i++) {
            if (i < rooms.size() - 1) {
                rooms[i].connections.push_back(rooms[i + 1].id);
                rooms[i + 1].connections.push_back(rooms[i].id);
            }
        }
    }
};

/*int main() {
    MapGenerator generator;
    generator.GenerateMap(10);  // creat 10 rooms
    generator.PrintMap();
    return 0;
}*/
