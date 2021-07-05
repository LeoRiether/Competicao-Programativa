template <typename T> class rev {
  private:
    T &iterable_;

  public:
    explicit rev(T &iterable) : iterable_{iterable} {}
    auto begin() const { return std::rbegin(iterable_); }
    auto end() const { return std::rend(iterable_); }
};