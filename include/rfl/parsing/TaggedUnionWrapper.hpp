#ifndef RFL_PARSING_TAGGEDUNIONWRAPPER_HPP_
#define RFL_PARSING_TAGGEDUNIONWRAPPER_HPP_

#include <string>

#include "rfl/Flatten.hpp"
#include "rfl/Rename.hpp"
#include "rfl/internal/StringLiteral.hpp"

namespace rfl {
namespace parsing {

template <class T, class TagType, internal::StringLiteral _discriminator>
struct TaggedUnionWrapperNoFields {
  rfl::Rename<_discriminator, TagType> tag;
  rfl::Flatten<const T*> fields;
};

template <class T, class TagType, internal::StringLiteral _discriminator>
struct TaggedUnionWrapperWithFields {
  rfl::Field<_discriminator, TagType> tag;
  rfl::Flatten<const T*> fields;
};

}  // namespace parsing
}  // namespace rfl

#endif
