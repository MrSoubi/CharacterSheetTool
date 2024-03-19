#pragma once

class CharacterSheet
{
private:
	std::string name;
	std::string background;
	std::string imagePath;
	int attack;
	int defense;
	int luck;
	int gold;

public:
	int GetRandomFromDice(int diceNumber, int modifier);
	void Randomize();
	void SetImagePath(std::string path);
	void SetName(std::string name);
	void SetBackground(std::string background);
};

