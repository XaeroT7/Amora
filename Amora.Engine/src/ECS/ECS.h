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
struct Component: public BaseComponent {
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
};

template<typename TComponent>
void System::require_component() {
	const int component_id = Component<TComponent>::get_id();
	component_signature.set(component_id, 1);
}

struct Registry {
	// TODO: ...
};

#endif
