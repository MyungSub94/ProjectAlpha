#pragma once

#include "EnemyActor.h"

class EnemyPod : protected EnemyActor
{
public:
	EnemyPod();

	EnemyPod(int id, int *set);

	~EnemyPod();

	int size;
private:
	int pod_id;			//Stores the id of what the pod configuration will be
	int *set_id = new int[3];			//Stores the ids of the enemy actors that will be part of the pod
};

