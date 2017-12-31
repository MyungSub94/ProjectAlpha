#include "stdafx.h"
#include "EnemyPod.h"


EnemyPod::EnemyPod()
{
}

EnemyPod::EnemyPod(int id, int *set)
{
	pod_id = id;
	set_id = set;
	size = sizeof(set_id);
}


EnemyPod::~EnemyPod()
{
}
