# Stack/Queue – Problem 8: Valid Parentheses

## Problem

Given a string containing `()`, `{}`, and `[]`, determine whether the brackets are valid.

A string is valid when:
1. Every opening bracket has a matching closing bracket.
2. Brackets close in the correct order.
3. No unmatched brackets remain.

## Approach: Using Stack

**Why Stack?**

A stack follows LIFO (Last In, First Out).

The most recently opened bracket must be the first one to close.

### Algorithm

1. Create an empty `stack<char>`.
2. Traverse the string character by character.
3. If the character is an opening bracket (`(`, `{`, `[`), push it onto the stack.
4. If it is a closing bracket:
   - Check whether the stack is empty. If yes, return `false`.
   - Get the top element.
   - Check whether the opening and closing brackets match.
   - If they match, pop the opening bracket.
   - Otherwise, return `false`.
5. After traversing the entire string, return `st.empty()`.

## C++ Solution

```cpp
bool isValid(string s)
{
    stack<char> st;

    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
                return false;

            char top = st.top();

            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '['))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return st.empty();
}
```

## Dry Run

Input: `"{[]}"`

| Character | Operation | Stack |
|---|---|---|
| `{` | Push | `{` |
| `[` | Push | `{ [` |
| `]` | Match and pop | `{` |
| `}` | Match and pop | Empty |

Final stack is empty, so the answer is `true`.

## Important Edge Cases

| Input | Output | Reason |
|---|---|---|
| `()` | true | Valid pair |
| `([{}])` | true | Correct nesting |
| `(]` | false | Mismatched brackets |
| `((()` | false | Unmatched opening brackets |
| `())` | false | Extra closing bracket |
| Empty string | true | No unmatched brackets |

## Complexity Analysis

- **Time Complexity:** O(N) — each character is processed once.
- **Space Complexity:** O(N) — in the worst case, all characters are opening brackets.

## Key Takeaway

A stack is useful whenever we need to process elements in reverse order of insertion.

For valid parentheses, the most recently opened bracket must be closed first.