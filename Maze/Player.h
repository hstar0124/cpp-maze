#pragma once
#include "Vector.h"

class Board;

class Player
{
	enum
	{
		MOVE_TICK = 200
	};

public:

	void Init(Board* board);
	void Update(uint64 deltaTick);

	void SetPos(Pos pos) { _pos = pos; }
	Pos GetPos() { return _pos; }

	bool CanGo(Pos pos);

private:
	void CalculatePathRightHand();
	void CalculatePathBFS();

private:
	Pos				_pos;
	int32			_dir = DIR_UP;
	Board*			_board = nullptr;

	vector<Pos>		_path;
	int32			_pathIndex;
	uint64			_sumTick = 0;
};

