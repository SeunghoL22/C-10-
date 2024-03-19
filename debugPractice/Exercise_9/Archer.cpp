#include "Archer.h"
#include "Pet.h"

Archer::Archer(Pet* pet) : _pet(pet)
{
	
}

Archer::Archer(int hp) : Player(hp)
{
}

Archer::~Archer()
{
	// 즐거웠다 내 펫 :(
	if (_pet != nullptr)
		delete _pet;
}

void Archer::AddHp(int value)
{
	Player::AddHp(value);

	// 죽었으면 펫도 날린다
	if (IsDead())
	{
		delete _pet;
		_pet = nullptr;
		//정답 이중 delete을 예방하려면 소멸자가 아닌 곳에서 delete했을땐 nullptr로 밀어줘라.
	}
}
