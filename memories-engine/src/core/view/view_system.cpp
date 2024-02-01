#include "pch.h"
#include "view_system.h"

#include "core/defines.h"
#include "core/logger/assert.h"

namespace mem
{
	size_t ViewSystem::Add(mem_unique<View> view)
	{
		view->onInstantiated();
		view->setHandler(this);

		m_Views.push_back(std::move(view));

		return m_Views.size() - 1;
	}

	void ViewSystem::Remove(size_t index)
	{
		auto it = m_Views.begin() + index;
		it->get()->onRemoved();

		m_Views.erase(it);
	}

	View& ViewSystem::GetView(size_t index)
	{
		MEM_ASSERT(m_Views.size() - 1 <= index, "Invalid view index selected");
		return *m_Views[index].get();
	}
}