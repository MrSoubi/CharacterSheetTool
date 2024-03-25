#include "pch.h"
#include "CharacterSheet.h"

CharacterSheet::CharacterSheet()
{
    std::srand(std::time(nullptr));
}

int CharacterSheet::GetRandomFromDice(int diceNumber, int modifier)
{
    int result = 0;

    while (diceNumber != 0) {
        result += 1 + std::rand() % 6;
        diceNumber--;
    }

    return (result + modifier);
}

void CharacterSheet::RandomizeAll()
{
    RandomizeAttack();
    RandomizeDefense();
    RandomizeLuck();
    RandomizeGold();
}

void CharacterSheet::RandomizeAttack()
{
    attack = GetRandomFromDice(2, 5);
}

void CharacterSheet::RandomizeDefense()
{
    defense = GetRandomFromDice(2, 5);
}

void CharacterSheet::RandomizeLuck()
{
    luck = GetRandomFromDice(1, 5);
}

void CharacterSheet::RandomizeGold()
{
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

int CharacterSheet::GetAttack()
{
    return attack;
}

int CharacterSheet::GetDefense()
{
    return defense;
}
int CharacterSheet::GetLuck()
{
    return luck;
}
int CharacterSheet::GetGold()
{
    return gold;
}

std::string CharacterSheet::GetName()
{
    return name;
}
