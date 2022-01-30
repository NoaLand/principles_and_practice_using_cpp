# [Docs] English Grammar

English grammar in the book:

```
Sentence:
    Noun Verb
    Sentence Conjunction Sentence
Conjunction:
    "and"
    "or"
    "but"
Noun:
    NounDic
    Determiner NounDic
Determiner:
    "the"
NounDic:
    "birds"
    "fish"
    "C++"
Verb:
    "rules"
    "fly"
    "swim"
```

A sentence like "birds fly but fish swim" will be like:

```mermaid
graph BT
    birds --> noun1[Noun] --> sentence1[Sentence]
    fly --> verb1[Verb] --> sentence1 --> whole_sentence[Sentence]
    but ---> conjunction[Conjunction] --> whole_sentence
    fish --> noun2[Noun] --> sentence2[Sentence]
    swim --> verb2[Verb] --> sentence2 --> whole_sentence[Sentence]
```