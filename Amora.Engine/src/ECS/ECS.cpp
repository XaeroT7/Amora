#include "ECS.h"
#include "../Logger/Logger.h"

bool Entity::operator==(const Entity& other) const {
	return other.id == id;
}

template<typename TComponent>
void System::require_component() {
	const int component_id = Component<TComponent>::get_id();
	component_signature.set(component_id, 1);
}

void System::remove_entity(Entity entity) {
	for (unsigned int i = 0; i < entities.size(); i++) {
		if (entities[i] == entity) {
			entities.erase(entities.begin() + i);
		}
	}
}

Entity Registry::create_entity() {
	int entity_id = num_entities++;
	if (entity_id >= entity_component_signatures.size()) {
		entity_component_signatures.resize(entity_id + 1);
	}
	Entity entity(entity_id);
	entitiesToBeAdded.insert(entity);
	Logger::log("Entity created with id = " + std::to_string(entity_id));

	return entity;
}

void Registry::add_entity_to_system(Entity entity) {
}

template<typename T, typename ...TArgs>
void Registry::add_component(Entity entity, TArgs&& ...) {

}

template<typename T>
void Registry::remove_component(Entity entity) {
}

template<typename T>
bool Registry::has_component(Entity entity) const {
	return false;
}

template<typename T>
T& Registry::get_component(Entity entity) const {
	// TODO: insert return statement here
}

void Registry::update() {
	// TODO: Add entities that are waiting to be created
	// TODO: Remove entities waiting to be destroyed
}

