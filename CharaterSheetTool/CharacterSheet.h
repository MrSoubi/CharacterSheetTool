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
	CharacterSheet();

	int GetRandomFromDice(int diceNumber, int modifier);
	void RandomizeAll();
	void RandomizeAttack();
	void RandomizeDefense();
	void RandomizeLuck();
	void RandomizeGold();
	void SetImagePath(std::string path);
	void SetName(std::string name);
	void SetBackground(std::string background);
	int GetAttack();
	int GetDefense();
	int GetLuck();
	int GetGold();
	std::string GetName();
};

