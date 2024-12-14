#include "ECS.h"

Entity::Entity(int id): id(id) {
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
	//entities.erase(std::remove_if(entities.begin(), entities.end(), [&entity](Entity other) {
	//	return entity.id == other.id;
	//	}), entities.end());

	for (unsigned int i = 0; i < entities.size(); i++) {
		if (entities[i].id == entity.id) {
			entities.erase(entities.begin() + i);
		}
	}
}
