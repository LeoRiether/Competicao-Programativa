// https://florianjw.de/en/passing_overloaded_functions.html
#define RESOLVE(...) \
	[](auto&&...args)->decltype(auto){return __VA_ARGS__(std::forward<decltype(args)>(args)...);}