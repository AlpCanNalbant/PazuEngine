namespace Pazu
{
	template <typename T>
	requires std::convertible_to<T, Bone>
	bool Skeleton::AddBone(T &&bone)
	{
		if (FindBone(bone.GetName()))
		{
			bones_.emplace_back(std::forward<T>(bone));

			return true;
		}

		return false;
	}
}
