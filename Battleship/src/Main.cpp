#include <iostream>

enum class ShipType {
	None,
	AircraftCarrier,
	Battleship,
	Cruiser,
	Destroyer,
	Submarine
};

enum class ShipOrientation {
	Horizontal,
	Vertical
};

struct ShipPosition {
	int row;
	int col;
};

struct Ship {
	ShipType type = ShipType::None;
	ShipOrientation orientation;
	ShipPosition pos;
	int size;
};

enum class GuessType {
	None,
	Miss,
	Hit
};

int main() {
	return 0;
}
