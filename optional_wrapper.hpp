#ifndef TINY_PROCESS_LIBRARY_OPTIONAL_WRAPPER_HPP_
#define TINY_PROCESS_LIBRARY_OPTIONAL_WRAPPER_HPP_

#include <utility>

namespace TinyProcessLib {

/// Small utility class for environment options, avoiding C++17 requirement or boost::optional and avoiding pointers.
template <typename T>
class OptionalWrapper
{
public:
  explicit OptionalWrapper(T obj) noexcept(noexcept(T{}))
    : object{std::move(obj)}
    , is_set{true}
  {}

  OptionalWrapper() noexcept(noexcept(T{}))
    : object{}
    , is_set{false}
  {}

  void reset()
  {
    object = {};
    is_set = false;
  }

  T const& get() const noexcept
  {
    return object;
  }

  T& get() noexcept
  {
    return object;
  }

  explicit operator bool() const noexcept
  {
    return is_set;
  }
private:
  T object;
  bool is_set;
};

}

#endif
