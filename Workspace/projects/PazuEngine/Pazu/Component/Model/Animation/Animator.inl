namespace Pazu
{
	template <typename T>
	requires std::convertible_to<T, Animation>
	bool Animator::AddAnimation(T &&animation)
	{
		if (animation && !FindAnimation(animation->GetName()))
		{
			animations_.emplace_back(std::forward<T>(animation));

			return true;
		}

		return false;
	}
}
