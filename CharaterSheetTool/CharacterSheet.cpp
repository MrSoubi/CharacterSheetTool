#include "pch.h"
#include "CharacterSheet.h"

int CharacterSheet::GetRandomFromDice(int diceNumber, int modifier)
{
    int result = 0;
    std::srand(std::time(nullptr));

    while (diceNumber != 0) {
        result += 1 + std::rand() % 6;
        diceNumber--;
    }

    return (result + modifier);
}

void CharacterSheet::Randomize()
{
    attack = GetRandomFromDice(2, 5);
    defense = GetRandomFromDice(2, 5);
    luck = GetRandomFromDice(1, 5);
    gold = GetRandomFromDice(3, 10);
}

void CharacterSheet::SetName(std::string name)
{
    this->name = name;
}

void CharacterSheet::SetBackground(std::string background)
{
    this->background = background;
}
