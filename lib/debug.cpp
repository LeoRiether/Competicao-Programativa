#ifdef DEBUG
#define debug(...) __VA_ARGS__
#define judge(...)
#else
#define endl '\n'
#define debug(...)
#define judge(...) __VA_ARGS__
#endif
#define debugf(...) debug(printf(__VA_ARGS__))
