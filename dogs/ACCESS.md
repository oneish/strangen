# Access Levels

> *"Every module ... is characterized by its knowledge of a design decision which it hides from all others. Its interface or definition was chosen to reveal as little as possible about its inner workings."*
> -- David L. Parnas, *On the Criteria To Be Used in Decomposing Systems into Modules* (1972)

A prototype `struct` uses the C++ access labels `public:`, `protected:`, and `private:`
exactly the way C++ does. Strangen records the label that applies to each operation as a
`strange::access` value (`_public_`, `_protected_`, `_private_`; defined in
`sauce/strange/strange.h`) and uses it to decide **what code is generated** for that operation.

Access here is a *code-generation directive*, not a runtime value: it selects which of the
generated artifacts an operation appears in.

## The generated artifacts

For every abstraction the transformation engine emits several cooperating pieces (see
`sauce/strange/meta/strange__transformation.h`):

```
handle          the value type users hold; the public, type-erased surface
  |
  v
_derived        the pure-virtual concept every model must satisfy
  |
  v
_instance       the model: forwards each call to the wrapped _thing
  |
  v
implementation  the concrete struct that actually holds data and logic
```

The first three make up the **type-erased interface**. The last is the **implementation**.

## The three levels

| Access | Type-erased interface? | Implementation generated? |
|--------|------------------------|---------------------------|
| `public` | yes -- callable through the handle | yes; also regenerated into inheriting abstractions |
| `protected` | no | yes; **also** regenerated into inheriting abstractions |
| `private` | no | yes, but **only** in the defining abstraction -- not inheriting ones |

- **public** -- part of the public surface. The operation appears in the handle, the
  pure-virtual concept, and the instance model, and is dispatched polymorphically.
- **protected** -- no type-erased interface. The operation exists only as a concrete
  method/member on the implementation struct. Because implementations are flat (see
  [Inheritance is regeneration](#inheritance-is-regeneration)), a protected operation is
  *regenerated* into every inheriting abstraction's implementation.
- **private** -- like protected, but *not* regenerated for inheriting abstractions; it stays
  only in the implementation of the abstraction that declares it.

Two decisions in `_abstraction_operations` implement this:

- The **implementation passes** emit the concrete member/method for public, protected, and
  private operations -- except a private operation is skipped for an inheriting abstraction
  (`operation.access() == _private_ && abstraction.name() != derived.name()`), and any
  operation with an empty body is skipped (there is nothing to emit).
- The **interface passes** (`else if (operation.access() != _public_) continue;`) emit only
  public operations, so protected and private never reach the handle, concept, or model.

## Writing access in a prototype

Use ordinary C++ access labels. Every operation declared after a label takes that access
until the next label; the default (as in a C++ `struct`) is `public`.

```cpp
namespace demo
{
    struct [[strange::implementation("demo::widget_impl")]]
    widget : strange::any
    {
    public:
        auto draw() const -> void { /* ... uses the helpers below ... */ }

    protected:
        auto redraw() -> void { /* regenerated into inheriting abstractions */ }

    private:
        auto invalidate() -> void { /* only in widget's own implementation */ }
    };
}
```

`draw` is reachable through the `demo::widget` handle; `redraw` and `invalidate` are not --
they are implementation detail. (Protected/private operations need a body and an enclosing
`[[strange::implementation(...)]]` to be emitted, since they exist only in the implementation.)

## Data members and accessors

A data field in a prototype is written as a plain member with an initializer, for example
from the `operation` prototype in `sauce/strange/meta/strange__space_prototype.h`:

```cpp
std::string name {};
strange::access access {strange::access::_public_};
```

Each such field generates a public data member (`name_`, `access_`) alongside a matching pair
of `const`/mutable accessors:

```cpp
// generated implementation struct (shape)
struct operation
{
    std::string name_ {};
    inline auto name() const -> std::string const & { return name_; };
    inline auto name() -> std::string & { return name_; };
    strange::access access_ {strange::access::_public_};
    inline auto access() const -> strange::access const & { return access_; };
    inline auto access() -> strange::access & { return access_; };
    inline auto pack(strange::bag & dest) const -> void { /* ... */ }
    inline auto unpack(strange::bag const & src) -> void { /* ... */ }
};
```

Most code reaches a field through its accessor -- the instance model forwards via
`_thing.name()`, and the generated equality/hash/comparison and `pack`/`unpack` go through
`name()`. Because the members are public and the struct is an aggregate, an implementation can
also be built directly with a **designated initializer** that names the generated members -- an
idiom used, for example, by the tokenizer and the graph code:

```cpp
strange::token::_make(strange::implementation::token{
    .filename_ = _filename, .line_ = _start_line, .position_ = _start_position,
    .classification_ = classification, .text_ = text});
```

Keeping the data members public is what allows this aggregate / designated-initializer
construction.

## Inheritance is regeneration

Generated implementation structs are **flat** -- `_abstraction_implementation` emits
`struct <name> { ... };` with no base list. An abstraction that inherits another does not
inherit its implementation in the C++ sense; instead the parent's operations are *regenerated*
into the child's implementation struct. This is why the protected-vs-private distinction is
expressed as "regenerated for inheriting abstractions" (protected) versus "not regenerated"
(private) rather than through C++ `protected`/`private` on a base class.

## Where this lives in the code

| Concept | Location |
|---------|----------|
| `access` enum | `sauce/strange/strange.h` |
| Parsing `public:`/`protected:`/`private:` labels | `strange__comprehension__parser.h`, `parse_abstraction()` |
| Interface vs implementation passes; access filters | `strange__transformation.h`, `_abstraction_operations()` |
| Flat implementation struct + trailing `private:` members | `strange__transformation.h`, `_abstraction_implementation()` |

See also [SERPENT.md](SERPENT.md) for how to stage code-generator changes through the
self-hosting bootstrap.
