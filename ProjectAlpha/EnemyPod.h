#pragma once

#include "EnemyActor.h"
#include <string.h>

class EnemyPod : protected EnemyActor
{
public:
	EnemyPod();

	EnemyPod(int id, int *set, int size);
	int *set_id = new int[3];			//Stores the ids of the enemy actors that will be part of the pod

	~EnemyPod();

	int set_size;						//Size of the set of enemies in the pod. Manually input this

private:
	int pod_id;			//Stores the id of what the pod configuration will be
};

