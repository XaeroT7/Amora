#ifndef ECS_H 
#define ECS_H 

#include <vector>
#include <bitset>

const unsigned int MAX_COMPONENTS = 32;
typedef std::bitset<MAX_COMPONENTS> Signature;

class Component {
public:
	Component(int id);

	int id;
};

class Entity {
public:
	Entity(int id);

	int id;
};

class System {
public:
	System();
	~System();

	Signature component_signature;
	std::vector<Entity> entities;
};

class Registry {
	// TODO: ...
};

#endif
