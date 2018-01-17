#include "stdafx.h"
#include "EnemyPod.h"


EnemyPod::EnemyPod()
{
}

EnemyPod::EnemyPod(int id, int *set, int size)
{
	pod_id = id;
	set_id = set;
	set_size = size;
}


EnemyPod::~EnemyPod()
{
}
