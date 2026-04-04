# Known Bugs

## Parser (`sauce/strange/comprehension/strange__comprehension__parser.h`)

### 1. ~~Buffer underflow in `substr` (lines 618, 787)~~ FIXED

```cpp
oper.result() = oper.result().substr(0, oper.result().length() - oper.name().length());
```

If `oper.name().length()` exceeds `oper.result().length()`, subtracting unsigned `size_t` values wraps around, producing a massive length and causing undefined behavior. The same pattern appears at line 787 with `param.type()`.

### 2. ~~Contradictory error-checking logic (lines 1069-1084)~~ NOT A BUG

```cpp
if (angle < 0 || curly < 0 || round < 0 || square < 0)
{
    if (angle > 0) { err = "parse_argument() mismatched '<'"; }
    // ...
}
```

The outer condition requires `angle < 0` (or another counter < 0), but the inner condition checks `angle > 0`. These are mutually exclusive, so the error message for mismatched `<` is unreachable.

### 3. ~~Out-of-bounds access (line 268)~~ FIXED

```cpp
if (text[text.size() - 2] == '.')
```

No check that `text.size() >= 2` before accessing `text[text.size() - 2]`.

## Tokenizer (`sauce/strange/comprehension/strange__comprehension__toker.h`)

### 4. ~~Missing `continue` after escape detection (line 213)~~ NOT A BUG

When a backslash is encountered inside a quoted string, `escape` is set to `true` but execution falls through to subsequent conditions instead of continuing to the next iteration. This can cause the backslash or the following character to be misclassified.

## Transformation (`sauce/strange/meta/strange__transformation.h`)

### 5. ~~Off-by-one in namespace closing (line 955)~~ FIXED

```cpp
while (--depth)
{
    _out << "}\n";
}
```

Pre-decrement means the loop runs `depth - 1` times. If 3 namespaces were opened, only 2 closing braces are emitted, producing malformed C++ output.

### 6. ~~Unsafe `substr` without length check (line 1037)~~ FIXED

```cpp
operation.result().substr(0, operation.result().length() - 7)
```

If the result string is shorter than 7 characters, unsigned underflow causes undefined behavior.

### 7. Possible logic error with `||` vs `&&` (line 1293)

```cpp
if ((operation.modification().empty() && !inner) || operation.customisation().empty())
```

The `||` causes this condition to fire whenever `customisation` is empty, regardless of the `modification`/`inner` check. This may not be intentional.

## Code Generator Tool (`sauce/generation/strange__generation.cpp`)

### 8. Asterisk flag not reset on consecutive `*`

When processing `/*~ ... */` content, if a `*` is encountered the `asterisk` flag is set. If the next character is also `*`, the flag remains set and a single `*` is output. Sequences like `**` within tilde blocks could cause the `*/` terminator to be missed or misinterpreted.

### 9. Missing `slash` flag reset on false-positive delimiters

When the state machine detects `/*` or `//` but the next character is not `~`, it transitions back to normal mode without explicitly resetting the `slash` flag, leaving the state machine in a potentially inconsistent state.

## Common (`sauce/strange/common/strange__common.h`)

### 10. Race condition in `_mutate()` (line 191)

```cpp
if (_shared.use_count() > 1)
{
    _shared = _shared->_clone();
}
```

The check-then-act pattern is not thread-safe. Between checking `use_count()` and calling `_clone()`, another thread could change the reference count.

### 11. `_error()` silently destroys object state (line 267)

Calling `_error("msg")` unconditionally replaces `_shared` with a `_message` object, permanently losing the wrapped concrete object.

## Concurrency (`sauce/strange/implementation/graph/strange__implementation__graph.h`)

### 12. Race condition on `_outputs` promise (lines 193-200)

`operator()` creates a new promise on `_outputs` while another thread could still be waiting on the previous future via `future.get()`.

### 13. Uninitialized `_ins` and `_outs` in `thru_processor` (line 309)

Member variables are declared but never initialized in the constructor. If `closure()` uses them before they are set via the mutable getters, behavior is undefined.
