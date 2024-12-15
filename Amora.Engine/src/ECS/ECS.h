#ifndef ECS_H 
#define ECS_H 

#include <bitset>
#include <vector>
#include <set>
#include <typeindex>
#include <unordered_map>

const unsigned int MAX_COMPONENTS = 32;

typedef std::bitset<MAX_COMPONENTS> Signature;

struct Entity {
	Entity(int id) : id(id) {};

	int id;

	bool operator==(const Entity& other) const;
};


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


//---------------------------------------------------------------
// SYSTEM 
//---------------------------------------------------------------
// Processes entities that contain a specific component signature
//---------------------------------------------------------------
struct System {
	System() = default;
	~System() = default;

	Signature component_signature;
	std::vector<Entity> entities;
	
	void remove_entity(Entity entity);

	template<typename TComponent>
	void require_component();
};


//---------------------------------------------------------------
// REGISTRY
//---------------------------------------------------------------
// Manages the creation and destruction of entities, as well as 
// adding systems and components to entities.
//---------------------------------------------------------------
struct BasePool {
	virtual ~BasePool() = 0 { };
};

template<typename T>
struct Pool : public BasePool {
	std::vector<T> components;

	Pool(int size = 100) {
		components.resize(size);
	}
	~Pool() = default;
};

struct Registry {
	int num_entities;
	std::set<Entity> entitiesToBeAdded;
	std::set<Entity> entitiesToBeDestroyed;

	std::vector<BasePool> component_pools;					// [index = component type id]
	std::vector<Signature> entity_component_signatures;		// [index = entity id]
	std::unordered_map<std::type_index, System*> systems;

	Entity create_entity();

	void update();
	void add_entity_to_system(Entity entity);

	template<typename T, typename ...TArgs> 
	void add_component(Entity entity, TArgs&& ...);

	template<typename T>
	void remove_component(Entity entity);

	template<typename T>
	bool has_component(Entity entity) const;

	template<typename T>
	T& get_component(Entity entity) const;


	// TODO:
	// add_component(Entity entity)
	// get_component(Entity entity)
	// add_system()
};

#endif

