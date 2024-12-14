#ifndef ECS_H 
#define ECS_H 

#include <vector>
#include <bitset>

const unsigned int MAX_COMPONENTS = 32;

typedef std::bitset<MAX_COMPONENTS> Signature;

struct BaseComponent {
	static int next_id;
};

template <typename T>
struct Component : public BaseComponent {
	static int get_id() {
		static int id = next_id++;
		return id;
	}
};

struct Entity {
	Entity(int id);

	int id;
};

struct System {
	System();
	~System();

	Signature component_signature;
	std::vector<Entity> entities;

	template<typename TComponent>
	void require_component();
	void remove_entity(Entity entity);
};

struct Registry {
	// TODO: ...
};

#endif
