# [Docs] Bit Logical Operation Grammar

This is the design of `Bit Logical Operation`, the reference is PPP2/Chapter6/Exercise7

Bit Logical Operation has 5 operands: `!, ~, &, |, and ^`.

The primary of these operands is: `& > ^ > |`, and `!, ~` operands are `unary operator`.

```
Expression:
    Term
    Expression "|" Term
Term:
    Primary
    Term "^" Primary
Primary:
    Sub-primary
    Primary "&" Sub-primary
Sub-primary:
    Number
    "(" Expression ")"
    "{" Expression "}"
    "!" Sub-primary
    "~" Sub-primary
Number:
    integer-number-literal
```