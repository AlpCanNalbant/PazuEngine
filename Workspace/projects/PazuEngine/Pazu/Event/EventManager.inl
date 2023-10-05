// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	void EventManager::Add(const std::shared_ptr<T> &event)
	{
		const auto typeIndex = magic_enum::enum_integer(event->GetType());
		if (m_events[typeIndex] == event || !event)
			return Log::Get().Print<LogMode::Error>("Event eklenemedi.");
		m_events[typeIndex] = event;
		if constexpr (std::is_base_of_v<IUpdatableEvent, T>)
			m_updatableEvents.emplace_back(event);
	}

	template <typename T>
	void EventManager::Remove(const std::shared_ptr<T> &event)
	{
		const auto typeIndex = magic_enum::enum_integer(event->GetType());
		if (m_events[typeIndex] != event)
			return Log::Get().Print<LogMode::Error>("Event silinemedi.");
		m_events[typeIndex] = std::make_shared<NoneEvent>();
		if constexpr (std::is_base_of_v<IUpdatableEvent, T>)
			m_updatableEvents.erase(std::find(m_updatableEvents.begin(), m_updatableEvents.end(), event));
	}
} // namespace Pazu
