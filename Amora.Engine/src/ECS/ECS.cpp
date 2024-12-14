#include "ECS.h"

Entity::Entity(int id): id(id) {
}

bool Entity::operator==(const Entity& other) const {
	return other.id == id;
}

System::System() {
}

System::~System() {
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
