#include "stdafx.h"
#include "EnemyPod.h"


EnemyPod::EnemyPod()
{
}

EnemyPod::EnemyPod(int id, int *set, int size, int gold_given, int exp_given)
{
	pod_id = id;
	set_id = set;
	set_size = size;
	gold = gold_given;
	experience = exp_given;
}


EnemyPod::~EnemyPod()
{
}
